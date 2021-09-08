#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "wtablemodel.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QMap<QString, double> data;
    data["USD"] = 1.0000;
    data["CNY"] = 0.1628;
    data["GBP"] = 1.5361;
    data["EUR"] = 1.2992;
    data["HKD"] = 0.1289;

    WTableModel* model = new WTableModel;
    model->updateDataSource(data);
    ui->tableView->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;
}
