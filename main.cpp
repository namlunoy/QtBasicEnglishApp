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

    EDatabase db;
    QList<EQuestion> questions = db.getQuestions(1);
    for(auto q : questions)
    {
        qDebug() << q.toString() << q.answers().count();
        QList<EAnswer> r = q.answers();

        for(auto a : r)
            qDebug() << a.toString();
        qDebug() << endl;
    }


    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    QScopedPointer<EUI> pUi(new EUI(&app));
    engine.rootContext()->setContextProperty("ui",pUi.data());


    return app.exec();
}
