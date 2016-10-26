#ifndef FIGUREPAWN_HPP
#define FIGUREPAWN_HPP

#include <QObject>

#include "figureintf.hpp"

/**
 * @brief The FigurePawn class
 *
 *      Pawn figure
 */
class FigurePawn : public FigureIntf {
  Q_OBJECT
 public:
  FigurePawn(const uint x = 0, const uint y = 0, Color side = White,
             QObject *parent = 0);

  void moveTo(const uint &x, const uint &y);
  QString imagePath() const;

 Q_SIGNALS:
  void askPromotion();

 private:
  QString const s_path = QString(imgPrefix() + "p.svg");
};

#endif  // FIGUREPAWN_HPP
