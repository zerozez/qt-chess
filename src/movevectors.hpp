#ifndef MOVEVECTORS_HPP
#define MOVEVECTORS_HPP

#include <QList>
#include <QObject>
#include <QPair>

#include "movepoints.hpp"

class MoveVectors : public MovePoints {
  Q_OBJECT
 public:
  explicit MoveVectors(QObject *parent = 0);

  void setCurrent(uint x, uint y);
  void append(const QPair<uint, uint> &point, PlaceType type);

  void clear();

 private:
  QList<QPair<uint, uint>> m_stops;

  uint m_x; /**< x */
  uint m_y; /**< y */

 private:
  void checkExisting(QPair<uint, uint> point, int x, int y);
};

#endif  // MOVEVECTORS_HPP
