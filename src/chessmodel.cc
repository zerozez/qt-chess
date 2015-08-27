
#include <figureintf.hpp>

#include "chessmodel.hpp"

#include <QDebug>

ChessModel::ChessModel(QObject *parent)
    : QAbstractListModel(parent)
{

}

int ChessModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_data.size();
}

bool ChessModel::removeRows(int row, int count, const QModelIndex &parent)
{
    if (count <= 0 || row < 0 || (row + count) > rowCount(parent))
        return false;

    beginRemoveRows(QModelIndex(), row, row + count - 1);


    while(count > 0)
    {
        qDebug() << "Removing this " << row ;
        m_data.removeAt(row);
        count--;
    }

    endRemoveRows();

    return true;
}

QHash<int, QByteArray> ChessModel::roleNames() const
{
    QHash<int, QByteArray> out;

    out[XPosRole] = "X";
    out[YPosRole] = "Y";
    out[ImageRole] = "image";

    return out;
}

QVariant ChessModel::data(const QModelIndex &index, int role) const
{
    if (index.isValid())
    {
        if(index.row() < rowCount())
        {
            switch (role) {
            case XPosRole:
                return m_data.at(index.row())->X();
            case YPosRole:
                return m_data.at(index.row())->Y();
            case ImageRole:
                return m_data.at(index.row())->imagePath();
            default:
                break;
            }
        }
    }

    return QVariant();
}

void ChessModel::addFigure(FigureIntf *in)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());

    m_data.append(in);

    endInsertRows();
}

void ChessModel::removeAt(const uint x, const uint y)
{
    qDebug() << "Removing " << x << " and " << y ;
    foreach (FigureIntf *item, m_data) {
        if(item->X() == x && item->Y() == y)
        {
            removeRows(m_data.indexOf(item), 1, QModelIndex());
        }
    }
}

