#include "../include/flashcard.h"
#include "../include/flashcardmanager.h"
#include <QCoreApplication>
#include <QDebug>
#include <cassert>

void testFlashcardCreation() {
    qDebug() << "Testing Flashcard Creation...";
    Flashcard card("What is 2+2?", "4");
    assert(card.getQuestion() == "What is 2+2?");
    assert(card.getAnswer() == "4");
    assert(card.getReviewCount() == 0);
    qDebug() << "✓ Flashcard creation test passed";
}

void testFlashcardManager() {
    qDebug() << "Testing FlashcardManager...";
    FlashcardManager manager;
    
    // Test adding flashcards
    Flashcard card1("Question 1", "Answer 1");
    Flashcard card2("Question 2", "Answer 2");
    
    manager.addFlashcard(card1);
    manager.addFlashcard(card2);
    
    assert(manager.getFlashcardCount() == 2);
    qDebug() << "✓ Adding flashcards test passed";
    
    // Test retrieving flashcards
    Flashcard retrieved = manager.getFlashcard(0);
    assert(retrieved.getQuestion() == "Question 1");
    assert(retrieved.getAnswer() == "Answer 1");
    qDebug() << "✓ Retrieving flashcards test passed";
    
    // Test updating flashcards
    Flashcard updatedCard("Updated Question", "Updated Answer");
    manager.updateFlashcard(0, updatedCard);
    retrieved = manager.getFlashcard(0);
    assert(retrieved.getQuestion() == "Updated Question");
    qDebug() << "✓ Updating flashcards test passed";
    
    // Test deleting flashcards
    manager.removeFlashcard(0);
    assert(manager.getFlashcardCount() == 1);
    qDebug() << "✓ Deleting flashcards test passed";
}

void testSaveLoad() {
    qDebug() << "Testing Save/Load functionality...";
    FlashcardManager manager;
    
    Flashcard card1("Test Question 1", "Test Answer 1");
    Flashcard card2("Test Question 2", "Test Answer 2");
    
    manager.addFlashcard(card1);
    manager.addFlashcard(card2);
    
    // Save to file
    QString testFile = "/tmp/test_flashcards.json";
    bool saved = manager.saveToFile(testFile);
    assert(saved);
    qDebug() << "✓ Save to file test passed";
    
    // Load from file
    FlashcardManager manager2;
    bool loaded = manager2.loadFromFile(testFile);
    assert(loaded);
    assert(manager2.getFlashcardCount() == 2);
    
    Flashcard loadedCard = manager2.getFlashcard(0);
    assert(loadedCard.getQuestion() == "Test Question 1");
    assert(loadedCard.getAnswer() == "Test Answer 1");
    qDebug() << "✓ Load from file test passed";
}

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);
    
    qDebug() << "========================================";
    qDebug() << "AI Study Assistant - Unit Tests";
    qDebug() << "========================================";
    qDebug() << "";
    
    try {
        testFlashcardCreation();
        qDebug() << "";
        testFlashcardManager();
        qDebug() << "";
        testSaveLoad();
        qDebug() << "";
        qDebug() << "========================================";
        qDebug() << "All tests passed! ✓";
        qDebug() << "========================================";
        return 0;
    } catch (const std::exception& e) {
        qDebug() << "Test failed with exception:" << e.what();
        return 1;
    }
}
