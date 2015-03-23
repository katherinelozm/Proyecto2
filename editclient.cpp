#include "editclient.h"
#include "ui_editclient.h"

EditClient::EditClient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditClient)
{
    ui->setupUi(this);
}

EditClient::~EditClient()
{
    delete ui;
}
