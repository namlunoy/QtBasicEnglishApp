#ifndef EDATABASE_H
#define EDATABASE_H

#include <QSql>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include <QList>

#include "eutils.h"
#include "elesson.h"
#include "equestion.h"
#include "eanswer.h"

// Singleton pattern
class EDatabase
{
private:
    static QSqlDatabase _db;

public:
    EDatabase();
    ~EDatabase();

    void insert(EQuestion question);
    void insert(EAnswer answer);

    int insert(QList<EQuestion> questons);
    int insert(QList<EAnswer> answers);

    QList<ELesson> getLessons();
    QList<EQuestion> getQuestions(int idLesson);
    QList<EAnswer> getAnswers(QString idQuestion);

    void showQuestions();
    void showAnswers();
    void showLessons();

    void test();
};

#endif // EDATABASE_H
