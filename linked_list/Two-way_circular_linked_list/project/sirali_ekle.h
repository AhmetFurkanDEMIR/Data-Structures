#ifndef SIRALI_EKLE_H
#define SIRALI_EKLE_H

#include <QDialog>

namespace Ui {
class sirali_ekle;
}

class sirali_ekle : public QDialog
{
    Q_OBJECT

public:
    explicit sirali_ekle(QWidget *parent = nullptr);
    ~sirali_ekle();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void ekle_son(char *str1, char *str2, char *str3);

private:
    Ui::sirali_ekle *ui;
};

#endif // SIRALI_EKLE_H
