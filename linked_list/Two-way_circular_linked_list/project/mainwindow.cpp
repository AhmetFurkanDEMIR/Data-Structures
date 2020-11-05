#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ekle.h"
#include "listele.h"
#include "ad_ara.h"
#include "tel_ara.h"
#include "sirali_ekle.h"
#include "sil.h"
#include "rehber.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(603, 501);
    this->move(382, 134);

    QPixmap pix("/home/demir/Desktop/C - C++ to build/C++/project/pngegg.png");
    ui->label->setPixmap(pix);

}

MainWindow::~MainWindow()
{
    delete ui;
}

// kisi ekleme butonu tetiklenince
void MainWindow::on_pushButton_clicked()
{

    // ekle classından yeni bir obje yaratıyoruz.
    // ve bu obje ekrana yansıtılıp, mainwindow adlı objeyi gizliyoruz(kapatıyoruz).
    Ekle *dialog = new Ekle(this);
    connect(dialog, SIGNAL(accepted()), this, SLOT(show()));
    connect(dialog, SIGNAL(rejected()), this, SLOT(show()));
    dialog->show();
    hide();

    return;

}

// kisi listele butonu tetiklenince
void MainWindow::on_pushButton_3_clicked()
{

    Listele *dialog = new Listele(this);
    connect(dialog, SIGNAL(accepted()), this, SLOT(show()));
    connect(dialog, SIGNAL(rejected()), this, SLOT(show()));
    dialog->show();
    hide();

    return;

}

// verileri sıralamada büyük veri ile küçük verinin içeriğini değistirdiğim fonk.
void swap(node *a, node *b)
{

    char temp_ad_soyad[30];
    strcpy(temp_ad_soyad, a->ad_soyad);
    strcpy(a->ad_soyad, b->ad_soyad);
    strcpy(b->ad_soyad, temp_ad_soyad);

    tela = a->next_no;
    a->next_no = b->next_no;
    b->next_no = tela;

}

// sıralama fonksiyonu, sıralı ekle ve sıralı liste scriptlerine ilerlenmeden bu fonk. ugranır.
void sirala()
{

    // veri yok ise, sıralamma işlemine de gerek yoktur.
    if(root==NULL)
    {
        return;
    }

    // veri degis tokusu oldumu diye kontrol degiskeni
    int swapped;

    // i
    do
    {
        swapped = 0;
        iterator = root;

        // j
        do
        {

            // eger iterator sonraki elemandan kucukse veriler yer degistirilir.
            // yani iterator->next, iteratorun yerine gecer.
            if(strcmp(iterator->ad_soyad, iterator->next->ad_soyad)>0)
            {
                // degistirme islemi
                swap(iterator, iterator->next);

                // eger degistirme islemi olduysa, döngü tekrardan tekrarlanır.
                // degistirme olmadıysa, demekki sıralamda bir problem yoktur ve döngü kesilir.
                swapped = 1;
            }

            iterator = iterator->next;

        }
        while(iterator->next!=root);

    }
    while(swapped);

}

// sirali listele butonu tetiklenince
void MainWindow::on_pushButton_4_clicked()
{
    // siralama islemi
    sirala();

    // listele
    Listele *dialog = new Listele(this);
    connect(dialog, SIGNAL(accepted()), this, SLOT(show()));
    connect(dialog, SIGNAL(rejected()), this, SLOT(show()));
    dialog->show();
    hide();

    return;

}

// sirali ekle butonu tetiklenince
void MainWindow::on_pushButton_2_clicked()
{

    // siralama
    sirala();

    // sirali ekleme
    sirali_ekle *dialog = new sirali_ekle(this);
    connect(dialog, SIGNAL(accepted()), this, SLOT(show()));
    connect(dialog, SIGNAL(rejected()), this, SLOT(show()));
    dialog->show();
    hide();

    return;

}

// ara(ad) butonu tetiklenince
void MainWindow::on_pushButton_5_clicked()
{
    ad_ara *dialog = new ad_ara(this);
    connect(dialog, SIGNAL(accepted()), this, SLOT(show()));
    connect(dialog, SIGNAL(rejected()), this, SLOT(show()));
    dialog->show();
    hide();

    return;

}

// ara(tel) butonu tetiklenince
void MainWindow::on_pushButton_6_clicked()
{
    tel_ara *dialog = new tel_ara(this);
    connect(dialog, SIGNAL(accepted()), this, SLOT(show()));
    connect(dialog, SIGNAL(rejected()), this, SLOT(show()));
    dialog->show();
    hide();

    return;
}

// sil butonu tetiklenince
void MainWindow::on_pushButton_7_clicked()
{

    sil *dialog = new sil(this);
    connect(dialog, SIGNAL(accepted()), this, SLOT(show()));
    connect(dialog, SIGNAL(rejected()), this, SLOT(show()));
    dialog->show();
    hide();

    return;

}
