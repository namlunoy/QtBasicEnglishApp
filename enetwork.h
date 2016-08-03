#ifndef ENETWORK_H
#define ENETWORK_H

#include <QtCore>
#include <QObject>
#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class ENetwork : public QObject
{
    Q_OBJECT
public:
    // Should use this -> and add the parent to it to auto release.
    explicit ENetwork(QObject *parent = 0);
    ~ENetwork();

    /**
     * @brief getData dfsdfsd
     * @param url sdfsdfsdf
     */
    void getData(QString url);

signals:
    void onGetDataDone(QNetworkReply *reply);

private:
    QNetworkAccessManager *m_networkManager;
};

#endif // ENETWORK_H
