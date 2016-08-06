#ifndef ELESSON_H
#define ELESSON_H

#include <QtCore>
#include "equestion.h"
#include <QList>

class ELesson
{
public:
    ELesson();
    int getId() const;
    void setId(int value);

    QString getText() const;
    void setText(const QString &value);

    QString getUrl() const;
    void setUrl(const QString &value);

    QList<EQuestion> getQuestions() const;
    void setQuestions(const QList<EQuestion> &value);

    QString toString();
private:
    int id;
    QString text;
    QString url;
    QList<EQuestion> questions;
};

#endif // ELESSON_H
