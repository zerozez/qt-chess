#include <QDir>
#include <QtQml>
#include <QFile>
#include <QQmlEngine>
#include <QQmlContext>
#include <QFileDialog>

#include <figureking.hpp>

#include "gameengine.hpp"


GameEngine::GameEngine(QObject *parent)
    :QObject(parent)
{
    qmlRegisterUncreatableType<FigureIntf>("com.znocpmp.chess", 1, 0, "Figure", "");
}

GameEngine::~GameEngine()
{
}

void GameEngine::setupBoard()
{
    m_figures.insert(QPair<uint, uint>(5, 5), new FigureKing(5, 5, FigureIntf::White));
}

void GameEngine::load()
{

}

void GameEngine::move()
{

}

QQmlListProperty<FigureIntf> GameEngine::figures()
{
    QList<FigureIntf *> out;

    foreach (FigureIntf *figure, m_figures) {
        out.append(figure);
    }

    return QQmlListProperty<FigureIntf>(this, out);
}

FigureIntf *GameEngine::figureAt(const uint x, const uint y)
{
    return m_figures.value(QPair<uint, uint>(x, y),
                           new FigureKing(0, 0, FigureIntf::White));
}
