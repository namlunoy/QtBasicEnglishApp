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

QString EQuestion::htmlData() const
{
    return m_htmlData;
}

void EQuestion::setHtmlData(const QString &htmlData)
{
    m_htmlData = htmlData;
    processHtmlData(m_htmlData);
}

void EQuestion::processHtmlData(const QString &input)
{
    // #1: Get question
    m_text = ETextWork::getQuestion(input);

    // #2: Get explanation
    m_explanation = ETextWork::getExplanation(input);

    // #3: Get Answers

}

QList<EAnswer> EQuestion::vecAnswers() const
{
    return m_vecAnswers;
}

void EQuestion::setVecAnswers(const QList<EAnswer> &vecAnswers)
{
    m_vecAnswers = vecAnswers;
}

