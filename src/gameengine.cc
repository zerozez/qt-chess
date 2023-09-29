#include <QDir>
#include <QFile>
#include <QFileDialog>
#include <QList>
#include <QQmlContext>
#include <QQmlEngine>
#include <QtQml>

#include <src\figurebishop.hpp>
#include <src\figureking.hpp>
#include <src\figureknight.hpp>
#include <src\figurepawn.hpp>
#include <src\figurequeen.hpp>
#include <src\figurerook.hpp>

#include <src\chessmodel.hpp>
#include <src\historymodel.hpp>

#include "src\gameengine.hpp"
#include "src\movepoints.hpp"

GameEngine::GameEngine(QObject *parent)
    : QObject(parent),
      m_history(new HistoryModel(this)),
      m_figures(new ChessModel(this)),
      m_isWhite(true),
      m_lastClick(nullptr) {
  qmlRegisterUncreatableType<FigureIntf>("com.znocpmp.chess", 1, 0, "Figure",
                                         "");
  qmlRegisterType<ChessModel>("com.znocpmp.chess", 1, 0, "ChessModel");
}

GameEngine::~GameEngine() {}

void GameEngine::setupBoard() {
  for (int row = 0; row < 2; row++) {
    FigureIntf::Color color = row == 0 ? FigureIntf::Black : FigureIntf::White;
    int place = 8 - 7 * row;

    // Pawns
    for (int count = 1; count < 9; count++)
      m_figures->addFigure(
          new FigurePawn(place + (row == 0 ? -1 : 1), count, color));

    // Rooks
    m_figures->addFigure(new FigureRook(place, 1, color));
    m_figures->addFigure(new FigureRook(place, 8, color));

    // Bishops
    m_figures->addFigure(new FigureBishop(place, 3, color));
    m_figures->addFigure(new FigureBishop(place, 6, color));

    // Knights
    m_figures->addFigure(new FigureKnight(place, 2, color));
    m_figures->addFigure(new FigureKnight(place, 7, color));

    // Queen
    m_figures->addFigure(new FigureQueen(place, 4, color));

    // King
    m_figures->addFigure(new FigureKing(place, 5, color));
  }
}

void GameEngine::clean() {
  m_figures->erase();
}

void GameEngine::save() {}

void GameEngine::load() {}

void GameEngine::move() {}

QObject *GameEngine::figures() {
  return m_figures;
}

QObject *GameEngine::history() {
  return m_history;
}

void GameEngine::itemClicked(uint x, uint y) {
  FigureIntf *item = m_figures->getFigure(x, y);

  if (m_lastClick != nullptr) {
    if (m_lastClick->moveList().indexOf(QPair<uint, uint>(x, y)) != -1) {
      m_figures->removeAt(x, y);
      m_lastClick->moveTo(x, y);

      // Clean all up
      // next side to move
      m_isWhite = !m_isWhite;
      m_lastClick = nullptr;
      m_figures->rmHitSpot();
    } else if (m_lastClick->side() == item->side()) {
      m_lastClick = nullptr;
      m_figures->rmHitSpot();
      itemClicked(x, y);
    }
  }
  // Moves order
  else if ((item->side() == FigureIntf::Black) ^ m_isWhite) {
    item->defMoveList()->clear();

    setFigureWays(item);
    m_lastClick = item;
  }
}

void GameEngine::setFigureWays(FigureIntf *figure) {
  qDebug() << "loading ways to move";

  MovePoints *points = figure->defMoveList();

  if (points->isEmpty()) {
    QListIterator<QPair<uint, uint> > iterList(points->moves());

    while (iterList.hasNext()) {
      QPair<uint, uint> point = iterList.next();

      FigureIntf *pFigure = m_figures->getFigure(point.first, point.second);

      if (!pFigure)
        points->append(point, MovePoints::Empty);
      else if (pFigure->side() == figure->side())
        points->append(point, MovePoints::Friendly);
      else
        points->append(point, MovePoints::Enemy);
    }
  }

  m_figures->addHitSpot(points->moveList());
}
