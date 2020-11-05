/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(603, 501);
        MainWindow->setCursor(QCursor(Qt::ArrowCursor));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(130, 190, 151, 31));
        QFont font;
        font.setPointSize(10);
        font.setItalic(true);
        pushButton->setFont(font);
        pushButton->setCursor(QCursor(Qt::OpenHandCursor));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(320, 190, 151, 31));
        pushButton_2->setFont(font);
        pushButton_2->setCursor(QCursor(Qt::OpenHandCursor));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(130, 260, 151, 31));
        pushButton_3->setFont(font);
        pushButton_3->setCursor(QCursor(Qt::OpenHandCursor));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(320, 260, 151, 31));
        pushButton_4->setFont(font);
        pushButton_4->setCursor(QCursor(Qt::OpenHandCursor));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(130, 330, 151, 31));
        pushButton_5->setFont(font);
        pushButton_5->setCursor(QCursor(Qt::OpenHandCursor));
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(320, 330, 151, 31));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(false);
        font1.setItalic(true);
        font1.setWeight(50);
        pushButton_6->setFont(font1);
        pushButton_6->setCursor(QCursor(Qt::OpenHandCursor));
        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setEnabled(true);
        pushButton_7->setGeometry(QRect(220, 400, 161, 31));
        pushButton_7->setFont(font);
        pushButton_7->setCursor(QCursor(Qt::OpenHandCursor));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(223, 20, 161, 150));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 603, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "           demir.ai Rehber", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Ki\305\237i Ekle", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "S\304\261ral\304\261 Ki\305\237i Ekle", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "Listele", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("MainWindow", "S\304\261ral\304\261 Listele", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("MainWindow", "Ki\305\237i Ara (Ad, Soyad)", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("MainWindow", "Ki\305\237i Ara (Tel)", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("MainWindow", "Ki\305\237i Sil", Q_NULLPTR));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
