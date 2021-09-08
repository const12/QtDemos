#include "wtablemodel.h"

WTableModel::WTableModel(QObject *parent)
    : QAbstractTableModel(parent)
{
}

WTableModel::~WTableModel()
{

}

void WTableModel::updateDataSource(const QMap<QString, double> &map)
{
    beginResetModel();
    currencyRate = map;
    endResetModel();
}

// 行数
int WTableModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    // FIXME: Implement me!
    return currencyRate.count();
}

// 列数
int WTableModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    // FIXME: Implement me!
    return currencyRate.count();
}

// 单元格数据显示
QVariant WTableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    switch (role) {
    case Qt::TextAlignmentRole: {
        return int(Qt::AlignRight | Qt::AlignVCenter);
    }
    case Qt::DisplayRole: {
        QString rowKey = (currencyRate.cbegin() + index.row()).key();
        QString colKey = (currencyRate.cbegin() + index.column()).key();

        double rowValue = currencyRate.value(rowKey);
        if (abs(rowValue) <= 0.00001) {
            return "###";
        } else {
            double rate = currencyRate.value(colKey) / rowValue;
            return QString("%1").arg(rate, 0, 'f', 4);
        }
    }
    default:
        return QVariant();
    }
}

// 表头信息显示
QVariant WTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
    if (role != Qt::DisplayRole)
        return QVariant();

    return (currencyRate.cbegin() + section).key();
}
