#include "eutils.h"

EUtils::EUtils()
{

}

QDir EUtils::getCurrentProjectDir()
{
    QDir dir;
    while(!dir.absolutePath().endsWith("Qt")){
        dir.cdUp();
        //qDebug() << dir.absolutePath();
    }
    dir.cd("QtBasicEnglishApp");
    return dir;
}
