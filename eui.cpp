#include "eui.h"

EUI::EUI(QObject *parent) : QObject(parent)
{

}

QString EUI::getResult(QString url, QString stt)
{
    int no = stt.toInt();
    QList<EQuestion> listQuestions;

    QString output;

    // #1: Get data
    QString data = ETextWork::getSampleData();

    // #2: Separate questions add get info
    QStringList htmlQuests = ETextWork::splitQuestion(data);
    for(QString s : htmlQuests)
    {
        EQuestion q(no);

        q.setHtmlData(s);
        q.setVecAnswers(ETextWork::getAnswers(s));
        listQuestions.push_back(q);
    }

    for(EQuestion q : listQuestions)
    {
        qDebug() << "Q: "<< q.text();
        for(EAnswer a : q.vecAnswers())
        {
            qDebug() << a.text() <<"\t|"<<a.isCorrect() << "\t|"<<a.hint();
        }
        qDebug()<<"\n";
    }


    return output;
}
