#include "clients.h"
#include "ui_clients.h"
#include "addclient.h"
#include "editclient.h"
#include "deleteclient.h"
#include "client.h"
#include <vector>

Clients::Clients(vector<Client*>* clients, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Clients)
{
    ui->setupUi(this);
    this->clients = clients;
}

Clients::~Clients()
{
    delete ui;
}

void Clients::on_pushButton_clicked()
{
    AddClient ac(clients);
    ac.exec();
}

void Clients::on_pushButton_2_clicked()
{
    EditClient ec(clients);
    ec.exec();
}

void Clients::on_pushButton_3_clicked()
{
    DeleteClient dc(clients);
    dc.exec();
}
