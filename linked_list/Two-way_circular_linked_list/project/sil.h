#ifndef SIL_H
#define SIL_H

#include <QDialog>

namespace Ui {
class sil;
}

class sil : public QDialog
{
    Q_OBJECT

public:
    explicit sil(QWidget *parent = nullptr);
    ~sil();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::sil *ui;
};

#endif // SIL_H
