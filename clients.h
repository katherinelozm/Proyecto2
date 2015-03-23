#ifndef CLIENTS_H
#define CLIENTS_H

#include <QDialog>

namespace Ui {
class Clients;
}

class Clients : public QDialog
{
    Q_OBJECT

public:
    explicit Clients(QWidget *parent = 0);
    ~Clients();

private:
    Ui::Clients *ui;
};

#endif // CLIENTS_H
