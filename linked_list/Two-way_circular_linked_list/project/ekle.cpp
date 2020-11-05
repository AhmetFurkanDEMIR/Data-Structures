#include "ekle.h"
#include "ui_ekle.h"
#include "mainwindow.h"
#include "rehber.h"
#include "QMessageBox"

Ekle::Ekle(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ekle)
{
    ui->setupUi(this);
    this->setFixedSize(603, 501);
    this->move(382, 134);

    if(knt!=0)
    {
        ui->lineEdit->setText(iterator->ad_soyad);
        ui->lineEdit->setEnabled(false);
    }

    QPixmap pix("/home/demir/Desktop/C - C++ to build/C++/project/pngegg.png");
    ui->label->setPixmap(pix);

}

Ekle::~Ekle()
{
    delete ui;
}

void Ekle::ekle_son(char *str1, char *str2, char *str3)
{

    // knt=0 ise yeni bir veri(kişi) oluşturulucak demektir.
    // bir kişi ve bir telefon numarası kaydedilir.
    if(knt==0)
    {

        // hiçbir veri yoksa yeni bir veri oluşturulur ve roota atanır.
        // dairesel çift yönlü bağlı liste olduğu için, nexti ve backı kendisini işaret edecektir.
        if(root==NULL)
        {

            root = (node *)malloc(sizeof(node));
            root->next = root;
            root->back = root;

            memcpy(root->ad_soyad, str1,30);

            root->next_no = (tel *)malloc(sizeof(tel));
            root->next_no->next_no=root->next_no;
            root->next_no->back_no = root->next_no;

            memcpy(root->next_no->tel_turu, str2,20);
            memcpy(root->next_no->tel, str3,11);

            iterator = root;


        }

        // eğer veri(kişi) varsa sondan yeni bir veri eklenir
        else
        {

            // son eleman
            iterator = root->back;

            // yeni eleman eklemek
            iterator->next = (node *)malloc(sizeof(node));
            iterator->next->back=iterator;
            iterator->next->next = root;
            root->back = iterator->next;
            iterator=iterator->next;

            memcpy(iterator->ad_soyad, str1,30);

            iterator->next_no = (tel *)malloc(sizeof(tel));
            iterator->next_no->next_no=iterator->next_no;
            iterator->next_no->back_no = iterator->next_no;

            memcpy(iterator->next_no->tel_turu, str2,20);
            memcpy(iterator->next_no->tel, str3,11);

        }
    }

    // knt!=0 ise yeni bir veri eklenmeyecek demektir
    // sadece, oluşturulan kişiye yeni tel eklenecektir.
    else
    {

        // son telefon
        iterator_tel = iterator->next_no->back_no;

        // ilk telefon
        tela = iterator->next_no;

        // yeni telefon oluşturup değer atamak
        iterator_tel->next_no = (tel *)malloc(sizeof(tel));
        iterator_tel->next_no->back_no=iterator_tel;
        iterator_tel->next_no->next_no = tela;
        tela->back_no = iterator_tel->next_no;
        iterator_tel=iterator_tel->next_no;

        memcpy(iterator_tel->tel_turu, str2,20);
        memcpy(iterator_tel->tel, str3,11);

    }

    // knt=1, ilk veri olstuktan sonra yeni veri oluşturmak yerine tel ekleme işlemi yapmamızı saglayan degisken
    knt = 1;

    return;

}


void Ekle::on_pushButton_clicked()
{

    // knt=0, yeni birey oluşturmak
    if(knt==0)
    {

        if(root==NULL)
        {

            root = (node *)malloc(sizeof(node));
            root->next = root;
            root->back = root;

            memcpy(root->ad_soyad, ui->lineEdit->text().toStdString().c_str(),30);

            root->next_no = (tel *)malloc(sizeof(tel));
            root->next_no->next_no=root->next_no;
            root->next_no->back_no = root->next_no;

            memcpy(root->next_no->tel_turu, ui->lineEdit_2->text().toStdString().c_str(),20);
            memcpy(root->next_no->tel, ui->lineEdit_3->text().toStdString().c_str(),11);

            iterator = root;


        }

        else
        {

            iterator = root->back;

            iterator->next = (node *)malloc(sizeof(node));
            iterator->next->back=iterator;
            iterator->next->next = root;
            root->back = iterator->next;
            iterator=iterator->next;

            memcpy(iterator->ad_soyad, ui->lineEdit->text().toStdString().c_str(),30);

            iterator->next_no = (tel *)malloc(sizeof(tel));
            iterator->next_no->next_no=iterator->next_no;
            iterator->next_no->back_no = iterator->next_no;

            memcpy(iterator->next_no->tel_turu, ui->lineEdit_2->text().toStdString().c_str(),20);
            memcpy(iterator->next_no->tel, ui->lineEdit_3->text().toStdString().c_str(),11);


        }

        QMessageBox::information(this, "Başarılı", "Kişi Ekleme Başarılı.");

        knt = 0;
        MainWindow *dialog = new MainWindow(this);
        connect(dialog, SIGNAL(accepted()), this, SLOT(show()));
        connect(dialog, SIGNAL(rejected()), this, SLOT(show()));
        dialog->show();
        hide();
        return;

    }

    // knt!=0 ise veri oluşturulmuş demektir, sadece tel güncellemesi yapacağız
    else
    {

        iterator_tel = iterator->next_no->back_no;
        tela = iterator->next_no;

        iterator_tel->next_no = (tel *)malloc(sizeof(tel));
        iterator_tel->next_no->back_no=iterator_tel;
        iterator_tel->next_no->next_no = tela;
        tela->back_no = iterator_tel->next_no;
        iterator_tel=iterator_tel->next_no;

        memcpy(iterator_tel->tel_turu, ui->lineEdit_2->text().toStdString().c_str(),20);
        memcpy(iterator_tel->tel, ui->lineEdit_3->text().toStdString().c_str(),11);

        QMessageBox::information(this, "Başarılı", "Kişi Ekleme Başarılı.");

        knt = 0;
        MainWindow *dialog = new MainWindow(this);
        connect(dialog, SIGNAL(accepted()), this, SLOT(show()));
        connect(dialog, SIGNAL(rejected()), this, SLOT(show()));
        dialog->show();
        hide();

        return;

    }

}

void Ekle::on_pushButton_2_clicked()
{

    char add[30];
    char tel_turuu[20];
    char tell[11];

    memcpy(add, ui->lineEdit->text().toStdString().c_str(),30);
    memcpy(tel_turuu, ui->lineEdit_2->text().toStdString().c_str(),20);
    memcpy(tell, ui->lineEdit_3->text().toStdString().c_str(),11);

    ekle_son(add, tel_turuu, tell);

    Ekle *dialog = new Ekle(this);
    connect(dialog, SIGNAL(accepted()), this, SLOT(show()));
    connect(dialog, SIGNAL(rejected()), this, SLOT(show()));
    dialog->show();
    hide();
    return;

}
