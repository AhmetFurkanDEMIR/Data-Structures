#ifndef KISI_EKLE_H
#define KISI_EKLE_H

#include <QDialog>

namespace Ui
{
class kisi_ekle;
}

class kisi_ekle : public QDialog
{
    Q_OBJECT

public:
    explicit kisi_ekle(QWidget *parent = nullptr);
    ~kisi_ekle();

private:
    Ui::kisi_ekle *ui;
};

#endif // KISI_EKLE_H
