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
    _network->get(QNetworkRequest(QUrl(url)));
}

void ENetwork::onGetDataDone(QNetworkReply *reply)
{
    QString htmlContent(reply->readAll());

}

ELesson *ENetwork::getPLesson() const
{
    return pLesson;
}

void ENetwork::setPLesson(ELesson *value)
{
    pLesson = value;
}
