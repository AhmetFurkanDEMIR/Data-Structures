#include "mainwindow.h"
#include "QApplication"
#include "rehber.h"

tel * iterator_tel, * tela;
node * root, * iterator;
int knt = 0;
std::string dire = "";

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
