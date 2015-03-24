#ifndef EDITCLIENT_H
#define EDITCLIENT_H

#include <QDialog>
#include <vector>
#include "client.h"

using std::vector;

namespace Ui {
class EditClient;
}

class EditClient : public QDialog
{
    Q_OBJECT

public:
    explicit EditClient(vector<Client*>*, QWidget *parent = 0);
    ~EditClient();

private slots:
    void on_pushButton_clicked();

    void on_cb_client_currentIndexChanged(int index);

private:
    Ui::EditClient *ui;
    vector<Client*>* clients;
};

#endif // EDITCLIENT_H
