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
    meals->push_back(new Meal("Pork Chops", 20, "Onion Sauce"));
    meals->push_back(new Meal("Grilled Chicken", 23, "Chicken Breast"));
    meals->push_back(new Meal("Shrimps", 35, "Garlic/Breaded/Grilled"));
    drinks->push_back(new Alcoholic("Red Wine", 7.50, "Merlot"));
    drinks->push_back(new Alcoholic("Heineken", 3.75, "Beer"));
    drinks->push_back(new NonAlcoholic("Coke", 3.50, "Bottle"));
    drinks->push_back(new NonAlcoholic("Lemonade", 4, ""));
    //Read Clients
    //Regular
    string name;
    string birthday;
    string gender;
    ifstream file;
    file.open("./r_clients.txt");
    string line;
    int cont;
    if (file.is_open()) {
        while (getline(file, line)) {
            cont = 0;
            istringstream iss(line);
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
    file.close();
    //Corporate
    string name2;
    string birthday2;
    string gender2;
    string company;
    ifstream file2;
    file2.open("./c_clients.txt");
    string line2;
    if (file2.is_open()) {
        while (getline(file2, line2)) {
            cont = 0;
            istringstream iss(line2);
            do{
                string s;
                iss >> s;
                cont++;
                if (cont == 1){
                    name2 = s;
                } else if (cont == 2){
                    birthday2 = s;
                } else if (cont == 3){
                    gender2 = s;
                } else if (cont == 4){
                    company = s;
                }
            } while (iss);
            clients->push_back(new CoorporateClient(name2, birthday2, gender2, company));
        }
    }
    file2.close();
    //Premium
    string name3;
    string birthday3;
    string gender3;
    int years;
    ifstream file3;
    file3.open("./p_clients.txt");
    string line3;
    if (file3.is_open()) {
        while (getline(file3, line3)) {
            cont = 0;
            istringstream iss(line3);
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
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

    Clients c(clients);
    c.exec();
}

void MainWindow::on_pushButton_2_clicked()
{

    NewBill nb(clients, meals, drinks, bills);
    nb.exec();
}

void MainWindow::on_MainWindow_destroyed()
{
    //Corporate
    ofstream file;
    file.open("./c_clients.txt");
    if (file.is_open()) {
        for (unsigned long i = 0; i < clients->size(); i++){
            CoorporateClient* cc = dynamic_cast<CoorporateClient*>(clients->at(i));
            if (cc){
                file << cc->getName();
                file << " ";
                file << cc->getBirthDay();
                file << " ";
                file << cc->getGender();
                file << " ";
                file << cc->getCompany();
                file << "\n";
            }
        }
    }
    file.close();
    //Premium
    ofstream file2;
    file2.open("./p_clients.txt");
    if (file2.is_open()) {
        for (unsigned long i = 0; i < clients->size(); i++){
            PremiumClient* pc = dynamic_cast<PremiumClient*>(clients->at(i));
            if (pc){
                file << pc->getName();
                file << " ";
                file << pc->getBirthDay();
                file << " ";
                file << pc->getGender();
                file << " ";
                file << pc->getYears();
                file << "\n";
            }
        }
    }
    file2.close();
    //Regular
    ofstream file3;
    file3.open("./r_clients.txt");
    if (file3.is_open()) {
        for (unsigned long i = 0; i < clients->size(); i++){
            RegularClient* rc = dynamic_cast<RegularClient*>(clients->at(i));
            if (rc){
                file << rc->getName();
                file << " ";
                file << rc->getBirthDay();
                file << " ";
                file << rc->getGender();
                file << "\n";
            }
        }
    }
    file3.close();
}
