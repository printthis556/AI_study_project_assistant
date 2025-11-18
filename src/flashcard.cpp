#include "flashcard.h"

Flashcard::Flashcard()
    : m_question(""), m_answer(""), m_createdDate(QDateTime::currentDateTime()), 
      m_lastReviewed(), m_reviewCount(0)
{
}

Flashcard::Flashcard(const QString &question, const QString &answer)
    : m_question(question), m_answer(answer), m_createdDate(QDateTime::currentDateTime()),
      m_lastReviewed(), m_reviewCount(0)
{
}

QString Flashcard::getQuestion() const
{
    return m_question;
}

QString Flashcard::getAnswer() const
{
    return m_answer;
}

QDateTime Flashcard::getCreatedDate() const
{
    return m_createdDate;
}

QDateTime Flashcard::getLastReviewed() const
{
    return m_lastReviewed;
}

int Flashcard::getReviewCount() const
{
    return m_reviewCount;
}

void Flashcard::setQuestion(const QString &question)
{
    m_question = question;
}

void Flashcard::setAnswer(const QString &answer)
{
    m_answer = answer;
}

void Flashcard::setLastReviewed(const QDateTime &dateTime)
{
    m_lastReviewed = dateTime;
}

void Flashcard::incrementReviewCount()
{
    m_reviewCount++;
    m_lastReviewed = QDateTime::currentDateTime();
}
