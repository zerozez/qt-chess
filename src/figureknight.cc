#include <movepoints.hpp>

#include "figureknight.hpp"

FigureKnight::FigureKnight(const uint x, const uint y, FigureIntf::Color side,
                           QObject *parent)
    : FigureIntf(x, y, side, new MovePoints(), parent) {
  MovePoints *points = defMoveList();

  points->addPoint(2, 1);
  points->addPoint(2, -1);
  points->addPoint(-2, 1);
  points->addPoint(-2, -1);
  points->addPoint(1, 2);
  points->addPoint(1, -2);
  points->addPoint(-1, 2);
  points->addPoint(-1, -2);
  points->setCurrent(x, y);
}

QString FigureKnight::imagePath() const {
  return s_path;
}
