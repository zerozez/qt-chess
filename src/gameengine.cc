#include <QDir>
#include <QtQml>
#include <QFile>
#include <QList>
#include <QQmlEngine>
#include <QQmlContext>
#include <QFileDialog>

#include <figureking.hpp>
#include <chessmodel.hpp>

#include "gameengine.hpp"
#include "movepoints.hpp"


GameEngine::GameEngine(QObject *parent)
    :QObject(parent)
    ,m_figures(new ChessModel(this))
    ,m_isWhite(true)
    ,m_lastClick(nullptr)
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
    FigureIntf* item = m_figures->getFigure(x, y);

    if(m_lastClick != nullptr)
    {
        if (m_lastClick->moveList().indexOf(QPair<uint, uint>(x, y)) != -1)
        {
            m_figures->removeAt(x, y);
            m_lastClick->moveTo(x, y);

            // Clean all up
            // next side to move
            m_isWhite = !m_isWhite;
            m_lastClick = nullptr;
            m_figures->rmHitSpot();
        }
        else if( m_lastClick->side() == item->side())
        {
            m_lastClick = nullptr;
            m_figures->rmHitSpot();
            itemClicked(x, y);
        }
    }
    // Moves order
    else if((item->side() == FigureIntf::Black) ^ m_isWhite)
    {
        setFigureWays(item);
        m_lastClick = item;
    }
}

void GameEngine::setFigureWays(FigureIntf *figure)
{
    qDebug() << "loading ways to move" ;

    MovePoints *points = figure->defMoveList();

    if(points->isEmpty())
    {
        QListIterator<QPair<uint, uint> > iterList(points->moves());

        while (iterList.hasNext())
        {
            QPair<uint, uint> point = iterList.next();

            FigureIntf *pFigure = m_figures->getFigure(point.first, point.second);

            if(!pFigure)
                points->append(point, MovePoints::Empty);
            else if(pFigure->side() == figure->side())
                points->append(point, MovePoints::Friendly);
            else
                points->append(point, MovePoints::Enemy);
        }
    }

    m_figures->addHitSpot(points->moveList());
}
