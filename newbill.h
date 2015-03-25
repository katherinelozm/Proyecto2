#ifndef NEWBILL_H
#define NEWBILL_H

#include <QDialog>
#include <vector>
#include "meal.h"
#include "drink.h"
#include "client.h"
#include "bill.h"

using std::vector;

namespace Ui {
class NewBill;
}

class NewBill : public QDialog
{
    Q_OBJECT

public:
    explicit NewBill(vector<Client*>*, vector<Meal*>*, vector<Drink*>*, vector<Bill*>*,  QWidget *parent = 0);
    ~NewBill();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();


private:
    Ui::NewBill *ui;
    vector<Client*>* clients;
    vector<Meal*>* meals;
    vector<Drink*>* drinks;
    vector<Bill*>* bills;
};

#endif // NEWBILL_H
