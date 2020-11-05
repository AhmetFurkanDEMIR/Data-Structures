#include "ad_ara.h"
#include "ui_ad_ara.h"
#include "mainwindow.h"
#include "rehber.h"
#include "listele.h"
#include "QMessageBox"

ad_ara::ad_ara(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ad_ara)
{
    ui->setupUi(this);
    this->setFixedSize(603, 501);
    this->move(382, 134);

    QPixmap pix("/home/demir/Desktop/C - C++ to build/C++/project/pngegg.png");
    ui->label->setPixmap(pix);

}

ad_ara::~ad_ara()
{
    delete ui;
}

void ad_ara::on_pushButton_2_clicked()
{
    MainWindow *dialog = new MainWindow(this); //ERROR: no matching constructor for initialization of 'Dialog'
    connect(dialog, SIGNAL(accepted()), this, SLOT(show()));
    connect(dialog, SIGNAL(rejected()), this, SLOT(show()));
    dialog->show();
    hide();
}

void ad_ara::on_pushButton_clicked()
{

    // kişi yoksa
    if(root==NULL)
    {

        QMessageBox::information(this, "Başarısız", "Kişi listesi boş.");

        MainWindow *dialog = new MainWindow(this);
        connect(dialog, SIGNAL(accepted()), this, SLOT(show()));
        connect(dialog, SIGNAL(rejected()), this, SLOT(show()));
        dialog->show();
        hide();

        return;
    }

    // aranacak kelime
    char ara[30];
    memcpy(ara, ui->lineEdit->text().toStdString().c_str(),30);

    dire = "<pre> \n";

    int kntrl=0, byt, i=0, z=0, a=0, j=1,k=0;

    // aranacak kelime uzunluğu
    while(*(ara+i)!='\0')
    {

        i+=1;
    }

    // uzunluk
    byt = i;

    iterator=root;

    // iterator!=root
    do
    {
        a=0;

        // aranan kelimenin adın içinde olup olmaması kontrolü
        for(i=0; i<=byt-1; ++i)
        {

            if(*(iterator->ad_soyad+i)==*(ara+i))
            {
                z+=1;
            }

            else
            {

                z=0;
                break;
            }

            if(z==byt)
            {
                a=1;
                kntrl=1;
                z=0;
                break;
            }

        }

        // eğer kelime adın içinde varsa bu bloğa girer
        if(a==1)
        {

            dire = dire + "<pre>   <span style='color: orange'>"+ std::to_string(j) +". Kişi Adı -> " + iterator->ad_soyad + "</span>";

            k=1;
            j+=1;

            tela = iterator->next_no;
            iterator_tel = iterator->next_no;

            do
            {

                dire = dire + "<pre> <pre>       <span style='color: turquoise'>"+ std::to_string(k) +". Telefon Numara Türü -> " + iterator_tel->tel_turu + "</span>";
                dire = dire + "<pre>       <span style='color: turquoise'>"+ std::to_string(k) +". Telefon Numarası -> " + iterator_tel->tel + "</span>";

                iterator_tel = iterator_tel->back_no;
                k+=1;

            }
            while(iterator_tel!=tela);

            dire = dire + "<pre> <pre>";

        }

        iterator=iterator->back;

    }
    while(iterator!=root);


    // kişi bulunduysa listele scriptine ilerlenir ve "dire" adlı değişken ekrana yazdırılır
    if(kntrl==1)
    {

        // listele scriptinde kontrol edilecek degisken
        knt = 5;
        Listele *dialog = new Listele(this);
        connect(dialog, SIGNAL(accepted()), this, SLOT(show()));
        connect(dialog, SIGNAL(rejected()), this, SLOT(show()));
        dialog->show();
        hide();

    }

    // kişi bulunamazsa
    else
    {

        QMessageBox::information(this, "Başarısız", "Kişi bulunamadı");
    }

}
