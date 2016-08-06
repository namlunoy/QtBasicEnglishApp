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
        QString sql = "insert into Question (id, text, explan) values (" +QString::number(question.getId())+ ",'"+question.text()+"','"+question.explanation()+"')";
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
                +QString::number(answer.getId())+ ", " + QString::number(answer.getId_quest())
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
            sql = "insert into Question (id, text, explan) values (" +QString::number(q.getId())+ ",'"+q.text()+"','"+q.explanation()+"')";
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
                    +QString::number(a.getId())+ ", " + QString::number(a.getId_quest())
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

