#ifndef ENETWORK_H
#define ENETWORK_H

#include <QtCore>
#include <QObject>
#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkReply>

#include "elesson.h"

class ENetwork : public QObject
{
    Q_OBJECT
public:
    // Should use this -> and add the parent to it to auto release.
    explicit ENetwork(QObject *parent = 0, ELesson *lesson = 0);
    ~ENetwork();

    void getData(QString url);

    ELesson *getPLesson() const;
    void setPLesson(ELesson *value);

public slots:
    void onGetDataDone(QNetworkReply *reply);

private:
    QNetworkAccessManager *_network;
    ELesson *pLesson;
};

#endif // ENETWORK_H
