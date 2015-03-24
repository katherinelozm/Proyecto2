#ifndef CLIENTS_H
#define CLIENTS_H

#include <QDialog>
#include <vector>
#include "client.h"

using std::vector;

namespace Ui {
class Clients;
}

class Clients : public QDialog
{
    Q_OBJECT

public:
    explicit Clients(vector<Client*>*, QWidget *parent = 0);
    ~Clients();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Clients *ui;
    vector<Client*>* clients;
};

#endif // CLIENTS_H
