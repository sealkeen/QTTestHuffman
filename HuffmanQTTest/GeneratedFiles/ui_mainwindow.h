/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
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
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QWidget *centralWidget;
    QPushButton *btnEncode;
    QTextEdit *textEdit;
    QPushButton *btnShowCode;
    QPushButton *btnWrite;
    QLabel *lblString;
    QLabel *lblOutput;
    QTextEdit *txtOutput;
    QPushButton *btnRead;
    QTextEdit *txtFilePath;
    QLabel *lblPath;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(640, 480);
        MainWindow->setMinimumSize(QSize(640, 480));
        MainWindow->setMaximumSize(QSize(640, 480));
        MainWindow->setTabShape(QTabWidget::Triangular);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setEnabled(true);
        btnEncode = new QPushButton(centralWidget);
        btnEncode->setObjectName(QStringLiteral("btnEncode"));
        btnEncode->setGeometry(QRect(10, 250, 75, 23));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(10, 20, 621, 221));
        btnShowCode = new QPushButton(centralWidget);
        btnShowCode->setObjectName(QStringLiteral("btnShowCode"));
        btnShowCode->setGeometry(QRect(90, 250, 75, 23));
        btnWrite = new QPushButton(centralWidget);
        btnWrite->setObjectName(QStringLiteral("btnWrite"));
        btnWrite->setEnabled(false);
        btnWrite->setGeometry(QRect(480, 250, 71, 41));
        lblString = new QLabel(centralWidget);
        lblString->setObjectName(QStringLiteral("lblString"));
        lblString->setGeometry(QRect(10, 0, 71, 16));
        lblOutput = new QLabel(centralWidget);
        lblOutput->setObjectName(QStringLiteral("lblOutput"));
        lblOutput->setGeometry(QRect(10, 280, 47, 13));
        txtOutput = new QTextEdit(centralWidget);
        txtOutput->setObjectName(QStringLiteral("txtOutput"));
        txtOutput->setGeometry(QRect(10, 300, 621, 121));
        btnRead = new QPushButton(centralWidget);
        btnRead->setObjectName(QStringLiteral("btnRead"));
        btnRead->setEnabled(false);
        btnRead->setGeometry(QRect(560, 250, 71, 41));
        txtFilePath = new QTextEdit(centralWidget);
        txtFilePath->setObjectName(QStringLiteral("txtFilePath"));
        txtFilePath->setGeometry(QRect(230, 250, 241, 41));
        lblPath = new QLabel(centralWidget);
        lblPath->setObjectName(QStringLiteral("lblPath"));
        lblPath->setGeometry(QRect(180, 250, 51, 16));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 640, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionOpen);

        retranslateUi(MainWindow);
        QObject::connect(btnEncode, SIGNAL(clicked()), MainWindow, SLOT(Encode()));
        QObject::connect(btnShowCode, SIGNAL(clicked()), MainWindow, SLOT(ShowCodes()));
        QObject::connect(btnWrite, SIGNAL(clicked()), MainWindow, SLOT(WriteFile()));
        QObject::connect(btnRead, SIGNAL(clicked()), MainWindow, SLOT(ReadFile()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", Q_NULLPTR));
        btnEncode->setText(QApplication::translate("MainWindow", "Encode", Q_NULLPTR));
        textEdit->setDocumentTitle(QString());
        btnShowCode->setText(QApplication::translate("MainWindow", "Show Codes", Q_NULLPTR));
        btnWrite->setText(QApplication::translate("MainWindow", "Write", Q_NULLPTR));
        lblString->setText(QApplication::translate("MainWindow", "Your String:", Q_NULLPTR));
        lblOutput->setText(QApplication::translate("MainWindow", "Output:", Q_NULLPTR));
        btnRead->setText(QApplication::translate("MainWindow", "Read", Q_NULLPTR));
        lblPath->setText(QApplication::translate("MainWindow", "File path:", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
