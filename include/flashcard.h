#ifndef FLASHCARD_H
#define FLASHCARD_H

#include <QString>
#include <QDateTime>

/**
 * @brief The Flashcard class represents a single flashcard with a question and answer
 */
class Flashcard
{
public:
    Flashcard();
    Flashcard(const QString &question, const QString &answer);
    
    // Getters
    QString getQuestion() const;
    QString getAnswer() const;
    QDateTime getCreatedDate() const;
    QDateTime getLastReviewed() const;
    int getReviewCount() const;
    
    // Setters
    void setQuestion(const QString &question);
    void setAnswer(const QString &answer);
    void setLastReviewed(const QDateTime &dateTime);
    void incrementReviewCount();
    
private:
    QString m_question;
    QString m_answer;
    QDateTime m_createdDate;
    QDateTime m_lastReviewed;
    int m_reviewCount;
};

#endif // FLASHCARD_H
