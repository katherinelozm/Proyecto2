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
    this->close();
}

void Clients::on_pushButton_2_clicked()
{
    if (clients->size() > 0){
        EditClient ec(clients);
        ec.exec();
        this->close();
    }
}

void Clients::on_pushButton_3_clicked()
{
    if (clients->size() > 0){
        DeleteClient dc(clients);
        dc.exec();
        this->close();
    }
}
