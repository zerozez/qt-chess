
#include <movepoints.hpp>

#include "figureking.hpp"

FigureKing::FigureKing(const uint x, const uint y, Color side, QObject *parent)
    : FigureIntf(x, y, side, parent)
{
    MovePoints *points = defMoveList();

    points->addPoint( 0, 1);
    points->addPoint( 1, 1);
    points->addPoint( 1, 0);
    points->addPoint( 1, -1);
    points->addPoint( 0, -1);
    points->addPoint( -1, -1);
    points->addPoint( -1, 0);
    points->addPoint( -1, 1);
    points->setCurrent(x, y);
}

FigureKing::~FigureKing()
{
}

void FigureKing::setCastling(bool flag)
{
    if(!m_castled)
        m_sRook = flag;
}

bool FigureKing::isCastled() const
{
    return m_castled;
}

QString FigureKing::imagePath() const
{
    return s_path;
}

void FigureKing::moveTo(const uint &x, const uint &y)
{
    // Only once in a game
    if(m_sRook & isCastlingMove(x))
    {
        m_castled = true;
        m_sRook = false;
    }

    FigureIntf::moveTo(x, y);
}

bool FigureKing::isCastlingMove(uint x) const
{
    return abs(X() - x) == 2;
}
