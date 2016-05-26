/********************************************************************************
** Form generated from reading UI file 'controlpresencial.ui'
**
** Created: Wed Sep 17 14:51:16 2014
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROLPRESENCIAL_H
#define UI_CONTROLPRESENCIAL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ControlPresencial
{
public:
    QWidget *centralWidget;
    QFrame *frame;
    QLabel *Digitalclock;
    QLabel *DateTime;
    QLabel *LabelDispositivo;
    QLabel *LabelEdificio;
    QLabel *LabelAula;

    void setupUi(QMainWindow *ControlPresencial)
    {
        if (ControlPresencial->objectName().isEmpty())
            ControlPresencial->setObjectName(QString::fromUtf8("ControlPresencial"));
        ControlPresencial->resize(546, 305);
        ControlPresencial->setCursor(QCursor(Qt::BlankCursor));
        centralWidget = new QWidget(ControlPresencial);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setStyleSheet(QString::fromUtf8("border-color: rgb(255, 255, 255);\n"
"background-color: rgb(255, 255, 255);"));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(0, 20, 181, 191));
        frame->setAutoFillBackground(false);
        frame->setStyleSheet(QString::fromUtf8("border-image: url(:/new/es-resources/Resources/Logo.gif);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        Digitalclock = new QLabel(centralWidget);
        Digitalclock->setObjectName(QString::fromUtf8("Digitalclock"));
        Digitalclock->setGeometry(QRect(190, 30, 121, 51));
        Digitalclock->setStyleSheet(QString::fromUtf8("font: 75 16pt \"Sans Serif\";"));
        DateTime = new QLabel(centralWidget);
        DateTime->setObjectName(QString::fromUtf8("DateTime"));
        DateTime->setGeometry(QRect(190, 20, 111, 16));
        DateTime->setStyleSheet(QString::fromUtf8("font: 75 12pt \"Sans Serif\";"));
        LabelDispositivo = new QLabel(centralWidget);
        LabelDispositivo->setObjectName(QString::fromUtf8("LabelDispositivo"));
        LabelDispositivo->setGeometry(QRect(200, 100, 101, 16));
        LabelEdificio = new QLabel(centralWidget);
        LabelEdificio->setObjectName(QString::fromUtf8("LabelEdificio"));
        LabelEdificio->setGeometry(QRect(200, 130, 71, 16));
        LabelAula = new QLabel(centralWidget);
        LabelAula->setObjectName(QString::fromUtf8("LabelAula"));
        LabelAula->setGeometry(QRect(200, 160, 71, 16));
        LabelAula->setStyleSheet(QString::fromUtf8("font: 12pt \"Sans Serif\";"));
        ControlPresencial->setCentralWidget(centralWidget);

        retranslateUi(ControlPresencial);

        QMetaObject::connectSlotsByName(ControlPresencial);
    } // setupUi

    void retranslateUi(QMainWindow *ControlPresencial)
    {
        ControlPresencial->setWindowTitle(QApplication::translate("ControlPresencial", "ControlPresencial", 0, QApplication::UnicodeUTF8));
        Digitalclock->setText(QApplication::translate("ControlPresencial", "Clock", 0, QApplication::UnicodeUTF8));
        DateTime->setText(QApplication::translate("ControlPresencial", "Datetime", 0, QApplication::UnicodeUTF8));
        LabelDispositivo->setText(QApplication::translate("ControlPresencial", "Dispositivo", 0, QApplication::UnicodeUTF8));
        LabelEdificio->setText(QApplication::translate("ControlPresencial", "Edificio", 0, QApplication::UnicodeUTF8));
        LabelAula->setText(QApplication::translate("ControlPresencial", "Aula", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ControlPresencial: public Ui_ControlPresencial {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROLPRESENCIAL_H
