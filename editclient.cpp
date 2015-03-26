#include "editclient.h"
#include "ui_editclient.h"
#include "coorporateclient.h"
#include "premiumclient.h"
#include "regularclient.h"
#include "client.h"
#include <vector>
#include <QMessageBox>
#include <iostream>;

using std::vector;
using std::cout;
using std::endl;

EditClient::EditClient(vector<Client*>* clients, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditClient)
{
    ui->setupUi(this);
    this->clients = clients;
    if (clients->size() > 0){
        for (unsigned long i = 0; i < clients->size(); i++){
            ui->cb_client->addItem(clients->at(i)->toString().c_str());
        }
    } else {
        this->close();
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
    c ? ui->le_company->setEnabled(true) : ui->le_company->setEnabled(false);
    p ? ui->sb_years->setEnabled(true) : ui->sb_years->setEnabled(false);
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
        CoorporateClient* c = dynamic_cast<CoorporateClient*>(clients->at(index));
        c->setName(name.toStdString());
        c->setBirthday(birthday.toStdString());
        c->setGender(gender.toStdString());
        c->setCompany(company.toStdString());
        QMessageBox::information(this, "Edit", "Successfully edited");
        int answer;
        answer = QMessageBox::question(this, "Continue", "Do you want to continue editing?", QMessageBox::Yes, QMessageBox::No);
        if (answer == QMessageBox::Yes){
            CoorporateClient* c = dynamic_cast<CoorporateClient*>(clients->at(0));
            PremiumClient* p = dynamic_cast<PremiumClient*>(clients->at(0));
            RegularClient* r = dynamic_cast<RegularClient*>(clients->at(0));
            if (c){
                ui->cb_client->setCurrentIndex(0);
                ui->le_name->setText(QString::fromStdString(clients->at(0)->getName().c_str()));
                ui->le_birthday->setText(clients->at(0)->getBirthDay().c_str());
                ui->cb_gender->setCurrentIndex(clients->at(0)->getGender() == "Masculine" ? 0 : 1);
                ui->le_company->setText(c->getCompany().c_str());
                ui->le_company->setEnabled(false);
            }
            if (p){
                ui->cb_client->setCurrentIndex(0);
                ui->le_name->setText(QString::fromStdString(clients->at(0)->getName().c_str()));
                ui->le_birthday->setText(clients->at(0)->getBirthDay().c_str());
                ui->cb_gender->setCurrentIndex(clients->at(0)->getGender() == "Masculine" ? 0 : 1);
                ui->sb_years->setValue(p->getYears());
                ui->sb_years->setEnabled(false);
            }
            if (r){
                ui->cb_client->setCurrentIndex(0);
                ui->le_name->setText(QString::fromStdString(clients->at(0)->getName().c_str()));
                ui->le_birthday->setText(clients->at(0)->getBirthDay().c_str());
                ui->cb_gender->setCurrentIndex(clients->at(0)->getGender() == "Masculine" ? 0 : 1);
            }
        } else {
            this->close();
        }
    } else if (type == "Premium"){
        int years;
        years = ui->sb_years->value();
        PremiumClient* p = dynamic_cast<PremiumClient*>(clients->at(index));
        p->setName(name.toStdString());
        p->setBirthday(birthday.toStdString());
        p->setGender(gender.toStdString());
        p->setYears(years);
        QMessageBox::information(this, "Edit", "Successfully edited");
        int answer;
        answer = QMessageBox::question(this, "Continue", "Do you want to continue editing?", QMessageBox::Yes, QMessageBox::No);
        if (answer == QMessageBox::Yes){
            CoorporateClient* c = dynamic_cast<CoorporateClient*>(clients->at(0));
            PremiumClient* p = dynamic_cast<PremiumClient*>(clients->at(0));
            RegularClient* r = dynamic_cast<RegularClient*>(clients->at(0));
            if (c){
                ui->cb_client->setCurrentIndex(0);
                ui->le_name->setText(QString::fromStdString(clients->at(0)->getName().c_str()));
                ui->le_birthday->setText(clients->at(0)->getBirthDay().c_str());
                ui->cb_gender->setCurrentIndex(clients->at(0)->getGender() == "Masculine" ? 0 : 1);
                ui->le_company->setText(c->getCompany().c_str());
                ui->le_company->setEnabled(false);
            }
            if (p){
                ui->cb_client->setCurrentIndex(0);
                ui->le_name->setText(QString::fromStdString(clients->at(0)->getName().c_str()));
                ui->le_birthday->setText(clients->at(0)->getBirthDay().c_str());
                ui->cb_gender->setCurrentIndex(clients->at(0)->getGender() == "Masculine" ? 0 : 1);
                ui->sb_years->setValue(p->getYears());
                ui->sb_years->setEnabled(false);
            }
            if (r){
                ui->cb_client->setCurrentIndex(0);
                ui->le_name->setText(QString::fromStdString(clients->at(0)->getName().c_str()));
                ui->le_birthday->setText(clients->at(0)->getBirthDay().c_str());
                ui->cb_gender->setCurrentIndex(clients->at(0)->getGender() == "Masculine" ? 0 : 1);
            }
        } else {
            this->close();
        }
    } else {
        RegularClient* r = dynamic_cast<RegularClient*>(clients->at(index));
        r->setName(name.toStdString());
        r->setBirthday(birthday.toStdString());
        r->setGender(gender.toStdString());
        QMessageBox::information(this, "Edit", "Successfully edited");
        int answer;
        answer = QMessageBox::question(this, "Continue", "Do you want to continue editing?", QMessageBox::Yes, QMessageBox::No);
        if (answer == QMessageBox::Yes){
            CoorporateClient* c = dynamic_cast<CoorporateClient*>(clients->at(0));
            PremiumClient* p = dynamic_cast<PremiumClient*>(clients->at(0));
            RegularClient* r = dynamic_cast<RegularClient*>(clients->at(0));
            if (c){
                ui->cb_client->setCurrentIndex(0);
                ui->le_name->setText(QString::fromStdString(clients->at(0)->getName().c_str()));
                ui->le_birthday->setText(clients->at(0)->getBirthDay().c_str());
                ui->cb_gender->setCurrentIndex(clients->at(0)->getGender() == "Masculine" ? 0 : 1);
                ui->le_company->setText(c->getCompany().c_str());
                ui->sb_years->setEnabled(false);
            }
            if (p){
                ui->cb_client->setCurrentIndex(0);
                ui->le_name->setText(QString::fromStdString(clients->at(0)->getName().c_str()));
                ui->le_birthday->setText(clients->at(0)->getBirthDay().c_str());
                ui->cb_gender->setCurrentIndex(clients->at(0)->getGender() == "Masculine" ? 0 : 1);
                ui->sb_years->setValue(p->getYears());
                ui->le_company->setEnabled(false);
            }
            if (r){
                ui->cb_client->setCurrentIndex(0);
                ui->le_name->setText(QString::fromStdString(clients->at(0)->getName().c_str()));
                ui->le_birthday->setText(clients->at(0)->getBirthDay().c_str());
                ui->cb_gender->setCurrentIndex(clients->at(0)->getGender() == "Masculine" ? 0 : 1);
                ui->sb_years->setEnabled(false);
                ui->le_company->setEnabled(false);
            }
        } else {
            this->close();
        }
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
    c ? ui->le_company->setEnabled(true) : ui->le_company->setEnabled(false);
    p ? ui->sb_years->setEnabled(true) : ui->sb_years->setEnabled(false);
}
