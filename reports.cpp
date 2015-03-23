#include "reports.h"
#include "ui_reports.h"

Reports::Reports(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Reports)
{
    ui->setupUi(this);
}

Reports::~Reports()
{
    delete ui;
}
