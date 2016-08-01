#ifndef EUI_H
#define EUI_H

#include <QObject>
#include "enetwork.h"

class EUI : public QObject
{
    Q_OBJECT
public:
    explicit EUI(QObject *parent = 0);
    Q_INVOKABLE QString getResult(QString url);
signals:

public slots:

private:
    ENetwork *m_network;
};

#endif // EUI_H
