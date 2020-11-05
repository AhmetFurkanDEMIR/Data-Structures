#ifndef EKLE_H
#define EKLE_H

#include <QDialog>

namespace Ui
{
class Ekle;
}

class Ekle : public QDialog
{
    Q_OBJECT

public:
    explicit Ekle(QWidget *parent = nullptr);
    ~Ekle();

private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void ekle_son(char *str1, char *str2, char *str3);

private:
    Ui::Ekle *ui;
};

#endif // EKLE_H
