#ifndef TEXTWORK_H
#define TEXTWORK_H

#include <QtCore>
#include <QDebug>
#include <QList>
#include "eanswer.h"

class EAnswer;

class ETextWork
{
public:
    ETextWork();
    static QString getSampleData();
    static QStringList splitQuestion(const QString& input);    // Split the html into question section
    static QString correctString(const QString&  input);    // Get rid of html code in the string
    static QString getQuestion(const QString&  input);      // Get the question in the question section
    static QList<EAnswer> getAnswers(const QString& input);    // Get the answer from the question section
    static QString getExplanation(const QString& input);    // Get the explanation from the question section
    static QString getLessonContent(const QString& input);  // Get content of the lesson
    static void verifyForSql(QString& input);
};

#endif // TEXTWORK_H
