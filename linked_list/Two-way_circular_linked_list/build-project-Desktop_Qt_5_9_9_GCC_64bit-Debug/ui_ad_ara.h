/********************************************************************************
** Form generated from reading UI file 'ad_ara.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AD_ARA_H
#define UI_AD_ARA_H

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

class Ui_ad_ara
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *ad_ara)
    {
        if (ad_ara->objectName().isEmpty())
            ad_ara->setObjectName(QStringLiteral("ad_ara"));
        ad_ara->resize(603, 501);
        label = new QLabel(ad_ara);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(223, 20, 161, 150));
        label_2 = new QLabel(ad_ara);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(70, 250, 221, 31));
        QFont font;
        font.setPointSize(13);
        font.setItalic(true);
        label_2->setFont(font);
        lineEdit = new QLineEdit(ad_ara);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(310, 250, 191, 31));
        pushButton = new QPushButton(ad_ara);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(210, 360, 181, 31));
        pushButton->setFont(font);
        pushButton_2 = new QPushButton(ad_ara);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(210, 430, 181, 31));
        pushButton_2->setFont(font);

        retranslateUi(ad_ara);

        QMetaObject::connectSlotsByName(ad_ara);
    } // setupUi

    void retranslateUi(QDialog *ad_ara)
    {
        ad_ara->setWindowTitle(QApplication::translate("ad_ara", "Ad ile ki\305\237i ara", Q_NULLPTR));
        label->setText(QString());
        label_2->setText(QApplication::translate("ad_ara", "Aranacak ki\305\237i ad\304\261, soyad\304\261 : ", Q_NULLPTR));
        pushButton->setText(QApplication::translate("ad_ara", "Ki\305\237iyi ara", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("ad_ara", "Ana men\303\274ye d\303\266n", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ad_ara: public Ui_ad_ara {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AD_ARA_H
