#ifndef FIGUREBISHOP_HPP
#define FIGUREBISHOP_HPP

#include <QObject>

#include "figureintf.hpp"

/**
 * @brief The FigureBishop class
 *
 *      Bishop class
 */
class FigureBishop : public FigureIntf {
  Q_OBJECT
 public:
  FigureBishop(const uint x = 0, const uint y = 0, Color side = White,
               QObject *parent = 0);

  QString imagePath() const;

 private:
  QString const s_path = QString(imgPrefix() + "b.svg");
};

#endif  // FIGUREBISHOP_HPP
