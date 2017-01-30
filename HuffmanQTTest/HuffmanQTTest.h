#ifndef HUFFMANQTTEST_H
#define HUFFMANQTTEST_H

#include <QtWidgets/QMainWindow>
#include "ui_HuffmanQTTest.h"

class HuffmanQTTest : public QMainWindow
{
    Q_OBJECT

public:
    HuffmanQTTest(QWidget *parent = Q_NULLPTR);

private:
    Ui::HuffmanQTTestClass ui;
};
#endif //HUFFMANQTTEST_H