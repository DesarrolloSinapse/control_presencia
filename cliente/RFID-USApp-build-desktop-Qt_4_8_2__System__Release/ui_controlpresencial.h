/********************************************************************************
** Form generated from reading UI file 'controlpresencial.ui'
**
** Created: Tue Mar 8 07:41:20 2016
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
    QLabel *LabelError;
    QLabel *LabelIP;

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
        frame->setGeometry(QRect(20, 40, 200, 67));
        frame->setAutoFillBackground(false);
        frame->setStyleSheet(QString::fromUtf8("border-image: url(:/new/es-resources/Resources/Logo.gif);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        Digitalclock = new QLabel(centralWidget);
        Digitalclock->setObjectName(QString::fromUtf8("Digitalclock"));
        Digitalclock->setGeometry(QRect(275, 20, 191, 51));
        Digitalclock->setStyleSheet(QString::fromUtf8("font: 75 19pt \"Sans Serif\";"));
        DateTime = new QLabel(centralWidget);
        DateTime->setObjectName(QString::fromUtf8("DateTime"));
        DateTime->setGeometry(QRect(282, 65, 171, 16));
        DateTime->setStyleSheet(QString::fromUtf8("font: 75 13pt \"Sans Serif\";"));
        LabelDispositivo = new QLabel(centralWidget);
        LabelDispositivo->setObjectName(QString::fromUtf8("LabelDispositivo"));
        LabelEdificio = new QLabel(centralWidget);
        LabelEdificio->setObjectName(QString::fromUtf8("LabelEdificio"));
        LabelError = new QLabel(centralWidget);
        LabelError->setObjectName(QString::fromUtf8("LabelError"));
        LabelError->setGeometry(QRect(20, 150, 321, 71));
        LabelError->setWordWrap(true);
        LabelIP = new QLabel(centralWidget);
        LabelIP->setObjectName(QString::fromUtf8("LabelIP"));
        LabelIP->setGeometry(QRect(280, 90, 161, 16));
        QFont font;
        font.setFamily(QString::fromUtf8("Sans Serif"));
        font.setPointSize(9);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(9);
        LabelIP->setFont(font);
        LabelIP->setStyleSheet(QString::fromUtf8("font: 75 9pt \"Sans Serif\";"));
        ControlPresencial->setCentralWidget(centralWidget);

        retranslateUi(ControlPresencial);

        QMetaObject::connectSlotsByName(ControlPresencial);
    } // setupUi

    void retranslateUi(QMainWindow *ControlPresencial)
    {
        ControlPresencial->setWindowTitle(QApplication::translate("ControlPresencial", "ControlPresencial", 0, QApplication::UnicodeUTF8));
        Digitalclock->setText(QApplication::translate("ControlPresencial", "Clock", 0, QApplication::UnicodeUTF8));
        DateTime->setText(QApplication::translate("ControlPresencial", "Datetime", 0, QApplication::UnicodeUTF8));
        LabelError->setText(QString());
        LabelIP->setText(QApplication::translate("ControlPresencial", "IP", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ControlPresencial: public Ui_ControlPresencial {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROLPRESENCIAL_H
