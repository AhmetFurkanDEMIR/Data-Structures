#ifndef LISTELE_H
#define LISTELE_H

#include <QDialog>

namespace Ui
{
class Listele;
}

class Listele : public QDialog
{
    Q_OBJECT

public:
    explicit Listele(QWidget *parent = nullptr);
    ~Listele();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Listele *ui;
};

#endif // LISTELE_H
