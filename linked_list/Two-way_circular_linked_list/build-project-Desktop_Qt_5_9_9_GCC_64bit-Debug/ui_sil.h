/********************************************************************************
** Form generated from reading UI file 'sil.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIL_H
#define UI_SIL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_sil
{
public:
    QLineEdit *lineEdit;
    QLabel *label;
    QLabel *label_2;
    QCheckBox *checkBox;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *sil)
    {
        if (sil->objectName().isEmpty())
            sil->setObjectName(QStringLiteral("sil"));
        sil->resize(603, 501);
        lineEdit = new QLineEdit(sil);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(330, 220, 181, 25));
        label = new QLabel(sil);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(223, 20, 161, 150));
        label_2 = new QLabel(sil);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(110, 220, 211, 21));
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        label_2->setFont(font);
        checkBox = new QCheckBox(sil);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(160, 290, 271, 21));
        QFont font1;
        font1.setPointSize(13);
        checkBox->setFont(font1);
        pushButton = new QPushButton(sil);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(180, 440, 241, 31));
        QFont font2;
        font2.setPointSize(13);
        font2.setItalic(true);
        pushButton->setFont(font2);
        pushButton->setCursor(QCursor(Qt::OpenHandCursor));
        pushButton_2 = new QPushButton(sil);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(170, 380, 261, 31));
        pushButton_2->setFont(font2);
        pushButton_2->setCursor(QCursor(Qt::OpenHandCursor));

        retranslateUi(sil);

        QMetaObject::connectSlotsByName(sil);
    } // setupUi

    void retranslateUi(QDialog *sil)
    {
        sil->setWindowTitle(QApplication::translate("sil", "Ki\305\237i sil", Q_NULLPTR));
        label->setText(QString());
        label_2->setText(QApplication::translate("sil", "Ki\305\237i ad\304\261 ve soyad\304\261 : ", Q_NULLPTR));
        checkBox->setText(QApplication::translate("sil", "Silinme i\305\237lemini onayl\304\261yorum", Q_NULLPTR));
        pushButton->setText(QApplication::translate("sil", "Ana men\303\274ye d\303\266n", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("sil", "Ki\305\237iyi sil", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class sil: public Ui_sil {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIL_H
