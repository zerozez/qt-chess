
#include <figureintf.hpp>

#include "chessmodel.hpp"

#include <QDebug>

ChessModel::ChessModel(QObject* parent) : QAbstractListModel(parent) {}

int ChessModel::rowCount(const QModelIndex& parent) const {
  Q_UNUSED(parent)
  return m_data.size();
}

bool ChessModel::removeRows(int row, int count, const QModelIndex& parent) {
  if (count <= 0 || row < 0 || (row + count) > rowCount(parent)) return false;

  beginRemoveRows(QModelIndex(), row, row + count - 1);

  while (count > 0) {
    qDebug() << "Removing this " << row;
    m_data.removeAt(row);
    count--;
  }

  endRemoveRows();

  return true;
}

QHash<int, QByteArray> ChessModel::roleNames() const {
  QHash<int, QByteArray> out;

  out[XPosRole] = "X";
  out[YPosRole] = "Y";
  out[ImageRole] = "image";

  return out;
}

QVariant ChessModel::data(const QModelIndex& index, int role) const {
  if (index.isValid()) {
    if (index.row() < rowCount()) {
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

void ChessModel::addFigure(FigureIntf* in) {
  beginInsertRows(QModelIndex(), rowCount(), rowCount());

  m_data.append(in);

  connect(in, SIGNAL(moved(uint, uint)), SLOT(movedPiece(uint, uint)));

  endInsertRows();
}

FigureIntf* ChessModel::getFigure(const uint x, const uint y) {
  foreach (FigureIntf* item, m_data) {
    if (item->X() == x && item->Y() == y) return item;
  }

  // this case (with existing qml) shouldn't happend
  // and we do that only for ensurance
  return nullptr;
}

void ChessModel::addHitSpot(const QList<QPair<uint, uint> > list) {
  QListIterator<QPair<uint, uint> > iterList(list);

  while (iterList.hasNext()) {
    QPair<uint, uint> point = iterList.next();

    addFigure(new FigureIntf(point.first, point.second, FigureIntf::HitPlace));
  }
}

void ChessModel::rmHitSpot() {
  foreach (FigureIntf* figure, m_data) {
    if (figure->side() == FigureIntf::HitPlace)
      removeRows(m_data.indexOf(figure), 1, QModelIndex());
  }
}

void ChessModel::removeAt(const uint x, const uint y) {
  qDebug() << "Removing " << x << " and " << y;
  foreach (FigureIntf* item, m_data) {
    if (item->X() == x && item->Y() == y) {
      removeRows(m_data.indexOf(item), 1, QModelIndex());
    }
  }
}

void ChessModel::erase() {
  removeRows(0, rowCount(), QModelIndex());
}

void ChessModel::movedPiece(const uint x, const uint y) {
  Q_UNUSED(x)
  Q_UNUSED(y)

  emit dataChanged(createIndex(0, 0), createIndex(rowCount(), 0));
}
