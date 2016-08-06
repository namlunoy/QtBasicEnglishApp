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
    int index = 0;
    for(QString s : htmlQuests)
    {
        index++;
        EQuestion q(no,index);

        q.setHtmlData(s);
        q.setAnswers(ETextWork::getAnswers(s));
        listQuestions.push_back(q);
    }

    for(EQuestion q : listQuestions)
    {
        qDebug() << "Q: "<< q.text();
        for(EAnswer a : q.answers())
        {
            qDebug() << a.text() <<"\t|"<<a.isCorrect() << "\t|"<<a.hint();
        }
        qDebug()<<"\n";
    }


    return output;
}
