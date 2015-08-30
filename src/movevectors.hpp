#ifndef MOVEVECTORS_HPP
#define MOVEVECTORS_HPP

#include <QObject>

#include "movepoints.hpp"


class MoveVectors : public MovePoints
{
    Q_OBJECT
public:
    explicit MoveVectors(QObject *parent = 0);

    void append();
};

#endif // MOVEVECTORS_HPP
