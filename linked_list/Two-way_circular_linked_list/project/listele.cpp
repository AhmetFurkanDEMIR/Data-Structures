#include "listele.h"
#include "ui_listele.h"
#include "mainwindow.h"
#include "rehber.h"

Listele::Listele(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Listele)
{

    ui->setupUi(this);
    this->setFixedSize(603, 501);
    this->move(382, 134);

    // hic veri yoksa, hiçbirşey yazdırılmaz
    if(root==NULL)
    {
        return;
    }

    // bu kontrol direk listele butonuna basıldıysa gelinir.
    else if(knt!=5)
    {

        // tüm veri ve telefonlar bu degiskende toplanılır ve ekrana yazdırılır.
        // html biçiminde toplanır.
        dire = "<pre> \n";

        iterator=root;

        int i = 1, j;

        do
        {

            // ad, soyad eklenir
            dire = dire + "<pre>   <span style='color: orange'>"+ std::to_string(i) +". Kişi Adı -> " + iterator->ad_soyad + "</span>";

            j = 1;

            iterator_tel = iterator->next_no;

            do
            {

                // telefon türleri ve telefonlar eklenir
                dire = dire + "<pre> <pre>       <span style='color: turquoise'>"+ std::to_string(j) +". Telefon Numara Türü -> " + iterator_tel->tel_turu + "</span>";
                dire = dire + "<pre>       <span style='color: turquoise'>"+ std::to_string(j) +". Telefon Numarası -> " + iterator_tel->tel + "</span>";

                j+=1;
                iterator_tel = iterator_tel->next_no;

            }
            while(iterator_tel!=iterator->next_no);

            iterator=iterator->next;

            i+=1;

            dire = dire + "<pre> <pre>";

        }
        while(iterator!=root);

    }

    // else if bloğuna girdiyse dire degiskeninde tüm veriler mevcuttur.
    // girmediyse bu fonksiyonu baska bir scriptten çağırılmıs demektir.
    // dire degiskenindeki veriler ekrana yazdırılır.
    QString qstr = QString::fromStdString(dire);
    ui->textBrowser->setText(qstr);
    knt=0;


}

Listele::~Listele()
{
    delete ui;
}

void Listele::on_pushButton_clicked()
{
    MainWindow *dialog = new MainWindow(this);
    connect(dialog, SIGNAL(accepted()), this, SLOT(show()));
    connect(dialog, SIGNAL(rejected()), this, SLOT(show()));
    dialog->show();
    hide();

    return;
}
