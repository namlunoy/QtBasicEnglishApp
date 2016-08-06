#include "equestion.h"

EQuestion::EQuestion()
{

}

EQuestion::EQuestion(int lessonId)
{
    this->lessonId = lessonId;
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

int EQuestion::getLessonId() const
{
    return lessonId;
}

void EQuestion::setLessonId(int value)
{
    lessonId = value;
}

QString EQuestion::toString()
{
    return QString::number(lessonId) +":"+QString::number(id) +" - " + text();
}

int EQuestion::getId() const
{
    return id;
}

void EQuestion::setId(int value)
{
    id = value;
}

QList<EAnswer> EQuestion::answers() const
{
    return m_Answers;
}

void EQuestion::setAnswers(const QList<EAnswer> &vecAnswers)
{
    m_Answers = vecAnswers;
}

