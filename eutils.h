#ifndef EUTILS_H
#define EUTILS_H

#include <QDir>
#include <QFile>
#include <QDebug>

class EUtils
{
public:
    EUtils();
    static const int MASK = 100;
    static QDir getCurrentProjectDir();
};

#endif // EUTILS_H
