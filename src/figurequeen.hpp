#ifndef FIGUREQUEEN_HPP
#define FIGUREQUEEN_HPP

#include <QObject>

#include "figureintf.hpp"

/**
 * @brief The FigureQueen class
 *
 *      Queen class
 */
class FigureQueen : public FigureIntf {
  Q_OBJECT
 public:
  FigureQueen(const uint x = 0, const uint y = 0, Color side = White,
              QObject *parent = 0);

  QString imagePath() const;

 private:
  QString const s_path = QString(imgPrefix() + "q.svg");
};

#endif  // FIGUREQUEEN_HPP
