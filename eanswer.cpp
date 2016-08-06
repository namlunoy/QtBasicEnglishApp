#include "eanswer.h"

EAnswer::EAnswer()
{

}

QString EAnswer::text() const
{
    return m_text;
}

void EAnswer::setText(const QString &text)
{
    m_text = text;
}

bool EAnswer::isCorrect() const
{
    return m_isCorrect;
}

void EAnswer::setIsCorrect(bool isCorrect)
{
    m_isCorrect = isCorrect;
}

QString EAnswer::hint() const
{
    return m_hint;
}

void EAnswer::setHint(const QString &hint)
{
    m_hint = hint;
}

int EAnswer::getId() const
{
    return id;
}

void EAnswer::setId(int value)
{
    id = value;
}

int EAnswer::getId_quest() const
{
    return id_quest;
}

void EAnswer::setId_quest(int value)
{
    id_quest = value;
}

