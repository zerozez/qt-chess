#include "movevectors.hpp"

MoveVectors::MoveVectors(QObject *parent) : MovePoints(parent) {}

void MoveVectors::setCurrent(uint x, uint y) {
  m_moveList.clear();

  QListIterator<QPair<int, int> > stepIter(m_steps);

  // we have to know to construct a vector of movements
  m_x = x;
  m_y = y;

  while (stepIter.hasNext()) {
    QPair<int, int> step = stepIter.next();

    uint newX = x;
    uint newY = y;

    while ((newX > 0 && newX < 9) && (newY > 0 && newY < 9)) {
      if (newX != x || newY != y)
        m_moveList.append(QPair<uint, uint>(newX, newY));

      newX = newX + step.first;
      newY = newY + step.second;
    }
  }
}

void MoveVectors::append(const QPair<uint, uint> &point,
                         MovePoints::PlaceType type) {
  int vec_x = point.first - m_x;
  int vec_y = point.second - m_y;

  // just protection of unpredictable input
  if ((abs(vec_x) != abs(vec_y)) && (vec_x != 0 && vec_y != 0)) return;

  vec_x = vec_x == 0 ? 0 : vec_x / abs(vec_x);
  vec_y = vec_y == 0 ? 0 : vec_y / abs(vec_y);

  uint posX = m_x;
  uint posY = m_y;

  while (!(posX == point.first && posY == point.second)) {
    posX += vec_x;
    posY += vec_y;

    if (m_stops.indexOf(QPair<uint, uint>(posX, posY)) != -1) return;
  }

  switch (type) {
    case Friendly:
      m_stops.append(point);
      checkExisting(point, vec_x, vec_y);
      break;

    // No break. That is not an error. We must add point to go then enemy or
    // nothing
    case Enemy:
      m_stops.append(
          QPair<uint, uint>(point.first + vec_x, point.second + vec_y));
      checkExisting(
          QPair<uint, uint>(point.first + vec_x, point.second + vec_y), vec_x,
          vec_y);

    default:
      MovePoints::append(point, type);
  }
}

void MoveVectors::clear() {
  m_stops.clear();

  MovePoints::clear();
}

void MoveVectors::checkExisting(QPair<uint, uint> point, int x, int y) {
  while (point.first > 0 && point.first < 9 && point.second > 0 &&
         point.second < 9) {
    point.first += x;
    point.second += y;

    int index = m_currentList.indexOf(point);

    if (index != -1) m_currentList.removeAt(index);
  }
}
