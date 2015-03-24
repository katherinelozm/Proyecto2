#ifndef DELETECLIENT_H
#define DELETECLIENT_H

#include <QDialog>
#include <vector>
#include "client.h"

using std::vector;

namespace Ui {
class DeleteClient;
}

class DeleteClient : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteClient(vector<Client*>*, QWidget *parent = 0);
    ~DeleteClient();

private slots:
    void on_pushButton_clicked();

private:
    Ui::DeleteClient *ui;
    vector<Client*>* clients;
};

#endif // DELETECLIENT_H
