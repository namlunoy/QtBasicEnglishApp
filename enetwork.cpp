#include "enetwork.h"

ENetwork::ENetwork(QObject *parent) : QObject(parent)
{
    qDebug() << "ENetwork()";
    m_networkManager = new QNetworkAccessManager(this);
    QObject::connect(m_networkManager, &QNetworkAccessManager::finished,
                     this, &ENetwork::onGetDataDone);
}

ENetwork::~ENetwork()
{
    qDebug() << "~ENetwork()";
}
