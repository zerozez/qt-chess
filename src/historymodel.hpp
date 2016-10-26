#ifndef HISTORYMODEL_HPP
#define HISTORYMODEL_HPP

#include <QAbstractListModel>
#include <QObject>

/**
 * @brief The HistoryModel class
 *
 *      Loggin all moves in here
 */
class HistoryModel : public QAbstractListModel {
  Q_OBJECT
 public:
  enum ChessRoles { Number = Qt::UserRole + 10, RecordW, RecordB };

  enum MoveStatus {
    Move,
    Hit,
    Check,
    CheckMate,
    CKS,
    CQS,
  };

  enum Type { Pawn, Bishop, Rook, Knight, Queen, King };

  explicit HistoryModel(QObject *parent = 0);

  QHash<int, QByteArray> roleNames() const;

  int rowCount(const QModelIndex &parent = QModelIndex()) const;
  QVariant headerData(int section, Qt::Orientation orientation,
                      int role = Qt::DisplayRole) const;
  QVariant data(const QModelIndex &index, int role) const;

  void setRecord(HistoryModel::Type type, QPair<QString, uint> &from,
                 QPair<QString, uint> &to, HistoryModel::MoveStatus status);
  QByteArray save() const;
  void load(QByteArray);

 public Q_SLOTS:
  void goForward();
  void goBack();

 Q_SIGNALS:
  void changed(HistoryModel::Type, QPair<QString, uint>, QPair<QString, uint>,
               HistoryModel::MoveStatus status);

 private:
  uint m_pos;
  QStringList m_data;
  QStringList m_header;

 private:
  QString typeToString(const Type type) const;
  QString statusToString(const MoveStatus status) const;
  Type toType(const QString &in) const;
  MoveStatus toStatus(const QString &in) const;

  // capture only for move and hit
  QString const s_pattern = "(\\w?)(\\w)(\\d)([\\-x])(\\w)(\\d)";
};

#endif  // HISTORYMODEL_HPP
