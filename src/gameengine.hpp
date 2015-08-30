#ifndef GAMEENGINE_HPP
#define GAMEENGINE_HPP

#include <QMap>
#include <QPair>
#include <QHash>
#include <QObject>
#include <QSharedPointer>
#include <QQmlListProperty>
#include <QAbstractListModel>

/**
 * @brief The GameEngine class
 *
 *      Main game engine. Control figures position,
 *      status of the game and moves history.
 *
 */
class ChessModel;
class FigureIntf;
class GameEngine : public QObject
{
    Q_OBJECT
    //Q_PROPERTY(QQmlListProperty<FigureIntf> figures READ figures)

public:
    explicit GameEngine(QObject *parent = 0);
    virtual ~GameEngine();

    Q_INVOKABLE void setupBoard();
    Q_INVOKABLE void load();
    Q_INVOKABLE void move();

    Q_INVOKABLE QObject *figures();

public Q_SLOTS:
    void itemClicked(uint x, uint y);

private:
    QMap<int, QString>      m_gHistory; /**< Move history*/
    ChessModel             *m_figures;  /**< Figures on the board */

    bool                    m_isWhite;  /**< WHo is going now */
    FigureIntf             *m_lastClick;/**< Figure to move */

private:
    void setFigureWays(FigureIntf *figure);

};

#endif // GAMEENGINE_HPP
