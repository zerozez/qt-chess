#include <QPair>

#include "movepoints.hpp"

MovePoints::MovePoints(QObject *parent) : QObject(parent) {}

void MovePoints::addPoint(int x, int y) {
  m_steps.append(QPair<int, int>(x, y));
}

QList<QPair<uint, uint> > MovePoints::moves() const {
  return m_moveList;
}

QList<QPair<uint, uint> > MovePoints::moveList() const {
  return m_currentList;
}

bool MovePoints::isEmpty() const {
  return m_currentList.empty();
}

void MovePoints::clear() {
  m_currentList.clear();
}

void MovePoints::setCurrent(uint x, uint y) {
  m_moveList.clear();

  QListIterator<QPair<int, int> > stepIter(m_steps);

  while (stepIter.hasNext()) {
    QPair<int, int> step = stepIter.next();

    uint newX = x + step.first;
    uint newY = y + step.second;

    if (newX == 0 || newX > 8 || newY == 0 || newY > 8) continue;

    m_moveList.append(QPair<uint, uint>(newX, newY));
  }
}

void MovePoints::append(const QPair<uint, uint> &point,
                        MovePoints::PlaceType type) {
  switch (type) {
    case Empty:
    case Enemy:
      if (m_moveList.indexOf(point) != -1) m_currentList.append(point);
      break;
    default:
      break;
  }
}
