#ifndef EUI_H
#define EUI_H

#include <QObject>
#include <QDebug>
#include <QList>
#include "etextwork.h"
#include "enetwork.h"
#include "eanswer.h"
#include "equestion.h"

class EUI : public QObject
{
    Q_OBJECT
public:
    explicit EUI(QObject *parent = 0);
    Q_INVOKABLE QString getResult(QString url);
signals:

public slots:
};

#endif // EUI_H
