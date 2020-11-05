#include "Kisi_ekle.h"
#include "ui_kisi_ekle.h"

kisi_ekle::kisi_ekle(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::kisi_ekle)
{
    ui->setupUi(this);
}

kisi_ekle::~kisi_ekle()
{
    delete ui;
}
