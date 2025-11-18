#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "flashcardmanager.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/**
 * @brief The MainWindow class is the main application window
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onAddFlashcard();
    void onEditFlashcard();
    void onDeleteFlashcard();
    void onImportFile();
    void onSaveFlashcards();
    void onLoadFlashcards();
    void onStudyMode();
    void onFlashcardSelectionChanged();

private:
    Ui::MainWindow *ui;
    FlashcardManager m_flashcardManager;
    
    void updateFlashcardList();
    void showFlashcard(int index);
};

#endif // MAINWINDOW_H
