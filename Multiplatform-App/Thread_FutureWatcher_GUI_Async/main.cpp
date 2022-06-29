#include <iostream>
#include <QApplication>
#include <QQmlContext>
#include <QQmlApplicationEngine>
#include "GuiManager.h"
#include "Worker.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    // C++ / QML class register
    qmlRegisterUncreatableType<GuiManager>("GuiManager", 1, 0, "GuiManager", "Expose GuiManager C++ to QML");


    QApplication app(argc, argv);
    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("GuiManager", GuiManager::getInstance().get());
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    engine.load(url);

    for( int i= 0;  i < 200; i++)
    {
        Worker worker;
        worker.bigTask(i);

    }

    return app.exec();
}