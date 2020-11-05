#include "tel_ara.h"
#include "ui_tel_ara.h"
#include "mainwindow.h"
#include "listele.h"
#include "rehber.h"
#include "QMessageBox"

tel_ara::tel_ara(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tel_ara)
{
    ui->setupUi(this);
    this->setFixedSize(603, 501);
    this->move(382, 134);

    QPixmap pix("/home/demir/Desktop/C - C++ to build/C++/project/pngegg.png");
    ui->label->setPixmap(pix);
}

tel_ara::~tel_ara()
{
    delete ui;
}

void tel_ara::on_pushButton_2_clicked()
{
    MainWindow *dialog = new MainWindow(this);
    connect(dialog, SIGNAL(accepted()), this, SLOT(show()));
    connect(dialog, SIGNAL(rejected()), this, SLOT(show()));
    dialog->show();
    hide();

    return;
}

void tel_ara::on_pushButton_clicked()
{
    // veri yok ise
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


    // arancak kelime
    char ara[30];
    dire = "<pre> \n";

    memcpy(ara, ui->lineEdit->text().toStdString().c_str(),30);

    int kntrl=0, byt, i=0, z=0, a=0, j=1,k=0;

    // aranacak kelime boyutu
    while(*(ara+i)!='\0')
    {

        i+=1;
    }

    // boyut
    byt = i;

    iterator=root;

    // itrator!=root
    do
    {

        // telefona göre arama islemi
        tela = iterator->next_no;
        iterator_tel = iterator->next_no;

        // iterator_tel!=tela
        do
        {

            // dogru veri icin kontol degiskeni
            a=0;

            // istenilen kelime telin icinde varmı diye kontrol ettim.
            // var ise a=1
            for(i=0; i<=byt-1; ++i)
            {

                if(*(iterator_tel->tel+i)==*(ara+i))
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

            if(a==1)
            {
                break;
            }

            iterator_tel=iterator_tel->back_no;

        }
        while(iterator_tel!=tela);


        // a=1 ise veri bulunmustur ve ekrana yazdırılmak için hazırlanılır.
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

    // listele scriptine ilerlenir.
    if(kntrl==1)
    {

        knt = 5;

        Listele *dialog = new Listele(this);
        connect(dialog, SIGNAL(accepted()), this, SLOT(show()));
        connect(dialog, SIGNAL(rejected()), this, SLOT(show()));
        dialog->show();
        hide();

    }

    // veri bulunamadı
    else
    {

        QMessageBox::information(this, "Başarısız", "Kişi bulunamadı");
    }

}
