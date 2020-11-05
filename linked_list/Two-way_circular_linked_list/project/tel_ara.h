#ifndef TEL_ARA_H
#define TEL_ARA_H

#include <QDialog>

namespace Ui {
class tel_ara;
}

class tel_ara : public QDialog
{
    Q_OBJECT

public:
    explicit tel_ara(QWidget *parent = nullptr);
    ~tel_ara();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::tel_ara *ui;
};

#endif // TEL_ARA_H
