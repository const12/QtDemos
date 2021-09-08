#ifndef WTABLEMODEL_H
#define WTABLEMODEL_H

#include <QAbstractTableModel>

class WTableModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit WTableModel(QObject *parent = nullptr);
    ~WTableModel();

    void updateDataSource(const QMap<QString, double>&);

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

private:
    QMap<QString, double>   currencyRate;//货币汇率，自定义数据源
};

#endif // WTABLEMODEL_H
