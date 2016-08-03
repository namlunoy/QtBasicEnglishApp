#ifndef EQUESTION_H
#define EQUESTION_H

#include <QtCore>
#include <QList>
#include "eanswer.h"
#include "etextwork.h"

class EQuestion
{
public:
    EQuestion(int stt);

    QString explanation() const;
    void setExplanation(const QString &explanation);

    QString text() const;
    void setText(const QString &text);

    QString htmlData() const;
    void setHtmlData(const QString &htmlData);

    QList<EAnswer> vecAnswers() const;
    void setVecAnswers(const QList<EAnswer> &vecAnswers);

    int getId() const;
    void setId(int value);

protected:
    void processHtmlData(const QString& input);

private:
    int id;
    QString m_text;
    QString m_explanation;
    QList<EAnswer> m_vecAnswers;
    QString m_htmlData;
};

#endif // EQUESTION_H
