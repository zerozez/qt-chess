#ifndef FIGUREKNIGHT_HPP
#define FIGUREKNIGHT_HPP

#include <QObject>

#include "figureintf.hpp"

/**
 * @brief The FigureKnight class
 *
 *      Knight class
 */
class FigureKnight : public FigureIntf {
  Q_OBJECT
 public:
  FigureKnight(const uint x = 0, const uint y = 0, Color side = White,
               QObject *parent = 0);

  QString imagePath() const;

 private:
  QString const s_path = QString(imgPrefix() + "n.svg");
};

#endif  // FIGUREKNIGHT_HPP
