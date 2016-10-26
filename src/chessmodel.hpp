#ifndef CHESSMODEL_HPP
#define CHESSMODEL_HPP

#include <QAbstractListModel>
#include <QHash>
#include <QObject>
#include <QPair>

class FigureIntf;
class ChessModel : public QAbstractListModel {
  Q_OBJECT

 public:
  enum ChessRoles {
    XPosRole = Qt::UserRole + 10,
    YPosRole,
    SideRole,
    ImageRole
  };

  explicit ChessModel(QObject *parent = 0);

  int rowCount(const QModelIndex &parent = QModelIndex()) const;
  bool removeRows(int row, int count, const QModelIndex &parent);

  QHash<int, QByteArray> roleNames() const;
  QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

  void addFigure(FigureIntf *in);
  FigureIntf *getFigure(const uint x, const uint y);

  void addHitSpot(const QList<QPair<uint, uint> > list);
  void rmHitSpot();

 public Q_SLOTS:
  void removeAt(const uint x, const uint y);
  void erase();
  void movedPiece(const uint x, const uint y);

 private:
  QList<FigureIntf *> m_data;
};

#endif  // CHESSMODEL_HPP
