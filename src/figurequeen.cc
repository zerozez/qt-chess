#include <movevectors.hpp>

#include "figurequeen.hpp"

FigureQueen::FigureQueen(const uint x, const uint y, FigureIntf::Color side,
                         QObject *parent)
    : FigureIntf(x, y, side, new MoveVectors(), parent) {
  MoveVectors *vectors = qobject_cast<MoveVectors *>(defMoveList());

  vectors->addPoint(0, 1);
  vectors->addPoint(1, 1);
  vectors->addPoint(1, 0);
  vectors->addPoint(1, -1);
  vectors->addPoint(0, -1);
  vectors->addPoint(-1, -1);
  vectors->addPoint(-1, 0);
  vectors->addPoint(-1, 1);
  vectors->setCurrent(x, y);
}

QString FigureQueen::imagePath() const {
  return s_path;
}
