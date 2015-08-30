#include <movepoints.hpp>

#include "figureintf.hpp"

FigureIntf::FigureIntf(QObject *parent) : QObject(parent)
{
}

FigureIntf::FigureIntf(const uint x, const uint y, Color side, MovePoints *points,
                       QObject *parent)
    : QObject(parent)
    , m_points(points)
    , m_xPos(x)
    , m_yPos(y)
    , m_color(side)
{
}

FigureIntf::~FigureIntf()
{
}

void FigureIntf::moveTo(const uint &x, const uint &y)
{
    setX(x);
    setY(y);

    m_points->clear();
    m_points->setCurrent(x, y);

    emit moved(x, y);
}

QList<QPair<uint, uint> > FigureIntf::moveList()
{
    return QList<QPair<uint, uint> >();
}

void FigureIntf::setX(const uint &x)
{
    m_xPos = x;
}

uint FigureIntf::X() const
{
    return m_xPos;
}

void FigureIntf::setY(const uint &y)
{
    m_yPos = y;
}

uint FigureIntf::Y() const
{
    return m_yPos;
}

FigureIntf::Color FigureIntf::side() const
{
    return m_color;
}

MovePoints *FigureIntf::defMoveList()
{
    return m_points;
}

QString FigureIntf::imgPrefix() const
{
    QString out("qrc:/qt-chess/img/images/");

    if(m_color == White)
        out += "c_w";
    else
        out += "c_b";

    return out;
}
