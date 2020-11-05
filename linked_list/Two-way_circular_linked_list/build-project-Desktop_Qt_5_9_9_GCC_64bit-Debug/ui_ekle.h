/********************************************************************************
** Form generated from reading UI file 'ekle.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EKLE_H
#define UI_EKLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Ekle
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QLabel *label_4;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *Ekle)
    {
        if (Ekle->objectName().isEmpty())
            Ekle->setObjectName(QStringLiteral("Ekle"));
        Ekle->resize(603, 501);
        label = new QLabel(Ekle);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(223, 20, 161, 150));
        label_2 = new QLabel(Ekle);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(110, 220, 211, 21));
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        label_2->setFont(font);
        lineEdit = new QLineEdit(Ekle);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(330, 220, 181, 25));
        label_3 = new QLabel(Ekle);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(110, 300, 211, 21));
        QFont font1;
        font1.setPointSize(13);
        font1.setItalic(true);
        label_3->setFont(font1);
        lineEdit_2 = new QLineEdit(Ekle);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(330, 300, 181, 25));
        label_4 = new QLabel(Ekle);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(110, 350, 221, 17));
        label_4->setFont(font1);
        lineEdit_3 = new QLineEdit(Ekle);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(330, 350, 181, 25));
        pushButton = new QPushButton(Ekle);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(180, 460, 241, 31));
        pushButton->setFont(font1);
        pushButton->setCursor(QCursor(Qt::OpenHandCursor));
        pushButton_2 = new QPushButton(Ekle);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(170, 410, 261, 31));
        pushButton_2->setFont(font1);
        pushButton_2->setCursor(QCursor(Qt::OpenHandCursor));

        retranslateUi(Ekle);

        QMetaObject::connectSlotsByName(Ekle);
    } // setupUi

    void retranslateUi(QDialog *Ekle)
    {
        Ekle->setWindowTitle(QApplication::translate("Ekle", "   Ki\305\237i Ekle", Q_NULLPTR));
        label->setText(QString());
        label_2->setText(QApplication::translate("Ekle", "Ki\305\237i ad\304\261 ve soyad\304\261 : ", Q_NULLPTR));
        label_3->setText(QApplication::translate("Ekle", "1. Telefon numara t\303\274r\303\274  : ", Q_NULLPTR));
        label_4->setText(QApplication::translate("Ekle", "1. Telefon numaras\304\261       : ", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Ekle", "Ki\305\237iyi kaydet", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Ekle", "Numara eklemeye devam et", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Ekle: public Ui_Ekle {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EKLE_H
