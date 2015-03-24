#include "editclient.h"
#include "ui_editclient.h"
#include "coorporateclient.h"
#include "premiumclient.h"
#include "regularclient.h"
#include "client.h"
#include <vector>
#include <QMessageBox>

using std::vector;

EditClient::EditClient(vector<Client*>* clients, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditClient)
{
    ui->setupUi(this);
    this->clients = clients;
    for (unsigned long i = 0; i < clients->size(); i++){
        ui->cb_client->addItem(clients->at(i)->toString().c_str());
    }
    ui->le_name->setText(clients->at(0)->getName().c_str());
    ui->le_birthday->setText(clients->at(0)->getBirthDay().c_str());
    ui->cb_gender->setCurrentText(clients->at(0)->getGender().c_str());
    RegularClient* r = dynamic_cast<RegularClient*>(clients->at(0));
    PremiumClient* p = dynamic_cast<PremiumClient*>(clients->at(0));
    CoorporateClient* c = dynamic_cast<CoorporateClient*>(clients->at(0));
    if (r){
        ui->cb_type->setCurrentIndex(2);
    } else if (p){
        ui->cb_type->setCurrentIndex(1);
    } else {
        ui->cb_type->setCurrentIndex(0);
    }
    if (c){
            ui->le_company->setText(c->getCompany().c_str());
    } else {
            ui->le_company->setText("");
    }
    if (p){
            ui->sb_years->setValue(p->getYears());
    } else {
            ui->sb_years->setValue(0);
    }
    ui->le_company->text()!="" ? ui->le_company->setEnabled(true) : ui->le_company->setEnabled(false);
    ui->sb_years->value()!=0 ? ui->sb_years->setEnabled(true) : ui->sb_years->setEnabled(false);
}

EditClient::~EditClient()
{
    delete ui;
}

void EditClient::on_pushButton_clicked()
{
    int index = ui->cb_client->currentIndex();
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
        clients->at(index)->setName(name.toStdString());
        clients->at(index)->setBirthday(birthday.toStdString());
        clients->at(index)->setGender(gender.toStdString());
        CoorporateClient* c = dynamic_cast<CoorporateClient*>(clients->at(0));
        c->setCompany(company.toStdString());
        QMessageBox::information(this, "Edit", "Successfully edited");
        ui->le_name->setText("");

        ui->cb_gender->setCurrentIndex(0);
        ui->cb_type->setCurrentIndex(2);
        ui->le_company->setText("");
    } else if (type == "Premium"){
        int years;
        years = ui->sb_years->value();
        clients->at(index)->setName(name.toStdString());
        clients->at(index)->setBirthday(birthday.toStdString());
        clients->at(index)->setGender(gender.toStdString());
        PremiumClient* p = dynamic_cast<PremiumClient*>(clients->at(0));
        p->setYears(years);
        QMessageBox::information(this, "Edit", "Successfully edited");
        ui->le_name->setText("");

        ui->cb_gender->setCurrentIndex(0);
        ui->cb_type->setCurrentIndex(2);
        ui->sb_years->setValue(0);
    } else {
        clients->at(index)->setName(name.toStdString());
        clients->at(index)->setBirthday(birthday.toStdString());
        clients->at(index)->setGender(gender.toStdString());
        QMessageBox::information(this, "Edit", "Successfully edited");
        ui->le_name->setText("");

        ui->cb_gender->setCurrentIndex(0);
        ui->cb_type->setCurrentIndex(2);
    }
}

void EditClient::on_cb_client_currentIndexChanged(int index)
{
    ui->le_name->setText(clients->at(index)->getName().c_str());
    ui->le_birthday->setText(clients->at(index)->getBirthDay().c_str());
    ui->cb_gender->setCurrentText(clients->at(index)->getGender().c_str());
    RegularClient* r = dynamic_cast<RegularClient*>(clients->at(index));
    PremiumClient* p = dynamic_cast<PremiumClient*>(clients->at(index));
    CoorporateClient* c = dynamic_cast<CoorporateClient*>(clients->at(index));
    if (r){
        ui->cb_type->setCurrentIndex(2);
    } else if (p){
        ui->cb_type->setCurrentIndex(1);
    } else {
        ui->cb_type->setCurrentIndex(0);
    }
    if (c){
            ui->le_company->setText(c->getCompany().c_str());
    } else {
            ui->le_company->setText("");
    }
    if (p){
            ui->sb_years->setValue(p->getYears());
    } else {
            ui->sb_years->setValue(0);
    }
    ui->le_company->text()!="" ? ui->le_company->setEnabled(true) : ui->le_company->setEnabled(false);
    ui->sb_years->value()!=0 ? ui->sb_years->setEnabled(true) : ui->sb_years->setEnabled(false);
}
