#ifndef FIGUREINTF_HPP
#define FIGUREINTF_HPP

#include <QPair>
#include <QList>
#include <QObject>


/**
 * @brief The FigureIntf class
 *
 *      The interface class for different
 *      kind of pieces
 */
class FigureIntf : public QObject
{
    Q_OBJECT

    Q_PROPERTY(Color Side MEMBER m_color)
    Q_PROPERTY(int X MEMBER m_xPos)
    Q_PROPERTY(int Y MEMBER m_yPos)

    Q_ENUMS(Color)
public:

    /**
     * @brief The Color enum
     *
     *      Meh
     */
    enum Color
    {
        Black
       ,White
    };

    explicit FigureIntf(QObject *parent = 0);
    FigureIntf(const uint x, const uint y, Color side, QObject *parent = 0);
    virtual ~FigureIntf();

    Q_INVOKABLE virtual QString imagePath();
    Q_INVOKABLE virtual void    moveTo(const uint &x, const uint &y);

    /**
     * @brief Return posible moves
     *
     *      Depend on current position
     * @return List of moves
     */
    virtual QList<QPair<uint, uint> > moveList();

Q_SIGNALS:
    void moved(uint x, uint y);
    void clicked();

protected:
    uint X() const;
    void setX(const uint &x);

    void setY(const uint &y);
    uint Y() const;

    QString imgPrefix() const;

private:
    uint        m_xPos = 0;         /**< Current x position */
    uint        m_yPos = 0;         /**< Current y position */

    Color       m_color = White;    /**< Side of 'war' */
};

#endif // FIGUREINTF_HPP
