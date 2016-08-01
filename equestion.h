#ifndef EQUESTION_H
#define EQUESTION_H

#include <QtCore>
#include "eanswer.h"

class EQuestion
{
public:
    EQuestion();

    QString explanation() const;
    void setExplanation(const QString &explanation);

    QString text() const;
    void setText(const QString &text);

private:
    QString m_text;
    QString m_explanation;
    QVector<EAnswer> m_vecAnswers;

};

#endif // EQUESTION_H
