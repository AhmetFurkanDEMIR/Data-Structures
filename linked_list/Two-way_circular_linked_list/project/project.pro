QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ad_ara.cpp \
    ekle.cpp \
    listele.cpp \
    main.cpp \
    mainwindow.cpp \
    sil.cpp \
    sirali_ekle.cpp \
    tel_ara.cpp

HEADERS += \
    ad_ara.h \
    ekle.h \
    listele.h \
    mainwindow.h \
    rehber.h \
    sil.h \
    sirali_ekle.h \
    tel_ara.h

FORMS += \
    ad_ara.ui \
    ekle.ui \
    listele.ui \
    mainwindow.ui \
    sil.ui \
    sirali_ekle.ui \
    tel_ara.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
