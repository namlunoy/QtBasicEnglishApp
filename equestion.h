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
    EQuestion(int lessonId);

    QString explanation() const;
    void setExplanation(const QString &explanation);

    QString text() const;
    void setText(const QString &text);

    QString htmlData() const;
    void setHtmlData(const QString &htmlData);

    QList<EAnswer> answers() const;
    void setAnswers(const QList<EAnswer> &answers);

    int getId() const;
    void setId(int value);

    int getLessonId() const;
    void setLessonId(int value);

    QString toString();
protected:
    void processHtmlData(const QString& input);

private:
    int id;
    int lessonId;
    QString m_text;
    QString m_explanation;
    QList<EAnswer> m_Answers;
    QString m_htmlData;
};

#endif // EQUESTION_H
