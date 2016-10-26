#ifndef MOVEPOINTS_HPP
#define MOVEPOINTS_HPP

#include <QHash>
#include <QList>
#include <QObject>

class MovePoints : public QObject {
  Q_OBJECT
 public:
  // Status of step
  enum PlaceType { Empty, Friendly, Enemy };

  explicit MovePoints(QObject *parent = 0);

  void addPoint(int x, int y);

  QList<QPair<uint, uint> > moves() const;
  QList<QPair<uint, uint> > moveList() const;

  bool isEmpty() const;
  virtual void clear();

  virtual void setCurrent(uint x, uint y);
  virtual void append(const QPair<uint, uint> &point, PlaceType type);

 protected:
  QList<QPair<uint, uint> > m_moveList;    /**< Default ways to go */
  QList<QPair<int, int> > m_steps;         /**< How we can move */
  QList<QPair<uint, uint> > m_currentList; /**< Allow to go */
};

#endif  // MOVEPOINTS_HPP
