#ifndef FLASHCARDMANAGER_H
#define FLASHCARDMANAGER_H

#include <QList>
#include <QString>
#include "flashcard.h"

/**
 * @brief The FlashcardManager class manages a collection of flashcards
 */
class FlashcardManager
{
public:
    FlashcardManager();
    
    // Flashcard operations
    void addFlashcard(const Flashcard &flashcard);
    void removeFlashcard(int index);
    void updateFlashcard(int index, const Flashcard &flashcard);
    Flashcard getFlashcard(int index) const;
    int getFlashcardCount() const;
    QList<Flashcard> getAllFlashcards() const;
    
    // File operations
    bool saveToFile(const QString &filename);
    bool loadFromFile(const QString &filename);
    
    // Clear all flashcards
    void clear();
    
private:
    QList<Flashcard> m_flashcards;
};

#endif // FLASHCARDMANAGER_H
