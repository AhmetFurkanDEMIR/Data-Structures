#include "sirali_ekle.h"
#include "ui_sirali_ekle.h"
#include "mainwindow.h"
#include "rehber.h"
#include "QMessageBox"

sirali_ekle::sirali_ekle(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sirali_ekle)
{
    ui->setupUi(this);
    this->setFixedSize(603, 501);
    this->move(382, 134);

    if(knt!=0){
        ui->lineEdit->setText(iterator->ad_soyad);
        ui->lineEdit->setEnabled(false);
    }

    QPixmap pix("/home/demir/Desktop/C - C++ to build/C++/project/pngegg.png");
    ui->label->setPixmap(pix);
}

sirali_ekle::~sirali_ekle()
{
    delete ui;
}


// ekle scriptinden tek farkı, yer_belirle fonksiyonu.
// eger root!=NULL ise yeni veri olusturulurken uygun konum bulunur ve bu verinin adresi return edilir.
node *yer_belirle(char *ara){

    node *temp;

    iterator=root->back;

    // eger eklenen ad soyad root dan büyükse, root yeni veri olarak degistirilir ve return edilir.
    int sn = strcmp(root->ad_soyad, ara), c=0;

    if(sn>=0){

        iterator->next=(node *)malloc(sizeof(node));
        iterator->next->back = iterator;
        iterator->next->next=root;
        root->back=iterator->next;
        root=iterator->next;

        return root;
    }

    iterator=root;

    // sona veya ortalara yeni veri ekleme
    while(1){

        // en sona veri eklenecek, c=1
        if(iterator->next==root){
            c=1;
            break;
        }

        // iterator->next yerine yeni veri ekleyeceğiz
        // eklenen verinin nexti iterator->nexti işaret edecek.
        sn = strcmp(iterator->next->ad_soyad, ara);
        if(sn>=0){

            c=0;
            break;
        }

        iterator=iterator->next;
    }

    // sona veri ekleme
    if(c==1){

        iterator->next=(node *)malloc(sizeof(node));
        iterator->next->back = iterator;
        iterator->next->next=root;
        root->back=iterator->next;

    }

    // c=0 ise ortalarda bir yerde uygun yer buldu demektir.
    else{

        temp = iterator->next;
        iterator->next = (node *)malloc(sizeof(node));
        iterator->next->back = iterator;
        iterator->next->next = temp;
        temp->back = iterator->next;
    }

    return iterator->next;

}

void sirali_ekle::ekle_son(char *str1, char *str2, char *str3){

    // knt=0 ise ilk defa veri ekleme işlemi yapılyor
    if(knt==0){

        // hic veri yok ise root=yeni_veri
        if(root==NULL){

            root = (node *)malloc(sizeof(node));
            root->next = root;
            root->back = root;

            memcpy(root->ad_soyad, str1 ,30);

            root->next_no = (tel *)malloc(sizeof(tel));
            root->next_no->next_no=root->next_no;
            root->next_no->back_no = root->next_no;

            memcpy(root->next_no->tel_turu, str2 ,20);
            memcpy(root->next_no->tel, str3 ,11);

            iterator = root;


        }

        // rot!=NULL ise yer_belirle fonksiyonundan gelen yeni veriye değerler aktarılır
        else{

            char araa[30];

            memcpy(araa, ui->lineEdit->text().toStdString().c_str() ,30);

            iterator = yer_belirle(araa);

            memcpy(iterator->ad_soyad, ui->lineEdit->text().toStdString().c_str() ,30);

            iterator->next_no = (tel *)malloc(sizeof(tel));
            iterator->next_no->next_no=iterator->next_no;
            iterator->next_no->back_no = iterator->next_no;

            memcpy(iterator->next_no->tel_turu, str2 ,20);
            memcpy(iterator->next_no->tel, str3 ,11);

        }
    }

    //knt!=0 yani veri zaten ekli, sadece yeni tel eklenecek
    else{

        iterator_tel = iterator->next_no;
        tela = iterator->next_no;

        while(iterator_tel->next_no!=tela){

            iterator_tel=iterator_tel->next_no;
        }


        iterator_tel->next_no = (tel *)malloc(sizeof(tel));
        iterator_tel->next_no->back_no=iterator_tel;
        iterator_tel->next_no->next_no = tela;
        tela->back_no = iterator_tel->next_no;
        iterator_tel=iterator_tel->next_no;

        memcpy(iterator_tel->tel_turu, str2 ,20);
        memcpy(iterator_tel->tel, str3 ,11);

    }

    knt = 1;

    return;

}

