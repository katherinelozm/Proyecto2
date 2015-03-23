#include "newbill.h"
#include "ui_newbill.h"

NewBill::NewBill(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewBill)
{
    ui->setupUi(this);
}

NewBill::~NewBill()
{
    delete ui;
}
