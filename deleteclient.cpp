#include "deleteclient.h"
#include "ui_deleteclient.h"
#include "coorporateclient.h"
#include "premiumclient.h"
#include "regularclient.h"
#include "client.h"
#include <vector>
#include <QMessageBox>

using std::vector;

DeleteClient::DeleteClient(vector<Client*>* clients, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteClient)
{
    ui->setupUi(this);
    this->clients = clients;
    for (unsigned long i = 0; i < clients->size(); i++){
        ui->cb_clients->addItem(clients->at(i)->toString().c_str());
    }
}

DeleteClient::~DeleteClient()
{
    delete ui;
}

void DeleteClient::on_pushButton_clicked()
{
    clients->erase(clients->begin() + ui->cb_clients->currentIndex());
    ui->cb_clients->clear();
    if (clients->size() > 0){
        for (unsigned long i = 0; i < clients->size(); i++){
            ui->cb_clients->addItem(clients->at(i)->toString().c_str());
        }
    } else {
        this->close();
    }
}
