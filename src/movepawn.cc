#include "movepawn.hpp"

MovePawn::MovePawn(QObject *parent)
    : MovePoints(parent), m_first(true), m_x(0), m_y(0) {}

void MovePawn::setCurrent(uint x, uint y) {
  if (m_x != 0 && m_first) m_first = false;

  m_x = x;
  m_y = y;

  MovePoints::setCurrent(x, y);
}

void MovePawn::append(const QPair<uint, uint> &point, PlaceType type) {
  MovePoints::append(point, type);

  if (!m_first && abs(point.first - m_x) == 2)
    m_currentList.removeAt(m_currentList.indexOf(point));

  if (type == Empty) {
    if (!m_first && abs(point.first - m_x) == 2)
      m_currentList.removeAt(m_currentList.indexOf(point));
    if (abs(point.second - m_y) == 1)
      m_currentList.removeAt(m_currentList.indexOf(point));
  } else if (abs(point.second - m_y) == 0) {
    m_currentList.removeAt(m_currentList.indexOf(point));

    // we dont have to step over figures
    if (m_first && abs(point.first - m_x) == 1) {
      int index = m_currentList.indexOf(
          QPair<uint, uint>(point.first + (point.first - m_x), point.second));

      if (index != -1) m_currentList.removeAt(index);
    }
  }
}
