#ifndef FIGUREKING_HPP
#define FIGUREKING_HPP

#include <QObject>

#include "figureintf.hpp"

/**
 * @brief The FigureKing class
 *
 *      King class
 */
class FigureKing : public FigureIntf {
  Q_OBJECT
 public:
  FigureKing(const uint x = 0, const uint y = 0, Color side = White,
             QObject *parent = 0);
  ~FigureKing();

  void setCastling(bool flag);
  bool isCastled() const;

  QString imagePath() const;
  void moveTo(const uint &x, const uint &y);

 Q_SIGNALS:
  void castling(uint x);

 private:
  bool m_sRook = false;   /**< Allow to castling */
  bool m_castled = false; /**< Status*/

  bool isCastlingMove(uint x) const;

 private:
  QString const s_path = QString(imgPrefix() + "k.svg");
};

#endif  // FIGUREKING_HPP
