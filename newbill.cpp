#include "newbill.h"
#include "ui_newbill.h"
#include "client.h"
#include "meal.h"
#include "drink.h"
#include "bill.h"
#include "alcoholic.h"
#include "nonalcoholic.h"
#include <vector>

using std::vector;

NewBill::NewBill(vector<Client*>* clients, vector<Meal*>* meals, vector<Drink*>* drinks, vector<Bill*>* bills , QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewBill)
{
    ui->setupUi(this);
    this->clients = clients;
    this->meals = meals;
    this->drinks = drinks;
    this->bills = bills;
    vector<Meal*> m;
    vector<Drink*> d;
    bills->push_back(new Bill("Restaurante\n\nCity Mall\nTegucigalpa, Honduras", bills->size() + 1, " ",  m, d, 0, 0, 0, 0, 0));
    for (unsigned long i = 0; i < clients->size(); i++){
        ui->cb_clients->addItem(clients->at(i)->toString().c_str());
    }
    for (unsigned long i = 0; i < meals->size(); i++){
        ui->cb_meals->addItem(meals->at(i)->toString().c_str());
    }
    for (unsigned long i = 0; i < drinks->size(); i++){
        ui->cb_drinks->addItem(drinks->at(i)->toString().c_str());
    }
    ui->textEdit->setText(bills->at(bills->size()-1)->toString().c_str());
    ui->textEdit->setReadOnly(true);
}


NewBill::~NewBill(){
    delete ui;
}

void NewBill::on_pushButton_4_clicked(){
    ui->cb_meals->setEnabled(true);
    ui->cb_drinks->setEnabled(true);
    ui->pushButton->setEnabled(true);
    ui->pushButton_2->setEnabled(true);
    bills->at(bills->size()-1)->setClientName(ui->cb_clients->currentText().toStdString());
    ui->textEdit->setText(bills->at(bills->size()-1)->toString().c_str());
}

void NewBill::on_pushButton_clicked(){
    vector<Meal*> m = bills->at(bills->size()-1)->getMeals();
    m.push_back(meals->at(ui->cb_meals->currentIndex()));
    bills->at(bills->size()-1)->setMeals(m);
    bills->at(bills->size()-1)->setSub(meals->at(ui->cb_meals->currentIndex())->getPrice() + bills->at(bills->size()-1)->getSub());
    bills->at(bills->size()-1)->setTax15(meals->at(ui->cb_meals->currentIndex())->tax() + bills->at(bills->size()-1)->getTax15());
    bills->at(bills->size()-1)->setTips(clients->at(ui->cb_clients->currentIndex())->getTips()*bills->at(bills->size()-1)->getSub());
    bills->at(bills->size()-1)->setTotal(bills->at(bills->size()-1)->getSub() + bills->at(bills->size()-1)->getTax15() + bills->at(bills->size()-1)->getTax18() + bills->at(bills->size()-1)->getTips());
    ui->textEdit->setText(bills->at(bills->size()-1)->toString().c_str());

}

void NewBill::on_pushButton_2_clicked(){
    vector<Drink*> d = bills->at(bills->size()-1)->getDrinks();
    d.push_back(drinks->at(ui->cb_drinks->currentIndex()));
    bills->at(bills->size()-1)->setDrinks(d);
    bills->at(bills->size()-1)->setSub(drinks->at(ui->cb_drinks->currentIndex())->getPrice() + bills->at(bills->size()-1)->getSub());
    Alcoholic* a = dynamic_cast<Alcoholic*>(drinks->at(ui->cb_drinks->currentIndex()));
    NonAlcoholic* n = dynamic_cast<NonAlcoholic*>(drinks->at(ui->cb_drinks->currentIndex()));
    if (a){
        bills->at(bills->size()-1)->setTax18(a->tax() + bills->at(bills->size()-1)->getTax18());
    }
    if(n){
        bills->at(bills->size()-1)->setTax15(n->tax() + bills->at(bills->size()-1)->getTax15());
    }
    double sub = bills->at(bills->size()-1)->getSub();
    bills->at(bills->size()-1)->setTips(clients->at(ui->cb_clients->currentIndex())->getTips()*sub);
    bills->at(bills->size()-1)->setTotal(bills->at(bills->size()-1)->getSub() + bills->at(bills->size()-1)->getTax15() + bills->at(bills->size()-1)->getTax18() + bills->at(bills->size()-1)->getTips());
    ui->textEdit->setText(bills->at(bills->size()-1)->toString().c_str());
}

void NewBill::on_pushButton_3_clicked()
{
    this->close();
}
