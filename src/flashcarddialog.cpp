#include "flashcarddialog.h"
#include "ui_flashcarddialog.h"

FlashcardDialog::FlashcardDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::FlashcardDialog)
{
    ui->setupUi(this);
}

FlashcardDialog::~FlashcardDialog()
{
    delete ui;
}

void FlashcardDialog::setFlashcard(const Flashcard &flashcard)
{
    ui->questionTextEdit->setPlainText(flashcard.getQuestion());
    ui->answerTextEdit->setPlainText(flashcard.getAnswer());
}

Flashcard FlashcardDialog::getFlashcard() const
{
    return Flashcard(ui->questionTextEdit->toPlainText(),
                    ui->answerTextEdit->toPlainText());
}
