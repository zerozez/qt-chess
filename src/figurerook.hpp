#ifndef FIGUREROOK_HPP
#define FIGUREROOK_HPP

#include <QObject>

#include "figureintf.hpp"

/**
 * @brief The FigureRook class
 *
 *      Rook class
 */
class FigureRook : public FigureIntf {
  Q_OBJECT
 public:
  FigureRook(const uint x = 0, const uint y = 0, Color side = White,
             QObject *parent = 0);

  QString imagePath() const;

 private:
  QString const s_path = QString(imgPrefix() + "r.svg");
};

#endif  // FIGUREROOK_HPP
