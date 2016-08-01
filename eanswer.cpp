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
