/**
 *
 *
 *
 */

#include <QApplication>
#include <QQmlApplicationEngine>


/// Default programm running
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/qt-chess/qml/Window.qml")));

    return app.exec();
}
