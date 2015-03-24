#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include "client.h"
#include "meal.h"
#include "drink.h"
#include "bill.h"

using std::vector;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_MainWindow_destroyed();

private:
    Ui::MainWindow *ui;
    vector<Client*>* clients;
    vector<Meal*>* meals;
    vector<Drink*>* drinks;
    vector<Bill*>* bills;
};

#endif // MAINWINDOW_H
