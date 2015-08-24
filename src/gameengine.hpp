#ifndef GAMEENGINE_HPP
#define GAMEENGINE_HPP

#include <QMap>
#include <QPair>
#include <QHash>
#include <QObject>
#include <QSharedPointer>
#include <QQmlListProperty>

/**
 * @brief The GameEngine class
 *
 *      Main game engine. Control figures position,
 *      status of the game and moves history.
 *
 */
class FigureIntf;
class GameEngine : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<FigureIntf> figures READ figures)

public:
    explicit GameEngine(QObject *parent = 0);
    virtual ~GameEngine();

    Q_INVOKABLE void setupBoard();
    Q_INVOKABLE void load();
    Q_INVOKABLE void move();

    Q_INVOKABLE QQmlListProperty<FigureIntf> figures();

    FigureIntf *figureAt(const uint x, const uint y);

private:
    QMap<int, QString>                  m_gHistory; /**< Move history*/
    QHash<QPair<uint, uint>,
                    FigureIntf* >       m_figures;  /**< Figures on the board */
};

#endif // GAMEENGINE_HPP
