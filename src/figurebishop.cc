#include <movevectors.hpp>

#include "figurebishop.hpp"

FigureBishop::FigureBishop(const uint x, const uint y, FigureIntf::Color side,
                           QObject *parent)
    : FigureIntf(x, y, side, new MoveVectors(), parent) {
  MoveVectors *vectors = qobject_cast<MoveVectors *>(defMoveList());

  vectors->addPoint(1, 1);
  vectors->addPoint(-1, 1);
  vectors->addPoint(1, -1);
  vectors->addPoint(-1, -1);
  vectors->setCurrent(x, y);
}

QString FigureBishop::imagePath() const {
  return s_path;
}
