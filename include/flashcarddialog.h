#ifndef FLASHCARDDIALOG_H
#define FLASHCARDDIALOG_H

#include <QDialog>
#include "flashcard.h"

QT_BEGIN_NAMESPACE
namespace Ui { class FlashcardDialog; }
QT_END_NAMESPACE

/**
 * @brief The FlashcardDialog class provides a dialog for creating/editing flashcards
 */
class FlashcardDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FlashcardDialog(QWidget *parent = nullptr);
    ~FlashcardDialog();
    
    // Set flashcard data for editing
    void setFlashcard(const Flashcard &flashcard);
    
    // Get the flashcard data from the dialog
    Flashcard getFlashcard() const;

private:
    Ui::FlashcardDialog *ui;
};

#endif // FLASHCARDDIALOG_H
