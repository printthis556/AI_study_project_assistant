#include "flashcardmanager.h"
#include <QFile>
#include <QTextStream>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

FlashcardManager::FlashcardManager()
{
}

void FlashcardManager::addFlashcard(const Flashcard &flashcard)
{
    m_flashcards.append(flashcard);
}

void FlashcardManager::removeFlashcard(int index)
{
    if (index >= 0 && index < m_flashcards.size()) {
        m_flashcards.removeAt(index);
    }
}

void FlashcardManager::updateFlashcard(int index, const Flashcard &flashcard)
{
    if (index >= 0 && index < m_flashcards.size()) {
        m_flashcards[index] = flashcard;
    }
}

Flashcard FlashcardManager::getFlashcard(int index) const
{
    if (index >= 0 && index < m_flashcards.size()) {
        return m_flashcards[index];
    }
    return Flashcard();
}

int FlashcardManager::getFlashcardCount() const
{
    return m_flashcards.size();
}

QList<Flashcard> FlashcardManager::getAllFlashcards() const
{
    return m_flashcards;
}

bool FlashcardManager::saveToFile(const QString &filename)
{
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly)) {
        return false;
    }
    
    QJsonArray flashcardsArray;
    for (const Flashcard &card : m_flashcards) {
        QJsonObject cardObject;
        cardObject["question"] = card.getQuestion();
        cardObject["answer"] = card.getAnswer();
        cardObject["createdDate"] = card.getCreatedDate().toString(Qt::ISODate);
        cardObject["lastReviewed"] = card.getLastReviewed().toString(Qt::ISODate);
        cardObject["reviewCount"] = card.getReviewCount();
        flashcardsArray.append(cardObject);
    }
    
    QJsonDocument doc(flashcardsArray);
    file.write(doc.toJson());
    file.close();
    
    return true;
}

bool FlashcardManager::loadFromFile(const QString &filename)
{
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly)) {
        return false;
    }
    
    QByteArray data = file.readAll();
    file.close();
    
    QJsonDocument doc = QJsonDocument::fromJson(data);
    if (!doc.isArray()) {
        return false;
    }
    
    m_flashcards.clear();
    QJsonArray flashcardsArray = doc.array();
    
    for (const QJsonValue &value : flashcardsArray) {
        QJsonObject cardObject = value.toObject();
        Flashcard card(cardObject["question"].toString(), 
                      cardObject["answer"].toString());
        
        // Note: We'd need to add setters for these in Flashcard class to fully restore state
        // For now, we'll just create new cards with the question and answer
        m_flashcards.append(card);
    }
    
    return true;
}

void FlashcardManager::clear()
{
    m_flashcards.clear();
}
