/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *labelComposition;
    QPushButton *pushButtonAdd;
    QPushButton *pushButtonPrev;
    QPushButton *pushButtonPlay;
    QPushButton *pushButtonPause;
    QPushButton *pushButtonNext;
    QSlider *HorSliderVolume;
    QSlider *horizontalSliderProgress;
    QLabel *labelVolume;
    QLabel *labelPlayer;
    QLabel *labelDuration;
    QPushButton *pushButtonStop;
    QPushButton *pushButtonMute;
    QTableView *tablePlayList;
    QPushButton *pushButtonRem;
    QPushButton *pushButtonClear;
    QPushButton *pushButtonLoop;
    QPushButton *pushButtonShuffle;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(540, 430);
        Widget->setMinimumSize(QSize(540, 430));
        Widget->setMaximumSize(QSize(540, 430));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Icon/Icon/player.ico"), QSize(), QIcon::Normal, QIcon::Off);
        Widget->setWindowIcon(icon);
        labelComposition = new QLabel(Widget);
        labelComposition->setObjectName(QString::fromUtf8("labelComposition"));
        labelComposition->setGeometry(QRect(20, 40, 491, 31));
        pushButtonAdd = new QPushButton(Widget);
        pushButtonAdd->setObjectName(QString::fromUtf8("pushButtonAdd"));
        pushButtonAdd->setGeometry(QRect(20, 390, 51, 21));
        pushButtonAdd->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border: none;\n"
"	border-radius: 5px;\n"
"	background-color: rgb(211,211,211);\n"
"	color: rgb(11,11,11);\n"
"}"));
        pushButtonPrev = new QPushButton(Widget);
        pushButtonPrev->setObjectName(QString::fromUtf8("pushButtonPrev"));
        pushButtonPrev->setGeometry(QRect(20, 100, 51, 21));
        pushButtonPrev->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border: none;\n"
"	border-radius: 5px;\n"
"	background-color: rgb(211,211,211);\n"
"	color: rgb(11,11,11);\n"
"}"));
        pushButtonPlay = new QPushButton(Widget);
        pushButtonPlay->setObjectName(QString::fromUtf8("pushButtonPlay"));
        pushButtonPlay->setGeometry(QRect(80, 100, 51, 21));
        pushButtonPlay->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border: none;\n"
"	border-radius: 5px;\n"
"	background-color: rgb(211,211,211);\n"
"	color: rgb(11,11,11);\n"
"}"));
        pushButtonPause = new QPushButton(Widget);
        pushButtonPause->setObjectName(QString::fromUtf8("pushButtonPause"));
        pushButtonPause->setGeometry(QRect(140, 100, 51, 21));
        pushButtonPause->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border: none;\n"
"	border-radius: 5px;\n"
"	background-color: rgb(211,211,211);\n"
"	color: rgb(11,11,11);\n"
"}"));
        pushButtonNext = new QPushButton(Widget);
        pushButtonNext->setObjectName(QString::fromUtf8("pushButtonNext"));
        pushButtonNext->setGeometry(QRect(260, 100, 51, 21));
        pushButtonNext->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border: none;\n"
"	border-radius: 6px;\n"
"	background-color: rgb(211,211,211);\n"
"	color: rgb(11,11,11);\n"
"}"));
        HorSliderVolume = new QSlider(Widget);
        HorSliderVolume->setObjectName(QString::fromUtf8("HorSliderVolume"));
        HorSliderVolume->setGeometry(QRect(410, 100, 101, 20));
        HorSliderVolume->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal\n"
"{\n"
"	height: 			8;\n"
"	width: 				120;\n"
"	background:	 red;\n"
"	border-radius:  8px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal\n"
"{\n"
"	visible: true;\n"
"	background: rgb(122,122,122);\n"
"	width: 					10px;\n"
"	height: 				10px;\n"
"	margin:		-7px -7px;\n"
"	border-radius:		10px;\n"
"}"));
        HorSliderVolume->setOrientation(Qt::Horizontal);
        horizontalSliderProgress = new QSlider(Widget);
        horizontalSliderProgress->setObjectName(QString::fromUtf8("horizontalSliderProgress"));
        horizontalSliderProgress->setGeometry(QRect(20, 150, 501, 20));
        horizontalSliderProgress->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal\n"