void sirali_ekle::on_pushButton_clicked()
{

    // knt=0 ise ilk defa veri ekleme işlemi yapılyor
    if(knt==0){

        // hic veri yok ise root=yeni_veri
        if(root==NULL){

            root = (node *)malloc(sizeof(node));
            root->next = root;
            root->back = root;

            memcpy(root->ad_soyad, ui->lineEdit->text().toStdString().c_str() ,30);

            root->next_no = (tel *)malloc(sizeof(tel));
            root->next_no->next_no=root->next_no;
            root->next_no->back_no = root->next_no;

            memcpy(root->next_no->tel_turu, ui->lineEdit_2->text().toStdString().c_str() ,20);
            memcpy(root->next_no->tel, ui->lineEdit_3->text().toStdString().c_str() ,11);

            iterator = root;


        }

        // rot!=NULL ise yer_belirle fonksiyonundan gelen yeni veriye değerler aktarılır
        else{

            char araa[30];

            memcpy(araa, ui->lineEdit->text().toStdString().c_str() ,30);

            iterator = yer_belirle(araa);

            memcpy(iterator->ad_soyad, ui->lineEdit->text().toStdString().c_str() ,30);

            iterator->next_no = (tel *)malloc(sizeof(tel));
            iterator->next_no->next_no=iterator->next_no;
            iterator->next_no->back_no = iterator->next_no;

            memcpy(iterator->next_no->tel_turu, ui->lineEdit_2->text().toStdString().c_str() ,20);
            memcpy(iterator->next_no->tel, ui->lineEdit_3->text().toStdString().c_str() ,11);


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

    //knt!=0 yani veri zaten ekli, sadece yeni tel eklenecek ve ana menüye dönülecek
    // kisiyi kaydet butonu tetiklendigi için
    else{

        iterator_tel = iterator->next_no;
        tela = iterator->next_no;

        while(iterator_tel->next_no!=tela){

            iterator_tel=iterator_tel->next_no;
        }

        iterator_tel->next_no = (tel *)malloc(sizeof(tel));
        iterator_tel->next_no->back_no=iterator_tel;
        iterator_tel->next_no->next_no = tela;
        tela->back_no = iterator_tel->next_no;
        iterator_tel=iterator_tel->next_no;

        memcpy(iterator_tel->tel_turu, ui->lineEdit_2->text().toStdString().c_str() ,20);
        memcpy(iterator_tel->tel, ui->lineEdit_3->text().toStdString().c_str() ,11);

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

void sirali_ekle::on_pushButton_2_clicked()
{
    char add[30];
    char tel_turuu[20];
    char tell[11];

    memcpy(add, ui->lineEdit->text().toStdString().c_str() ,30);
    memcpy(tel_turuu, ui->lineEdit_2->text().toStdString().c_str() ,20);
    memcpy(tell, ui->lineEdit_3->text().toStdString().c_str() ,11);

    ekle_son(add, tel_turuu, tell);

    sirali_ekle *dialog = new sirali_ekle(this);
    connect(dialog, SIGNAL(accepted()), this, SLOT(show()));
    connect(dialog, SIGNAL(rejected()), this, SLOT(show()));
    dialog->show();
    hide();
    return;
}
