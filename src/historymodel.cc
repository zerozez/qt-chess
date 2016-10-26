#include <regex>

#include "historymodel.hpp"

HistoryModel::HistoryModel(QObject *parent) : QAbstractListModel(parent) {
  m_header.append("White");
  m_header.append("Black");
}

QHash<int, QByteArray> HistoryModel::roleNames() const {
  QHash<int, QByteArray> out;

  out[Number] = "Number";
  out[RecordW] = "RecordW";
  out[RecordB] = "RecordB";

  return out;
}

int HistoryModel::rowCount(const QModelIndex &parent) const {
  Q_UNUSED(parent)

  return m_data.size();
}

QVariant HistoryModel::headerData(int section, Qt::Orientation orientation,
                                  int role) const {
  Q_UNUSED(role)

  switch (orientation) {
    case Qt::Horizontal:
      if (section > 0) return m_header.at(section - 1);
    case Qt::Vertical:
      if (section > 1) return QString("[ %1 ]").arg(section);
  }

  return QVariant();
}

QVariant HistoryModel::data(const QModelIndex &index, int role) const {
  if (index.isValid()) {
    QRegExp exp(s_pattern);

    if (index.row() < rowCount()) {
      switch (role) {
        case Number:
          return index.row();
        case RecordW:
          m_data.at(index.row()).section(" ", 0, 0);
        case RecordB:
          m_data.at(index.row()).section(" ", 1, 1);
        default:
          break;
      }
    }
  }

  return QVariant();
}

void HistoryModel::setRecord(HistoryModel::Type type,
                             QPair<QString, uint> &from,
                             QPair<QString, uint> &to,
                             HistoryModel::MoveStatus status) {
  beginInsertRows(QModelIndex(), rowCount(), rowCount());

  QString str = QString("%1%2%3%4%5%6")
                    .arg(typeToString(type))
                    .arg(from.first)
                    .arg(from.second)
                    .arg(statusToString(status))
                    .arg(to.first)
                    .arg(to.second);

  if (m_data.size() % 2 == 0)
    m_data.append(str);
  else
    m_data.replace(m_data.size() - 1, m_data.at(m_data.size() - 1) + " " + str);

  endInsertRows();
}

QByteArray HistoryModel::save() const {
  return QByteArray();
}

void HistoryModel::load(QByteArray) {}

void HistoryModel::goForward() {
  if (m_data.size() > m_pos - 1) m_pos++;

  QRegExp exp(s_pattern);

  if (exp.indexIn(m_data.at(m_pos)) != -1)
    emit changed(toType(exp.cap(1)),
                 QPair<QString, uint>(exp.cap(2), exp.cap(3).toUInt()),
                 QPair<QString, uint>(exp.cap(4), exp.cap(5).toUInt()),
                 toStatus(exp.cap(6)));
}

void HistoryModel::goBack() {}

QString HistoryModel::typeToString(HistoryModel::Type type) const {
  switch (type) {
    case Bishop:
      return "B";
    case Rook:
      return "R";
    case Knight:
      return "N";
    case Queen:
      return "Q";
    case King:
      return "K";
    case Pawn:
      break;
  }

  return "";
}

QString HistoryModel::statusToString(HistoryModel::MoveStatus status) const {
  switch (status) {
    case Move:
      return "-";
    case Hit:
      return "x";
    case Check:
      return "+";
    case CheckMate:
      return "++";
    case CKS:
      return "O-O";
    case CQS:
      return "O-O-O";
  }

  return "";
}

HistoryModel::Type HistoryModel::toType(const QString &in) const {
  if (in == QString("B"))
    return Bishop;
  else if (in == QString("R"))
    return Rook;
  else if (in == QString("N"))
    return Knight;
  else if (in == QString("Q"))
    return Queen;
  else if (in == QString("K"))
    return King;

  return Pawn;
}

HistoryModel::MoveStatus HistoryModel::toStatus(const QString &in) const {
  if (in == QString("x")) return Hit;

  return Move;
}
