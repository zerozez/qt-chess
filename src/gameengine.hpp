#ifndef GAMEENGINE_HPP
#define GAMEENGINE_HPP

#include <QAbstractListModel>
#include <QHash>
#include <QMap>
#include <QObject>
#include <QPair>
#include <QQmlListProperty>
#include <QSharedPointer>

/**
 * @brief The GameEngine class
 *
 *      Main game engine. Control figures position,
 *      status of the game and moves history.
 *
 */
class ChessModel;
class FigureIntf;
class HistoryModel;
class GameEngine : public QObject {
  Q_OBJECT
  // Q_PROPERTY(QQmlListProperty<FigureIntf> figures READ figures)

 public:
  explicit GameEngine(QObject *parent = 0);
  virtual ~GameEngine();

  Q_INVOKABLE void setupBoard();
  Q_INVOKABLE void clean();
  Q_INVOKABLE void save();
  Q_INVOKABLE void load();
  Q_INVOKABLE void move();

  Q_INVOKABLE QObject *figures();
  Q_INVOKABLE QObject *history();

 public Q_SLOTS:
  void itemClicked(uint x, uint y);

 private:
  HistoryModel *m_history; /**< Move history*/
  ChessModel *m_figures;   /**< Figures on the board */

  bool m_isWhite;          /**< WHo is going now */
  FigureIntf *m_lastClick; /**< Figure to move */

 private:
  void setFigureWays(FigureIntf *figure);
};

#endif  // GAMEENGINE_HPP
