#include "enetwork.h"

ENetwork::ENetwork(QObject *parent, ELesson *lesson) : QObject(parent)
{
    qDebug() << "ENetwork()";
    _network = new QNetworkAccessManager(this);
    QObject::connect(_network, &QNetworkAccessManager::finished,
                     this, &ENetwork::onGetDataDone);
    pLesson = lesson;
}

ENetwork::~ENetwork()
{
    qDebug() << "~ENetwork()";
}

void ENetwork::getData(QString url)
{
    qDebug() << "Sending request for lesson " << pLesson->getId();
    _network->get(QNetworkRequest(QUrl(url)));
}

void ENetwork::onGetDataDone(QNetworkReply *reply)
{
    qDebug() << "Lesson "<<pLesson->getId()<<" has been replied!";
    QString htmlContent(reply->readAll());
    getContentLesson(htmlContent);
}

void ENetwork::getAllObjects(const QString &htmlContent)
{
    QList<EQuestion> questions;
    QStringList htmlQuests = ETextWork::splitQuestion(htmlContent);
    int index = 0;
    for(QString s : htmlQuests)
    {
        index++;
        EQuestion q(pLesson->getId(), index);
        q.setHtmlData(s);
        questions.push_back(q);
    }
    pLesson->setQuestions(questions);
    EDatabase db;
    db.insert(*pLesson);

    qDebug() << "Lesson "<<pLesson->getId()<<" has "<<pLesson->getQuestions().count() << " question(s)";

}

void ENetwork::getContentLesson(const QString &htmlContent)
{
    QString content = ETextWork::getLessonContent(htmlContent);
    EDatabase db;
    db.updateContentLesson(pLesson->getId(),content);
}

ELesson *ENetwork::getPLesson() const
{
    return pLesson;
}

void ENetwork::setPLesson(ELesson *value)
{
    pLesson = value;
}
