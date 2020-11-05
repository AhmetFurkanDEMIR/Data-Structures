/********************************************************************************
** Form generated from reading UI file 'sirali_ekle.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIRALI_EKLE_H
#define UI_SIRALI_EKLE_H

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

class Ui_sirali_ekle
{
public:
    QLabel *label;
    QLabel *label_3;
    QLabel *label_2;
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLabel *label_4;
    QPushButton *pushButton_2;

    void setupUi(QDialog *sirali_ekle)
    {
        if (sirali_ekle->objectName().isEmpty())
            sirali_ekle->setObjectName(QStringLiteral("sirali_ekle"));
        sirali_ekle->resize(603, 501);
        label = new QLabel(sirali_ekle);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(223, 20, 161, 150));
        label_3 = new QLabel(sirali_ekle);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(110, 300, 211, 21));
        QFont font;
        font.setPointSize(13);
        font.setItalic(true);
        label_3->setFont(font);
        label_2 = new QLabel(sirali_ekle);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(110, 220, 211, 21));
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(true);
        font1.setItalic(true);
        font1.setWeight(75);
        label_2->setFont(font1);
        pushButton = new QPushButton(sirali_ekle);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(180, 460, 241, 31));
        pushButton->setFont(font);
        pushButton->setCursor(QCursor(Qt::OpenHandCursor));
        lineEdit = new QLineEdit(sirali_ekle);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(330, 220, 181, 25));
        lineEdit_2 = new QLineEdit(sirali_ekle);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(330, 300, 181, 25));
        lineEdit_3 = new QLineEdit(sirali_ekle);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(330, 350, 181, 25));
        label_4 = new QLabel(sirali_ekle);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(110, 350, 221, 17));
        label_4->setFont(font);
        pushButton_2 = new QPushButton(sirali_ekle);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(170, 410, 261, 31));
        pushButton_2->setFont(font);
        pushButton_2->setCursor(QCursor(Qt::OpenHandCursor));

        retranslateUi(sirali_ekle);

        QMetaObject::connectSlotsByName(sirali_ekle);
    } // setupUi

    void retranslateUi(QDialog *sirali_ekle)
    {
        sirali_ekle->setWindowTitle(QApplication::translate("sirali_ekle", "S\304\261ral\304\261 ki\305\237i ekle", Q_NULLPTR));
        label->setText(QString());
        label_3->setText(QApplication::translate("sirali_ekle", "1. Telefon numara t\303\274r\303\274  : ", Q_NULLPTR));
        label_2->setText(QApplication::translate("sirali_ekle", "Ki\305\237i ad\304\261 ve soyad\304\261 : ", Q_NULLPTR));
        pushButton->setText(QApplication::translate("sirali_ekle", "Ki\305\237iyi kaydet", Q_NULLPTR));
        label_4->setText(QApplication::translate("sirali_ekle", "1. Telefon numaras\304\261       : ", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("sirali_ekle", "Numara eklemeye devam et", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class sirali_ekle: public Ui_sirali_ekle {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIRALI_EKLE_H
