#ifndef MOVEPAWN_HPP
#define MOVEPAWN_HPP

#include <QObject>

#include "movepoints.hpp"

/**
 * @brief The MovePawn class
 *
 *      Special case of moving pawn
 */
class MovePawn : public MovePoints {
  Q_OBJECT
 public:
  explicit MovePawn(QObject *parent = 0);

  virtual void setCurrent(uint x, uint y);
  virtual void append(const QPair<uint, uint> &point, PlaceType type);

 private:
  bool m_first; /**< first move */
  uint m_x;     /**< x */
  uint m_y;     /**< y */
};

#endif  // MOVEPAWN_HPP
