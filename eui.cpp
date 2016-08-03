#include "eui.h"

EUI::EUI(QObject *parent) : QObject(parent)
{

}

QString EUI::getResult(QString url)
{
    QList<EQuestion> listQuestions;

    QString output;

    // #1: Get data
    QString data = ETextWork::getSampleData();

    // #2: Separate questions
    QStringList htmlQuests = ETextWork::splitQuestion(data);
    for(QString s : htmlQuests)
    {
        EQuestion q;
        q.setHtmlData(s);
        listQuestions.push_back(q);
        q.setVecAnswers(ETextWork::getAnswers(s));
    }




    return output;
}
