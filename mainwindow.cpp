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

using std::vector;
using std::string;
using std::ifstream;
using std::istringstream;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    clients = new vector<Client*>();
    meals = new vector<Meal*>();
    drinks = new vector<Drink*>();
    bills = new vector<Bill*>();
    //Read Clients
    //Regular
    string name;
    string birthday;
    string gender;
    ifstream file;
    file.open("r_clients.txt");
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
    file2.open("c_clients.txt");
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
    file3.open("p_clients.txt");
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
    //Read Meals
    string name4;
    double price;
    string description;
    ifstream file4;
    file4.open("meals.txt");
    string line4;
    if (file4.is_open()) {
        while (getline(file4, line4)) {
            cont = 0;
            istringstream iss(line4);
            do{
                string s;
                iss >> s;
                cont++;
                if (cont == 1){
                    name4 = s;
                } else if (cont == 2){
                    price = atof(s.c_str());
                } else if (cont == 3){
                    description = s;
                }
            } while (iss);
            meals->push_back(new Meal(name4, price, description));
        }
    }
    file4.close();
    //Read Drinks
    //Alcoholic
    string name5;
    double price2;
    string description2;
    ifstream file5;
    file5.open("alcoholic_drinks.txt");
    string line5;
    if (file5.is_open()) {
        while (getline(file5, line5)) {
            cont = 0;
            istringstream iss(line5);
            do{
                string s;
                iss >> s;
                cont++;
                if (cont == 1){
                    name5 = s;
                } else if (cont == 2){
                    price2 = atof(s.c_str());
                } else if (cont == 3){
                    description2 = s;
                }
            } while (iss);
            drinks->push_back(new Alcoholic(name5, price2, description2));
        }
    }
    file5.close();
    //Non Alcoholic
    string name6;
    double price3;
    string description3;
    ifstream file6;
    file6.open("nonalcoholic_drinks.txt");
    string line6;
    if (file6.is_open()) {
        while (getline(file6, line6)) {
            cont = 0;
            istringstream iss(line6);
            do{
                string s;
                iss >> s;
                cont++;
                if (cont == 1){
                    name6 = s;
                } else if (cont == 2){
                    price3 = atof(s.c_str());
                } else if (cont == 3){
                    description3 = s;
                }
            } while (iss);
            drinks->push_back(new NonAlcoholic(name6, price3, description3));
        }
    }
    file6.close();
    //Read Bills

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