"{\n"
"	height: 			10;\n"
"	width: 				500;\n"
"	background:	 green;\n"
"	border-radius:  5px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal\n"
"{\n"
"	visible: true;\n"
"	background:rgb(111,100,111);\n"
"	width: 					10px;\n"
"	height: 				10px;\n"
"	margin:-7px -7px;\n"
"	border-radius:		6px;\n"
"}"));
        horizontalSliderProgress->setOrientation(Qt::Horizontal);
        labelVolume = new QLabel(Widget);
        labelVolume->setObjectName(QString::fromUtf8("labelVolume"));
        labelVolume->setGeometry(QRect(470, 80, 61, 16));
        labelPlayer = new QLabel(Widget);
        labelPlayer->setObjectName(QString::fromUtf8("labelPlayer"));
        labelPlayer->setGeometry(QRect(50, 130, 81, 16));
        labelDuration = new QLabel(Widget);
        labelDuration->setObjectName(QString::fromUtf8("labelDuration"));
        labelDuration->setGeometry(QRect(430, 130, 91, 20));
        pushButtonStop = new QPushButton(Widget);
        pushButtonStop->setObjectName(QString::fromUtf8("pushButtonStop"));
        pushButtonStop->setGeometry(QRect(200, 100, 51, 21));
        pushButtonStop->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border: none;\n"
"	border-radius: 5px;\n"
"	background-color: rgb(211,211,211);\n"
"	color: rgb(11,11,11);\n"
"}"));
        pushButtonMute = new QPushButton(Widget);
        pushButtonMute->setObjectName(QString::fromUtf8("pushButtonMute"));
        pushButtonMute->setGeometry(QRect(350, 100, 51, 21));
        pushButtonMute->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border: none;\n"
"	border-radius: 5px;\n"
"	background-color: rgb(211,211,211);\n"
"	color: rgb(11,11,11);\n"
"}"));
        tablePlayList = new QTableView(Widget);
        tablePlayList->setObjectName(QString::fromUtf8("tablePlayList"));
        tablePlayList->setGeometry(QRect(20, 190, 501, 192));
        pushButtonRem = new QPushButton(Widget);
        pushButtonRem->setObjectName(QString::fromUtf8("pushButtonRem"));
        pushButtonRem->setGeometry(QRect(90, 390, 51, 21));
        pushButtonRem->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border: none;\n"
"	border-radius: 5px;\n"
"	background-color: rgb(211,211,211);\n"
"	color: rgb(11,11,11);\n"
"}"));
        pushButtonClear = new QPushButton(Widget);
        pushButtonClear->setObjectName(QString::fromUtf8("pushButtonClear"));
        pushButtonClear->setGeometry(QRect(160, 390, 51, 21));
        pushButtonClear->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border: none;\n"
"	border-radius: 5px;\n"
"	background-color: rgb(211,211,211);\n"
"	color: rgb(11,11,11);\n"
"}"));
        pushButtonLoop = new QPushButton(Widget);
        pushButtonLoop->setObjectName(QString::fromUtf8("pushButtonLoop"));
        pushButtonLoop->setGeometry(QRect(220, 390, 51, 21));
        pushButtonLoop->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border: none;\n"
"	border-radius: 5px;\n"
"	background-color: rgb(211,211,211);\n"
"	color: rgb(11,11,11);\n"
"}\n"
"QPushButton:checked\n"
"{\n"
"	border: none;\n"
"	border-radius: 5px;\n"
"	background-color: rgb(11,11,11);\n"
"	color: rgb(211,211,211);\n"
"}"));
        pushButtonShuffle = new QPushButton(Widget);
        pushButtonShuffle->setObjectName(QString::fromUtf8("pushButtonShuffle"));
        pushButtonShuffle->setGeometry(QRect(280, 390, 51, 21));
        pushButtonShuffle->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border: none;\n"
"	border-radius: 5px;\n"
"	background-color: rgb(211,211,211);\n"
"	color: rgb(11,11,11);\n"
"}\n"
"QPushButton:checked\n"
"{\n"
"	border: none;\n"
"	border-radius: 5px;\n"
"	background-color: rgb(11,11,11);\n"
"	color: rgb(211,211,211);\n"
"}"));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Media Player", nullptr));
        labelComposition->setText(QApplication::translate("Widget", "Composition", nullptr));
        pushButtonAdd->setText(QApplication::translate("Widget", "Add", nullptr));
        pushButtonPrev->setText(QString());
        pushButtonPlay->setText(QString());
        pushButtonPause->setText(QString());
        pushButtonNext->setText(QString());
        labelVolume->setText(QApplication::translate("Widget", "Volume:", nullptr));
        labelPlayer->setText(QApplication::translate("Widget", "Player", nullptr));
        labelDuration->setText(QApplication::translate("Widget", "Duration", nullptr));
        pushButtonStop->setText(QString());
        pushButtonMute->setText(QString());
        pushButtonRem->setText(QApplication::translate("Widget", "Rem", nullptr));
        pushButtonClear->setText(QApplication::translate("Widget", "Clear", nullptr));
        pushButtonLoop->setText(QApplication::translate("Widget", "Loop", nullptr));
        pushButtonShuffle->setText(QApplication::translate("Widget", "Shuffle", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
