#include "addclient.h"
#include "ui_addclient.h"
#include "client.h"
#include "coorporateclient.h"
#include "premiumclient.h"
#include "regularclient.h"
#include <vector>
#include <QMessageBox>

using std::vector;

AddClient::AddClient(vector<Client*>* clients, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddClient)
{
    ui->setupUi(this);
    this->clients = clients;
}

AddClient::~AddClient()
{
    delete ui;
}

void AddClient::on_pushButton_clicked()
{
    QString name;
    name = ui->le_name->text();
    QString birthday;
    birthday = ui->le_birthday->text();
    QString gender;
    gender = ui->cb_gender->currentText();
    QString type;
    type = ui->cb_type->currentText();
    if (type == "Corporate"){
        QString company;
        company = ui->le_company->text();
        CoorporateClient* cc = new CoorporateClient(name.toStdString(), birthday.toStdString(), gender.toStdString(), company.toStdString());
        clients->push_back(cc);
        QMessageBox::information(this, "Create", "Successfully created");
        ui->le_name->setText("");
        ui->le_birthday->setText("January 1, 1989");
        ui->cb_gender->setCurrentIndex(0);
        ui->cb_type->setCurrentIndex(2);
        ui->le_company->setText("");
    } else if (type == "Premium"){
        int years;
        years = ui->sb_years->value();
        PremiumClient* pc = new PremiumClient(name.toStdString(), birthday.toStdString(), gender.toStdString(), years);
        clients->push_back(pc);
        QMessageBox::information(this, "Create", "Successfully created");
        ui->le_name->setText("");
        ui->le_birthday->setText("January 1, 1989");
        ui->cb_gender->setCurrentIndex(0);
        ui->cb_type->setCurrentIndex(2);
        ui->sb_years->setValue(0);
    } else {
        RegularClient* rc = new RegularClient(name.toStdString(), birthday.toStdString(), gender.toStdString());
        clients->push_back(rc);
        QMessageBox::information(this, "Create", "Successfully created");
        ui->le_name->setText("");
        ui->le_birthday->setText("January 1, 1989");
        ui->cb_gender->setCurrentIndex(0);
        ui->cb_type->setCurrentIndex(2);
    }
}

void AddClient::on_cb_type_currentIndexChanged(int index)
{
    if (index == 0){
        ui->le_company->setEnabled(false);
        ui->sb_years->setEnabled(false);
        ui->le_company->setText("");
        ui->sb_years->setValue(0);
    } else if (index == 1){
        ui->le_company->setEnabled(false);
        ui->sb_years->setEnabled(true);
        ui->le_company->setText("");
        ui->sb_years->setValue(0);
    } else {
        ui->le_company->setEnabled(true);
        ui->sb_years->setEnabled(false);
        ui->le_company->setText("");
        ui->sb_years->setValue(0);
    }
}
