/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *LED1;
    QCheckBox *checkBox_2;
    QLabel *LED3;
    QPushButton *shinebutton;
    QPushButton *switchbutton;
    QLabel *LED4;
    QCheckBox *checkBox_4;
    QLabel *LED2;
    QCheckBox *checkBox_1;
    QCheckBox *checkBox_3;
    QProgressBar *progressBar;
    QSpinBox *spinBox;
    QSlider *horizontalSlider;
    QLabel *label;
    QPushButton *switchbutton_off;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(590, 498);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        LED1 = new QLabel(centralWidget);
        LED1->setObjectName(QStringLiteral("LED1"));
        LED1->setGeometry(QRect(80, 40, 91, 81));
        LED1->setMinimumSize(QSize(71, 0));
        LED1->setPixmap(QPixmap(QString::fromUtf8("../index.png")));
        LED1->setScaledContents(true);
        checkBox_2 = new QCheckBox(centralWidget);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setGeometry(QRect(200, 160, 92, 23));
        LED3 = new QLabel(centralWidget);
        LED3->setObjectName(QStringLiteral("LED3"));
        LED3->setGeometry(QRect(80, 220, 91, 81));
        LED3->setMinimumSize(QSize(71, 0));
        LED3->setPixmap(QPixmap(QString::fromUtf8("../index.png")));
        LED3->setScaledContents(true);
        shinebutton = new QPushButton(centralWidget);
        shinebutton->setObjectName(QStringLiteral("shinebutton"));
        shinebutton->setGeometry(QRect(150, 410, 121, 25));
        switchbutton = new QPushButton(centralWidget);
        switchbutton->setObjectName(QStringLiteral("switchbutton"));
        switchbutton->setGeometry(QRect(350, 270, 151, 25));
        LED4 = new QLabel(centralWidget);
        LED4->setObjectName(QStringLiteral("LED4"));
        LED4->setGeometry(QRect(80, 310, 91, 81));
        LED4->setMinimumSize(QSize(71, 0));
        LED4->setPixmap(QPixmap(QString::fromUtf8("../index.png")));
        LED4->setScaledContents(true);
        checkBox_4 = new QCheckBox(centralWidget);
        checkBox_4->setObjectName(QStringLiteral("checkBox_4"));
        checkBox_4->setGeometry(QRect(200, 340, 92, 23));
        LED2 = new QLabel(centralWidget);
        LED2->setObjectName(QStringLiteral("LED2"));
        LED2->setGeometry(QRect(80, 130, 91, 81));
        LED2->setMinimumSize(QSize(71, 0));
        LED2->setPixmap(QPixmap(QString::fromUtf8("../index.png")));
        LED2->setScaledContents(true);
        checkBox_1 = new QCheckBox(centralWidget);
        checkBox_1->setObjectName(QStringLiteral("checkBox_1"));
        checkBox_1->setGeometry(QRect(200, 80, 92, 23));
        checkBox_3 = new QCheckBox(centralWidget);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));
        checkBox_3->setGeometry(QRect(200, 250, 92, 23));
        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(320, 180, 118, 23));
        progressBar->setValue(24);
        spinBox = new QSpinBox(centralWidget);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(460, 180, 48, 26));
        horizontalSlider = new QSlider(centralWidget);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(340, 140, 160, 16));
        horizontalSlider->setOrientation(Qt::Horizontal);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(370, 110, 191, 17));
        QFont font;
        font.setPointSize(13);
        label->setFont(font);
        switchbutton_off = new QPushButton(centralWidget);
        switchbutton_off->setObjectName(QStringLiteral("switchbutton_off"));
        switchbutton_off->setGeometry(QRect(350, 320, 151, 25));
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);
        QObject::connect(horizontalSlider, SIGNAL(valueChanged(int)), progressBar, SLOT(setValue(int)));
        QObject::connect(horizontalSlider, SIGNAL(valueChanged(int)), spinBox, SLOT(setValue(int)));
        QObject::connect(spinBox, SIGNAL(valueChanged(int)), horizontalSlider, SLOT(setValue(int)));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        LED1->setText(QString());
        checkBox_2->setText(QApplication::translate("MainWindow", "LED2", Q_NULLPTR));
        LED3->setText(QString());
        shinebutton->setText(QApplication::translate("MainWindow", "LED Shining", Q_NULLPTR));
        switchbutton->setText(QApplication::translate("MainWindow", "LED Switching on", Q_NULLPTR));
        LED4->setText(QString());
        checkBox_4->setText(QApplication::translate("MainWindow", "LED4", Q_NULLPTR));
        LED2->setText(QString());
        checkBox_1->setText(QApplication::translate("MainWindow", "LED1", Q_NULLPTR));
        checkBox_3->setText(QApplication::translate("MainWindow", "LED3", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Switching Speed", Q_NULLPTR));
        switchbutton_off->setText(QApplication::translate("MainWindow", "LED Switching off", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
