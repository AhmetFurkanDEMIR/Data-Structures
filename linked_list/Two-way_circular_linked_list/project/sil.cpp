#include "sil.h"
#include "ui_sil.h"
#include "mainwindow.h"
#include "rehber.h"
#include "QMessageBox"

sil::sil(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sil)
{
    ui->setupUi(this);
    this->setFixedSize(603, 501);
    this->move(382, 134);

    QPixmap pix("/home/demir/Desktop/C - C++ to build/C++/project/pngegg.png");
    ui->label->setPixmap(pix);
}

sil::~sil()
{
    delete ui;
}

void sil::on_pushButton_2_clicked()
{
    // veri yok ise
    if(root==NULL){

        QMessageBox::information(this, "Başarısız", "Kişi listesi boş.");

        MainWindow *dialog = new MainWindow(this);
        connect(dialog, SIGNAL(accepted()), this, SLOT(show()));
        connect(dialog, SIGNAL(rejected()), this, SLOT(show()));
        dialog->show();
        hide();

        return;
    }

    // onaylama işlemi gercekleştiyse bu bloktan devam eder
    if(ui->checkBox->isChecked()){

        // kisi silindiyse mesaj vermek amaçlı kontrol degiskeni
        int asd=0;

        //silinecek ad,soyad
        char sil_ad[30];

        memcpy(sil_ad, ui->lineEdit->text().toStdString().c_str() ,30);

        // eğer 1 veri varsa ve bu da silinecek ada sahipse, veri silinir ve return edilir.
        if(root->next==root && strcmp(root->ad_soyad,sil_ad)==0){

            free(root);
            root=NULL;
            asd=1;

            QMessageBox::information(this, "Başarılı", "Kişi Silme Başarılı.");

            MainWindow *dialog = new MainWindow(this);
            connect(dialog, SIGNAL(accepted()), this, SLOT(show()));
            connect(dialog, SIGNAL(rejected()), this, SLOT(show()));
            dialog->show();
            hide();

            return;

        }

        node *temp = root;

        iterator=root;

        // son eleman
        iterator=iterator->back;

        // silinecek ada sahip olan bastaki herkezi silmeye yarar
        // yani, "a,a,a,a,b" "a" ların hepsi silinir ve "b" kalır.
        while(strcmp(temp->ad_soyad,sil_ad)==0){

            iterator->next=root->next;
            root = root->next;
            root->back=iterator;
            free(temp);
            temp = root;

            asd=1;

            // son eleman da "a" ise "a" da silinir ve return edilir.
            if(temp->next==root){

                if(strcmp(temp->ad_soyad,sil_ad)==0){

                    free(root);
                    root=NULL;

                    asd=1;

                }

                QMessageBox::information(this, "Başarılı", "Kişi Silme Başarılı.");

                MainWindow *dialog = new MainWindow(this);
                connect(dialog, SIGNAL(accepted()), this, SLOT(show()));
                connect(dialog, SIGNAL(rejected()), this, SLOT(show()));
                dialog->show();
                hide();

                return;


            }
        }


        // ortadaki ve sondaki verilerden silinecek ada sahip olan herkez silinir.
        while(1){

            // silinecek kisiye kadar ilerlenir.
            while(strcmp(temp->ad_soyad,sil_ad)!=0){

                temp = temp->next;

                // döngü sonu
                if(temp==root){
                    break;
                }

            }

            // son elemana gelindi kodumuz bulabildiği tüm elemanları silmiş demektir.
            if (temp == root){

                // herhangi bir silme işleminde mesaj
                if(asd==1){

                    QMessageBox::information(this, "Başarılı", "Kişi Silme Başarılı.");

                    MainWindow *dialog = new MainWindow(this);
                    connect(dialog, SIGNAL(accepted()), this, SLOT(show()));
                    connect(dialog, SIGNAL(rejected()), this, SLOT(show()));
                    dialog->show();
                    hide();

                    return;

                    }

                // silme işlemi gerçekleşmediyse mesaj
                else{

                    QMessageBox::information(this, "Başarısız", "Kişi Bulunamadı.");

                    MainWindow *dialog = new MainWindow(this);
                    connect(dialog, SIGNAL(accepted()), this, SLOT(show()));
                    connect(dialog, SIGNAL(rejected()), this, SLOT(show()));
                    dialog->show();
                    hide();

                    return;

                }
            }

            // ortada veya sonda silinecek eleman bulundu demektir.
            temp->back->next = temp->next;
            temp->next->back = temp->back;
            free(temp);
            temp = temp->back->next;

            asd=1;

       }

}

    else{

        QMessageBox::information(this, "Başarısız", "Lütfen onaylama işlemini gerçekleştiriniz.");

    }

}

void sil::on_pushButton_clicked()
{

    MainWindow *dialog = new MainWindow(this);
    connect(dialog, SIGNAL(accepted()), this, SLOT(show()));
    connect(dialog, SIGNAL(rejected()), this, SLOT(show()));
    dialog->show();
    hide();

    return;

}
