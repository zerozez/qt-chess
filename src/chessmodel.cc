
#include <figureintf.hpp>

#include "chessmodel.hpp"


ChessModel::ChessModel(QObject *parent)
{

}

ChessModel::~ChessModel()
{

}

int ChessModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_data.size();
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
        m_data.append(in);
        emit dataChanged(createIndex(0,0),createIndex(m_data.size(),0));
}

