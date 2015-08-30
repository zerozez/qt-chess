#include <QDir>
#include <QtQml>
#include <QFile>
#include <QQmlEngine>
#include <QQmlContext>
#include <QFileDialog>

#include <figureking.hpp>
#include <chessmodel.hpp>

#include "gameengine.hpp"


GameEngine::GameEngine(QObject *parent)
    :QObject(parent)
    ,m_figures(new ChessModel(this))
    ,m_isWhite(true)
{
    qmlRegisterUncreatableType<FigureIntf>("com.znocpmp.chess", 1, 0, "Figure", "");
    qmlRegisterType<ChessModel>("com.znocpmp.chess", 1, 0, "ChessModel");
}

GameEngine::~GameEngine()
{
}

void GameEngine::setupBoard()
{
    // Rookes

    //bishops

    //Kings
    m_figures->addFigure(new FigureKing(8, 5, FigureIntf::Black));
    m_figures->addFigure(new FigureKing(1, 5, FigureIntf::White));
}

void GameEngine::load()
{

}

void GameEngine::move()
{

}

QObject *GameEngine::figures()
{
    return m_figures;
}

void GameEngine::itemClicked(uint x, uint y)
{
}

void GameEngine::setFigureWays()
{
}
