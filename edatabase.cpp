#include "edatabase.h"

QSqlDatabase EDatabase::_db = QSqlDatabase::addDatabase("QSQLITE");

EDatabase::EDatabase()
{
    if(_db.isValid())
    {
        QDir dir = EUtils::getCurrentProjectDir();
        QString path = dir.absolutePath() +"/data.db";
        _db.setDatabaseName(path);
    }
}

EDatabase::~EDatabase()
{
    if(_db.isValid() &&  _db.isOpen())
    {
        _db.close();
    }
}


void EDatabase::insert(EQuestion question)
{
    if(_db.open())
    {
        QSqlQuery query;
        QString sql = "insert into Question (id, text, explan) values (" +question.getId()+ ",'"+question.text()+"','"+question.explanation()+"')";
        qDebug() << sql;
        query.prepare(sql);
        if(query.exec()){
            qDebug() << query.numRowsAffected() << " row(s) effected!";
        }else{

            qDebug() << "Execute failed!";
            qDebug() << query.lastError().text();
        }

        _db.close();
    }
}

void EDatabase::insert(EAnswer answer)
{
    if(_db.open())
    {
        QString sql = "insert into Answer (id, question_id, text, is_correct, hint) values ("
                +answer.getId()+ ", " + answer.getQuestionId()
                + "  ,' " +answer.text()+ "',"+ QString::number(answer.isCorrect() ? 1 : 0)+",' "+ answer.hint() +" ')";
        qDebug() << sql;
        QSqlQuery query;
        query.prepare(sql);
        if(query.exec())
        {
            qDebug() << query.numRowsAffected()<<" row(s) effected!";
        }else{
            qDebug() << "Errors: " << query.lastError().text();
        }
        _db.close();
    }
}

int EDatabase::insert(QList<EQuestion> questons)
{
    if(_db.open())
    {
        int counter = 0;
        QString sql = "";
        QSqlQuery query;

        for(EQuestion q : questons)
        {
            sql = "insert into Question (id, text, explan) values (" +q.getId()+ ",'"+q.text()+"','"+q.explanation()+"')";
            query.prepare(sql);
            if(query.exec())
            {
                counter += query.numRowsAffected();
            }else{
                qDebug() << "FAILED: " << query.lastError().text();
            }
        }
        _db.close();
        return counter;
    }

    return 0;
}

int EDatabase::insert(QList<EAnswer> answers)
{
    if(_db.open())
    {
        int counter = 0;
        QSqlQuery query;
        QString sql;
        for(EAnswer a : answers)
        {
            sql = "insert into Answer (id, question_id, text, is_correct, hint) values ("
                    +a.getId()+ ", " + a.getQuestionId()
                    + "  ,' " +a.text()+ "',"+ QString::number(a.isCorrect() ? 1 : 0)+",' "+ a.hint() +" ')";
            query.prepare(sql);
            if(query.exec())
            {
                qDebug() << "ok";
                counter += query.numRowsAffected();
            }else{
                qDebug() << "FAILED: " << query.lastError().text();
            }
        }
        _db.close();
        return counter;
    }else{
        qDebug() << "Cannot open database!";
    }
    return 0;
}

QList<ELesson> EDatabase::getLessons()
{
    QList<ELesson> results;
    if(_db.open())
    {
        QString sql = "select * from Lesson";
        QSqlQuery query;
        query.prepare(sql);
        if(query.exec())
        {
            while(query.next())
            {
                ELesson l;
                l.setId(query.value("id").toInt());
                l.setText(query.value("text").toString());
                l.setUrl(query.value("url").toString());
                results.push_back(l);
            }
        }else{
            qDebug() << "Get lessons failed: " << query.lastError().text();
        }
        _db.close();
    }
    return results;
}

QList<EQuestion> EDatabase::getQuestions(int idLesson)
{
    QList<EQuestion> results;
    if(_db.open())
    {
        QString sql = "select * from Question where lesson_id = "+QString::number(idLesson);
        QSqlQuery query;
        query.prepare(sql);
        if(query.exec())
        {
           while(query.next())
           {
               EQuestion q(idLesson);
               q.setId(query.value("id").toString());
               q.setText(query.value("text").toString());
               q.setExplanation(query.value("explan").toString());
               results.push_back(q);
           }
        }else{
            qDebug() << "Get questions failed: "<< query.lastError().text();
        }
        _db.close();
    }

    // Get the answers of the questions
    for (int i = 0; i < results.count(); ++i) {
        results[i].setAnswers(getAnswers(results[i].getId()));
    }

    return results;
}

QList<EAnswer> EDatabase::getAnswers(QString idQuestion)
{
    QList<EAnswer> results;
    if(_db.open())
    {
        QString sql = "select * from Answer where question_id = '"+idQuestion+"'";
        QSqlQuery query;
        query.prepare(sql);
        if(query.exec())
        {
            while(query.next())
            {
                EAnswer a;
                a.setId(query.value("id").toString());
                a.setQuestionId(query.value("question_id").toString());
                a.setText(query.value("text").toString());
                a.setIsCorrect(query.value("is_correct").toBool());
                a.setHint(query.value("hint").toString());
                results.push_back(a);
            }
        }else{
            qDebug() << "Get Answers failed: " << query.lastError().text();
        }
        _db.close();
    }
    return results;
}

void EDatabase::showQuestions()
{
    if(_db.open())
    {
        QSqlQuery query("select * from Question");
        if(query.exec())
        {
            while(query.next())
                qDebug() << query.value(0).toString() <<" - "<<query.value(1).toString();
        }
        _db.close();
    }
}

void EDatabase::showAnswers()
{
    if(_db.open())
    {
        QSqlQuery query("select * from Answer");
        if(query.exec())
        {
            while(query.next())
                qDebug() << query.value(0).toString() <<" - "<<query.value(1).toString();
        }
        _db.close();
    }
}

void EDatabase::showLessons()
{
    if(_db.open())
    {
        QSqlQuery query("select * from Lesson");
        if(query.exec())
        {
            while(query.next())
                qDebug() << query.value(0).toString()
                         <<" - "<<query.value(1).toString()
                        <<" - "<<query.value(2).toString();;
        }
        _db.close();
    }
}

void EDatabase::test()
{
    _db.open();
    qDebug() << "Test open 2 times: "<< _db.open();
    _db.close();
}

