#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "clients.h"
#include "newbill.h"
#include "client.h"
#include "coorporateclient.h"
#include "premiumclient.h"
#include "regularclient.h"
#include "meal.h"
#include "drink.h"
#include "alcoholic.h"
#include "nonalcoholic.h"
#include <vector>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <string>
#include <iostream>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    clients = new vector<Client*>();
    meals = new vector<Meal*>();
    drinks = new vector<Drink*>();
    bills = new vector<Bill*>();
    meals->push_back(new Meal("Grilled Steak", 30, "16 oz"));
    meals->push_back(new Meal("Pork Chops", 20, ""));
    meals->push_back(new Meal("Grilled Chicken", 23, ""));
    meals->push_back(new Meal("Shrimps", 35, ""));
    drinks->push_back(new NonAlcoholic("Coke", 3.50, "Bottle"));
    drinks->push_back(new NonAlcoholic("Coke", 3.40, "Can"));
    drinks->push_back(new NonAlcoholic("Lemonade", 4, ""));
    drinks->push_back(new NonAlcoholic("Iced Tea", 4, ""));
    drinks->push_back(new Alcoholic("Wine", 7.50, "Red"));
    drinks->push_back(new Alcoholic("Wine", 7.50, "White"));
    drinks->push_back(new Alcoholic("Heineken", 3.75, "Beer"));
    //Read Clients
    //Regular
    string name;
    string birthday;
    string gender;
    QFile file(":/textf/r_clients.txt");
    if (!file.open(QIODevice::ReadOnly)){
        QMessageBox::information(this, "Warning", file.errorString());
    } else {
        QTextStream in(&file);
        while (!in.atEnd()) {
            int cont = 0;
            QString line = in.readLine();
            istringstream iss(line.toStdString());
            do{
                string s;
                iss >> s;
                cont++;
                if (cont == 1){
                    name = s;
                } else if (cont == 2){
                    birthday = s;
                } else if (cont == 3){
                    gender = s;
                }
            } while (iss);
            clients->push_back(new RegularClient(name, birthday, gender));
        }

    }
    //Corporate
    string name2;
    string birthday2;
    string gender2;
    string company;
    QFile file2(":/textf/c_clients.txt");
    if (!file2.open(QIODevice::ReadOnly)){
        QMessageBox::information(this, "Warning", file2.errorString());
    } else {
        QTextStream in(&file2);
        while (!in.atEnd()) {
            int cont = 0;
            QString line = in.readLine();
            istringstream iss(line.toStdString());
            do{
                string s;
                iss >> s;
                cont++;
                if (cont == 1){
                    name = s;
                } else if (cont == 2){
                    birthday = s;
                } else if (cont == 3){
                    gender = s;
                } else if (cont == 4){
                    company = s;
                }
            } while (iss);
            clients->push_back(new CoorporateClient(name, birthday, gender, company));
        }

    }
    file2.close();
    //Premium
    string name3;
    string birthday3;
    string gender3;
    int years;
    QFile file3(":/textf/p_clients.txt");
    if (!file3.open(QIODevice::ReadOnly)){
        QMessageBox::information(this, "Warning", file3.errorString());
    } else {
        QTextStream in(&file3);
        while (!in.atEnd()) {
            int cont = 0;
            QString line = in.readLine();
            istringstream iss(line.toStdString());
            do{
                string s;
                iss >> s;
                cont++;
                if (cont == 1){
                    name3 = s;
                } else if (cont == 2){
                    birthday3 = s;
                } else if (cont == 3){
                    gender3 = s;
                } else if (cont == 4){
                    years = atoi(s.c_str());
                }
            } while (iss);
            clients->push_back(new PremiumClient(name3, birthday3, gender3, years));
        }
    }
    file3.close();
}

MainWindow::~MainWindow()
{
    //Corporate
    QFile file("./c_clients.txt");
    if (!file.open(QIODevice::WriteOnly)){
        QMessageBox::information(this, "Warning", file.errorString());
    } else {
        for (unsigned long i = 0; i < clients->size(); i++){
            CoorporateClient* cc = dynamic_cast<CoorporateClient*>(clients->at(i));
            QTextStream out(&file);
            if (cc){
                out << cc->getName().c_str();
                out << " ";
                out << cc->getBirthDay().c_str();
                out << " ";
                out << cc->getGender().c_str();
                out << " ";
                out << cc->getCompany().c_str();
                out << "\n";
            }
        }
    }
    QMessageBox::information(this, "Save", "Successfully Saved");
    file.close();
    //Premium
    QFile file2("./p_clients.txt");
    if (!file2.open(QIODevice::WriteOnly)){
        QMessageBox::information(this, "Warning", file2.errorString());
    } else {
        for (unsigned long i = 0; i < clients->size(); i++){
            PremiumClient* pc = dynamic_cast<PremiumClient*>(clients->at(i));
            QTextStream out(&file2);
            if (pc){
                out << pc->getName().c_str();
                out << " ";
                out << pc->getBirthDay().c_str();
                out << " ";
                out << pc->getGender().c_str();
                out << " ";
                out << pc->getYears();
                out << "\n";
            }
        }
    }
    QMessageBox::information(this, "Save", "Successfully Saved");
    file2.close();
    //Regular
    QFile file3("r_clients.txt");
    if (!file3.open(QIODevice::WriteOnly)){
        QMessageBox::information(this, "Warning", file3.errorString());
    } else {
        for (unsigned long i = 0; i < clients->size(); i++){
            RegularClient* rc = dynamic_cast<RegularClient*>(clients->at(i));
            QTextStream out(&file3);
            if (rc){
                out << rc->getName().c_str();
                out << " ";
                out << rc->getBirthDay().c_str();
                out << " ";
                out << rc->getGender().c_str();
                out << "\n";
            }
        }
    }
    QMessageBox::information(this, "Save", "Successfully Saved");
    file3.close();
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

    Clients c(clients);
    c.exec();
}

void MainWindow::on_pushButton_2_clicked()
{

    if (clients->size() > 0){
        NewBill nb(clients, meals, drinks, bills);
        nb.exec();
    } else {
        QMessageBox::information(this, "Bill" ,"You must create a client before making a bill!");
    }
}
