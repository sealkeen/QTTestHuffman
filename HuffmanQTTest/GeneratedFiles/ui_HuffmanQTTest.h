/********************************************************************************
** Form generated from reading UI file 'HuffmanQTTest.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HUFFMANQTTEST_H
#define UI_HUFFMANQTTEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HuffmanQTTestClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *HuffmanQTTestClass)
    {
        if (HuffmanQTTestClass->objectName().isEmpty())
            HuffmanQTTestClass->setObjectName(QStringLiteral("HuffmanQTTestClass"));
        HuffmanQTTestClass->resize(600, 400);
        menuBar = new QMenuBar(HuffmanQTTestClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        HuffmanQTTestClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(HuffmanQTTestClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        HuffmanQTTestClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(HuffmanQTTestClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        HuffmanQTTestClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(HuffmanQTTestClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        HuffmanQTTestClass->setStatusBar(statusBar);

        retranslateUi(HuffmanQTTestClass);

        QMetaObject::connectSlotsByName(HuffmanQTTestClass);
    } // setupUi

    void retranslateUi(QMainWindow *HuffmanQTTestClass)
    {
        HuffmanQTTestClass->setWindowTitle(QApplication::translate("HuffmanQTTestClass", "HuffmanQTTest", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class HuffmanQTTestClass: public Ui_HuffmanQTTestClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HUFFMANQTTEST_H
