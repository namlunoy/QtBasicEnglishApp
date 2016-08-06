#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QScopedPointer>
#include <QList>
#include <QDebug>
#include "eui.h"
#include "edatabase.h"
#include "equestion.h"
#include "eanswer.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    QScopedPointer<EUI> pUi(new EUI(&app));
    engine.rootContext()->setContextProperty("ui",pUi.data());

    //-------------------------------------------------

    EDatabase db;
    QList<ELesson> lessons = db.getLessons();


    for (int i = 0; i < lessons.count(); ++i) {
        qDebug() << "Times: "<<i;
        ENetwork *network = new ENetwork(&app, &lessons[i]);
        network->getData(lessons[i].getUrl());
    }

//    ENetwork *network = new ENetwork(&app, &lessons[8]);
//    network->getData(lessons[8].getUrl());


    return app.exec();
}
