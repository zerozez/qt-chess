#ifndef CHESSMODEL_HPP
#define CHESSMODEL_HPP

#include <QHash>
#include <QPair>
#include <QObject>
#include <QAbstractListModel>

class FigureIntf;
class ChessModel : public QAbstractListModel
{
    Q_OBJECT

public:

    enum ChessRoles {
        XPosRole = Qt::UserRole + 10,
        YPosRole,
        SideRole,
        ImageRole
    };

    explicit ChessModel(QObject *parent = 0);
    ~ChessModel();

    int rowCount(const QModelIndex & parent = QModelIndex()) const;

    QHash<int, QByteArray> roleNames() const;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;

    void addFigure(FigureIntf *in);

    private:
        QList<FigureIntf*>   m_data;
};

#endif // CHESSMODEL_HPP
