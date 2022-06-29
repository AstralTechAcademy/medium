#include <iostream>
#include <QApplication>
#include <QQmlApplicationEngine>


int main(int argc, char *argv[])
{

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication app(argc, argv);
    //qmlRegisterType<Hello>("es.hello", 1, 0, "HelloImp");

    QQmlApplicationEngine engine;
    engine.addImportPath("/home/gabridc/Repositorio/Astral_Academy/medium/Components");
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    engine.load(url);

    return app.exec();
}