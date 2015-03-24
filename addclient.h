#ifndef ADDCLIENT_H
#define ADDCLIENT_H

#include <QDialog>
#include <vector>
#include "client.h"

using std::vector;

namespace Ui {
class AddClient;
}

class AddClient : public QDialog
{
    Q_OBJECT

public:
    explicit AddClient(vector<Client*>* ,QWidget *parent = 0);
    ~AddClient();

private slots:
    void on_pushButton_clicked();

    void on_cb_type_currentIndexChanged(int index);

private:
    Ui::AddClient *ui;
    vector<Client*>* clients;
};

#endif // ADDCLIENT_H
