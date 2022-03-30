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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *shinebutton;
    QPushButton *switchbutton;
    QLabel *Times;
    QCheckBox *checkBox_1;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;
    QLabel *LED1;
    QLabel *LED2;
    QLabel *LED3;
    QLabel *LED4;
    QLineEdit *input_text;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(532, 510);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        shinebutton = new QPushButton(centralWidget);
        shinebutton->setObjectName(QStringLiteral("shinebutton"));
        shinebutton->setGeometry(QRect(150, 400, 121, 25));
        switchbutton = new QPushButton(centralWidget);
        switchbutton->setObjectName(QStringLiteral("switchbutton"));
        switchbutton->setGeometry(QRect(350, 260, 121, 25));
        Times = new QLabel(centralWidget);
        Times->setObjectName(QStringLiteral("Times"));
        Times->setGeometry(QRect(350, 190, 67, 17));
        checkBox_1 = new QCheckBox(centralWidget);
        checkBox_1->setObjectName(QStringLiteral("checkBox_1"));
        checkBox_1->setGeometry(QRect(200, 70, 92, 23));
        checkBox_2 = new QCheckBox(centralWidget);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setGeometry(QRect(200, 150, 92, 23));
        checkBox_3 = new QCheckBox(centralWidget);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));
        checkBox_3->setGeometry(QRect(200, 240, 92, 23));
        checkBox_4 = new QCheckBox(centralWidget);
        checkBox_4->setObjectName(QStringLiteral("checkBox_4"));
        checkBox_4->setGeometry(QRect(200, 330, 92, 23));
        LED1 = new QLabel(centralWidget);
        LED1->setObjectName(QStringLiteral("LED1"));
        LED1->setGeometry(QRect(80, 30, 91, 81));
        LED1->setMinimumSize(QSize(71, 0));
        LED1->setPixmap(QPixmap(QString::fromUtf8("../index.png")));
        LED1->setScaledContents(true);
        LED2 = new QLabel(centralWidget);
        LED2->setObjectName(QStringLiteral("LED2"));
        LED2->setGeometry(QRect(80, 120, 91, 81));
        LED2->setMinimumSize(QSize(71, 0));
        LED2->setPixmap(QPixmap(QString::fromUtf8("../index.png")));
        LED2->setScaledContents(true);
        LED3 = new QLabel(centralWidget);
        LED3->setObjectName(QStringLiteral("LED3"));
        LED3->setGeometry(QRect(80, 210, 91, 81));
        LED3->setMinimumSize(QSize(71, 0));
        LED3->setPixmap(QPixmap(QString::fromUtf8("../index.png")));
        LED3->setScaledContents(true);
        LED4 = new QLabel(centralWidget);
        LED4->setObjectName(QStringLiteral("LED4"));
        LED4->setGeometry(QRect(80, 300, 91, 81));
        LED4->setMinimumSize(QSize(71, 0));
        LED4->setPixmap(QPixmap(QString::fromUtf8("../index.png")));
        LED4->setScaledContents(true);
        input_text = new QLineEdit(centralWidget);
        input_text->setObjectName(QStringLiteral("input_text"));
        input_text->setGeometry(QRect(350, 220, 121, 25));
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        shinebutton->setText(QApplication::translate("MainWindow", "LED Shining", Q_NULLPTR));
        switchbutton->setText(QApplication::translate("MainWindow", "LED Switching", Q_NULLPTR));
        Times->setText(QApplication::translate("MainWindow", "Times", Q_NULLPTR));
        checkBox_1->setText(QApplication::translate("MainWindow", "LED1", Q_NULLPTR));
        checkBox_2->setText(QApplication::translate("MainWindow", "LED2", Q_NULLPTR));
        checkBox_3->setText(QApplication::translate("MainWindow", "LED3", Q_NULLPTR));
        checkBox_4->setText(QApplication::translate("MainWindow", "LED4", Q_NULLPTR));
        LED1->setText(QString());
        LED2->setText(QString());
        LED3->setText(QString());
        LED4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
