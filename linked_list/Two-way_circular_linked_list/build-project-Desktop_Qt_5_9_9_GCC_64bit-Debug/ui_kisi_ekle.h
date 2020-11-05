/********************************************************************************
** Form generated from reading UI file 'kisi_ekle.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KISI_EKLE_H
#define UI_KISI_EKLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_kisi_ekle
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *kisi_ekle)
    {
        if (kisi_ekle->objectName().isEmpty())
            kisi_ekle->setObjectName(QStringLiteral("kisi_ekle"));
        kisi_ekle->resize(603, 501);
        buttonBox = new QDialogButtonBox(kisi_ekle);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(kisi_ekle);
        QObject::connect(buttonBox, SIGNAL(accepted()), kisi_ekle, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), kisi_ekle, SLOT(reject()));

        QMetaObject::connectSlotsByName(kisi_ekle);
    } // setupUi

    void retranslateUi(QDialog *kisi_ekle)
    {
        kisi_ekle->setWindowTitle(QApplication::translate("kisi_ekle", "Dialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class kisi_ekle: public Ui_kisi_ekle {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KISI_EKLE_H
