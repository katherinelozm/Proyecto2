#include "deleteclient.h"
#include "ui_deleteclient.h"

DeleteClient::DeleteClient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeleteClient)
{
    ui->setupUi(this);
}

DeleteClient::~DeleteClient()
{
    delete ui;
}
