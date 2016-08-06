#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QScopedPointer>
#include "eui.h"
#include "edatabase.h"
#include "equestion.h"
#include "eanswer.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    EDatabase db;
    QList<EAnswer> as;
    EAnswer a1;
    a1.setId(111);
    a1.setText("111");
    as.push_back(a1);

    EAnswer a2;
    a2.setId(222);
    a2.setText("222");
    as.push_back(a2);

    db.insert(as);
    db.showAnswers();

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    QScopedPointer<EUI> pUi(new EUI(&app));
    engine.rootContext()->setContextProperty("ui",pUi.data());


    return app.exec();
}
