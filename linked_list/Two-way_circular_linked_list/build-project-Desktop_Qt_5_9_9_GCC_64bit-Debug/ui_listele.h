/********************************************************************************
** Form generated from reading UI file 'listele.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LISTELE_H
#define UI_LISTELE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_Listele
{
public:
    QTextBrowser *textBrowser;
    QPushButton *pushButton;

    void setupUi(QDialog *Listele)
    {
        if (Listele->objectName().isEmpty())
            Listele->setObjectName(QStringLiteral("Listele"));
        Listele->resize(603, 501);
        textBrowser = new QTextBrowser(Listele);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(2, 2, 599, 431));
        QFont font;
        font.setFamily(QStringLiteral("DejaVu Sans"));
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        textBrowser->setFont(font);
        pushButton = new QPushButton(Listele);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(400, 450, 191, 41));
        QFont font1;
        font1.setPointSize(15);
        font1.setItalic(true);
        pushButton->setFont(font1);
        pushButton->setCursor(QCursor(Qt::OpenHandCursor));

        retranslateUi(Listele);

        QMetaObject::connectSlotsByName(Listele);
    } // setupUi

    void retranslateUi(QDialog *Listele)
    {
        Listele->setWindowTitle(QApplication::translate("Listele", "Listele", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Listele", "Ana Men\303\274ye D\303\266n", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Listele: public Ui_Listele {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTELE_H
