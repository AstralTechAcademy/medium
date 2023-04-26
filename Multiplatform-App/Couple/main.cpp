#include <iostream>
#include <string>
#include <QString>
#include <QDebug>
#include <QApplication>
#include <QQmlApplicationEngine>
#include "mysqlx/xdevapi.h"

#include "jdbc/mysql_connection.h"
#include "jdbc/mysql_error.h"
#include "jdbc/mysql_driver.h"
#include "jdbc/cppconn/statement.h"
#include "jdbc/cppconn/resultset.h"

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

int main(int argc, char *argv[])
{

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication app(argc, argv);

    sql::Driver * driver = sql::mysql::get_driver_instance();

    std::unique_ptr< sql::Connection > con(driver->connect("tcp://localhost:3306/couple", "user1", "user1"));

        // Create a SQL statement
    sql::Statement *stmt = con->createStatement();
    sql::ResultSet *res = stmt->executeQuery("SELECT * FROM Users");

    // Iterate through the result set
    while (res->next()) {
        int id = res->getInt("uuid");
        auto name = res->getString("username");
        std::cout << "ID: " << id << ", Name: " << name << std::endl;
    }

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setPort(3306);
    db.setDatabaseName("couple");
    db.setUserName("user1");
    db.setPassword("user1");
    bool ok = db.open();

    qDebug() << "QMYSQL DB opened: " << ok;

    QSqlQuery query = QSqlQuery(db);
    query.exec("SELECT uuid,username FROM Users");

    while(query.next())
    {
        qDebug() << "UUID: " << query.value(0).toInt() << " Username: "  <<  query.value(0).toString();
    }

    QQmlApplicationEngine engine;
    engine.addImportPath("/home/gabridc/Repositorio/Astral_Academy/medium/Components");
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    engine.load(url);

    return app.exec();
}