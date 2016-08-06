#ifndef EQUESTION_H
#define EQUESTION_H

#include <QtCore>
#include <QList>
#include "eanswer.h"
#include "etextwork.h"

class EQuestion
{
public:
    EQuestion();
    EQuestion(int lessonId, int index);

    QString explanation() const;
    void setExplanation(const QString &explanation);

    QString text() const;
    void setText(const QString &text);

    QString htmlData() const;
    void setHtmlData(const QString &htmlData);

    QList<EAnswer> answers() const;
    void setAnswers(const QList<EAnswer> &answers);

    QString getId() const;
    void setId(const QString &value);

    int getLessonId() const;
    void setLessonId(int value);

    QString toString();

protected:
    void processHtmlData(const QString& input);

private:
    QString id;
    int lessonId;
    QString m_text;
    QString m_explanation;
    QList<EAnswer> m_Answers;
    QString m_htmlData;
};

#endif // EQUESTION_H
