#ifndef DELETECLIENT_H
#define DELETECLIENT_H

#include <QDialog>

namespace Ui {
class DeleteClient;
}

class DeleteClient : public QDialog
{
    Q_OBJECT

public:
    explicit DeleteClient(QWidget *parent = 0);
    ~DeleteClient();

private:
    Ui::DeleteClient *ui;
};

#endif // DELETECLIENT_H
