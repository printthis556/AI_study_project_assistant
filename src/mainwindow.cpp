#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "flashcarddialog.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QFile>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    
    // Connect signals and slots
    connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::onAddFlashcard);
    connect(ui->editButton, &QPushButton::clicked, this, &MainWindow::onEditFlashcard);
    connect(ui->deleteButton, &QPushButton::clicked, this, &MainWindow::onDeleteFlashcard);
    connect(ui->importButton, &QPushButton::clicked, this, &MainWindow::onImportFile);
    connect(ui->saveButton, &QPushButton::clicked, this, &MainWindow::onSaveFlashcards);
    connect(ui->loadButton, &QPushButton::clicked, this, &MainWindow::onLoadFlashcards);
    connect(ui->studyButton, &QPushButton::clicked, this, &MainWindow::onStudyMode);
    connect(ui->flashcardListWidget, &QListWidget::currentRowChanged, 
            this, &MainWindow::onFlashcardSelectionChanged);
    
    // Initialize UI
    ui->editButton->setEnabled(false);
    ui->deleteButton->setEnabled(false);
    ui->studyButton->setEnabled(false);
    ui->questionDisplayLabel->setText("No flashcard selected");
    ui->answerDisplayLabel->setText("");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onAddFlashcard()
{
    FlashcardDialog dialog(this);
    dialog.setWindowTitle("Add New Flashcard");
    
    if (dialog.exec() == QDialog::Accepted) {
        Flashcard newCard = dialog.getFlashcard();
        if (!newCard.getQuestion().isEmpty()) {
            m_flashcardManager.addFlashcard(newCard);
            updateFlashcardList();
            ui->statusbar->showMessage("Flashcard added successfully", 3000);
        }
    }
}

void MainWindow::onEditFlashcard()
{
    int currentRow = ui->flashcardListWidget->currentRow();
    if (currentRow < 0) return;
    
    FlashcardDialog dialog(this);
    dialog.setWindowTitle("Edit Flashcard");
    dialog.setFlashcard(m_flashcardManager.getFlashcard(currentRow));
    
    if (dialog.exec() == QDialog::Accepted) {
        Flashcard editedCard = dialog.getFlashcard();
        m_flashcardManager.updateFlashcard(currentRow, editedCard);
        updateFlashcardList();
        ui->flashcardListWidget->setCurrentRow(currentRow);
        ui->statusbar->showMessage("Flashcard updated successfully", 3000);
    }
}

void MainWindow::onDeleteFlashcard()
{
    int currentRow = ui->flashcardListWidget->currentRow();
    if (currentRow < 0) return;
    
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Delete Flashcard", 
                                  "Are you sure you want to delete this flashcard?",
                                  QMessageBox::Yes | QMessageBox::No);
    
    if (reply == QMessageBox::Yes) {
        m_flashcardManager.removeFlashcard(currentRow);
        updateFlashcardList();
        ui->statusbar->showMessage("Flashcard deleted", 3000);
    }
}

void MainWindow::onImportFile()
{
    QString filename = QFileDialog::getOpenFileName(this, "Import Content", "",
                                                    "Text Files (*.txt);;All Files (*)");
    
    if (filename.isEmpty()) return;
    
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Import Error", 
                           "Could not open file for reading.");
        return;
    }
    
    QTextStream in(&file);
    QString content = in.readAll();
    file.close();
    
    // Simple import: create a flashcard with the filename as question and content preview as answer
    QString preview = content.left(200);
    if (content.length() > 200) {
        preview += "...";
    }
    
    Flashcard importedCard("Imported from: " + QFileInfo(filename).fileName(), preview);
    m_flashcardManager.addFlashcard(importedCard);
    updateFlashcardList();
    
    QMessageBox::information(this, "Import Successful", 
                            "Content imported successfully.\nYou can now edit the flashcard to create questions and answers.");
    ui->statusbar->showMessage("File imported successfully", 3000);
}

void MainWindow::onSaveFlashcards()
{
    QString filename = QFileDialog::getSaveFileName(this, "Save Flashcards", "",
                                                    "JSON Files (*.json);;All Files (*)");
    
    if (filename.isEmpty()) return;
    
    if (m_flashcardManager.saveToFile(filename)) {
        QMessageBox::information(this, "Save Successful", 
                                "Flashcards saved successfully!");
        ui->statusbar->showMessage("Flashcards saved", 3000);
    } else {
        QMessageBox::warning(this, "Save Error", 
                           "Could not save flashcards to file.");
    }
}

void MainWindow::onLoadFlashcards()
{
    QString filename = QFileDialog::getOpenFileName(this, "Load Flashcards", "",
                                                    "JSON Files (*.json);;All Files (*)");
    
    if (filename.isEmpty()) return;
    
    if (m_flashcardManager.loadFromFile(filename)) {
        updateFlashcardList();
        QMessageBox::information(this, "Load Successful", 
                                "Flashcards loaded successfully!");
        ui->statusbar->showMessage("Flashcards loaded", 3000);
    } else {
        QMessageBox::warning(this, "Load Error", 
                           "Could not load flashcards from file.");
    }
}

void MainWindow::onStudyMode()
{
    int currentRow = ui->flashcardListWidget->currentRow();
    if (currentRow < 0) return;
    
    // Simple study mode: show/hide answer
    if (ui->answerDisplayLabel->text().isEmpty() || 
        ui->answerDisplayLabel->text() == "Click 'Study Mode' to reveal answer") {
        Flashcard card = m_flashcardManager.getFlashcard(currentRow);
        ui->answerDisplayLabel->setText("<b>Answer:</b><br>" + card.getAnswer());
        card.incrementReviewCount();
        m_flashcardManager.updateFlashcard(currentRow, card);
    } else {
        ui->answerDisplayLabel->setText("Click 'Study Mode' to reveal answer");
    }
}

void MainWindow::onFlashcardSelectionChanged()
{
    int currentRow = ui->flashcardListWidget->currentRow();
    bool hasSelection = currentRow >= 0;
    
    ui->editButton->setEnabled(hasSelection);
    ui->deleteButton->setEnabled(hasSelection);
    ui->studyButton->setEnabled(hasSelection);
    
    if (hasSelection) {
        showFlashcard(currentRow);
    } else {
        ui->questionDisplayLabel->setText("No flashcard selected");
        ui->answerDisplayLabel->setText("");
    }
}

void MainWindow::updateFlashcardList()
{
    ui->flashcardListWidget->clear();
    
    for (int i = 0; i < m_flashcardManager.getFlashcardCount(); ++i) {
        Flashcard card = m_flashcardManager.getFlashcard(i);
        QString question = card.getQuestion();
        if (question.length() > 50) {
            question = question.left(50) + "...";
        }
        ui->flashcardListWidget->addItem(question);
    }
    
    ui->flashcardCountLabel->setText(QString("Total Flashcards: %1")
                                    .arg(m_flashcardManager.getFlashcardCount()));
}

void MainWindow::showFlashcard(int index)
{
    if (index < 0 || index >= m_flashcardManager.getFlashcardCount()) {
        return;
    }
    
    Flashcard card = m_flashcardManager.getFlashcard(index);
    ui->questionDisplayLabel->setText("<b>Question:</b><br>" + card.getQuestion());
    ui->answerDisplayLabel->setText("Click 'Study Mode' to reveal answer");
}
