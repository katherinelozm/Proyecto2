#include "clients.h"
#include "ui_clients.h"

Clients::Clients(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Clients)
{
    ui->setupUi(this);
}

Clients::~Clients()
{
    delete ui;
}
