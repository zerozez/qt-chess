#ifndef GAMEWINDOW_HPP
#define GAMEWINDOW_HPP

#include <QQmlEngine>
#include <QQuickView>

class GameWindow : public QDeclarativeView
{
    Q_OBJECT
public:
    GameWindow();
};

#endif // GAMEWINDOW_HPP
