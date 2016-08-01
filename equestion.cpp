#include "equestion.h"

EQuestion::EQuestion()
{

}

QString EQuestion::explanation() const
{
    return m_explanation;
}

void EQuestion::setExplanation(const QString &explanation)
{
    m_explanation = explanation;
}

QString EQuestion::text() const
{
    return m_text;
}

void EQuestion::setText(const QString &text)
{
    m_text = text;
}

