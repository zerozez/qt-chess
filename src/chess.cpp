/**
 *
 *
 *
 */

#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include <src\gameengine.hpp>

/// Default programm running
int main(int argc, char* argv[]) {
  QApplication app(argc, argv);

  QQmlApplicationEngine engine;

#ifdef QT_DEBUG
  engine.rootContext()->setContextProperty("debug", true);
#else
  engine.rootContext()->setContextProperty("debug", false);
#endif

  engine.rootContext()->setContextProperty("GameEngine", new GameEngine);
  engine.load(QUrl(QStringLiteral("qrc:/qt-chess/qml/Window.qml")));

  return app.exec();
}
