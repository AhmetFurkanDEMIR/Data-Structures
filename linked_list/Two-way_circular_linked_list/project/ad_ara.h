#ifndef AD_ARA_H
#define AD_ARA_H

#include <QDialog>

namespace Ui
{
class ad_ara;
}

class ad_ara : public QDialog
{
    Q_OBJECT

public:
    explicit ad_ara(QWidget *parent = nullptr);
    ~ad_ara();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::ad_ara *ui;
};

#endif // AD_ARA_H
