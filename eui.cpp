#include "eui.h"

EUI::EUI(QObject *parent) : QObject(parent)
{
    m_network = new ENetwork(this);
    m_network->getData("");
}

QString EUI::getResult(QString url)
{
    return "qwer";
}
