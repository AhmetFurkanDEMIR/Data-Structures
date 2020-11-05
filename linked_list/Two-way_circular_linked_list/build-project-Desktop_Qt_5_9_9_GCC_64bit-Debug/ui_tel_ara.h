/********************************************************************************
** Form generated from reading UI file 'tel_ara.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEL_ARA_H
#define UI_TEL_ARA_H

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

class Ui_tel_ara
{
public:
    QPushButton *pushButton_2;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QLabel *label;

    void setupUi(QDialog *tel_ara)
    {
        if (tel_ara->objectName().isEmpty())
            tel_ara->setObjectName(QStringLiteral("tel_ara"));
        tel_ara->resize(603, 501);
        pushButton_2 = new QPushButton(tel_ara);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(210, 430, 181, 31));
        QFont font;
        font.setPointSize(13);
        font.setItalic(true);
        pushButton_2->setFont(font);
        label_2 = new QLabel(tel_ara);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(70, 250, 221, 31));
        label_2->setFont(font);
        lineEdit = new QLineEdit(tel_ara);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(310, 250, 191, 31));
        pushButton = new QPushButton(tel_ara);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(210, 360, 181, 31));
        pushButton->setFont(font);
        label = new QLabel(tel_ara);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(223, 20, 161, 150));

        retranslateUi(tel_ara);

        QMetaObject::connectSlotsByName(tel_ara);
    } // setupUi

    void retranslateUi(QDialog *tel_ara)
    {
        tel_ara->setWindowTitle(QApplication::translate("tel_ara", "Telefon no ile ki\305\237i ara", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("tel_ara", "Ana men\303\274ye d\303\266n", Q_NULLPTR));
        label_2->setText(QApplication::translate("tel_ara", "Aranacak ki\305\237i telefon no : ", Q_NULLPTR));
        pushButton->setText(QApplication::translate("tel_ara", "Ki\305\237iyi ara", Q_NULLPTR));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class tel_ara: public Ui_tel_ara {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEL_ARA_H
