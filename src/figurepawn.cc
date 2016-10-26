#include <movepawn.hpp>

#include "figurepawn.hpp"

FigurePawn::FigurePawn(const uint x, const uint y, Color side, QObject *parent)
    : FigureIntf(x, y, side, new MovePawn(), parent) {
  // This figure has a little different kind of moves
  MovePawn *points = qobject_cast<MovePawn *>(defMoveList());

  points->addPoint(side == White ? 1 : -1, 0);
  // only first
  points->addPoint(side == White ? 2 : -2, 0);
  points->addPoint(side == White ? 1 : -1, -1);
  points->addPoint(side == White ? 1 : -1, 1);

  // In here we have to get info for En passant (thinking how to make)
  // points->addPoint(0, -1);
  // points->addPoint(0,  1);

  points->setCurrent(x, y);
}

void FigurePawn::moveTo(const uint &x, const uint &y) {
  FigureIntf::moveTo(x, y);

  if (x == (side() == White ? 8 : 1)) emit askPromotion();
}

QString FigurePawn::imagePath() const {
  return s_path;
}
