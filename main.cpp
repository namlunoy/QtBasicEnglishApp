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

    ENetwork network(&app, &lessons[0]);
    network.getData(lessons[0].getUrl());




    return app.exec();
}
