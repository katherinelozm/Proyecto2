#ifndef NEWBILL_H
#define NEWBILL_H

#include <QDialog>

namespace Ui {
class NewBill;
}

class NewBill : public QDialog
{
    Q_OBJECT

public:
    explicit NewBill(QWidget *parent = 0);
    ~NewBill();

private:
    Ui::NewBill *ui;
};

#endif // NEWBILL_H
