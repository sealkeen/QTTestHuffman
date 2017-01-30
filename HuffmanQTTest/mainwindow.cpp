#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "HuffmanCoder.h"

HuffmanCoder huffmanCoder;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ShowCodes()
{
    QString qS =  qS.fromStdString(huffmanCoder.ShowCodes());
    ui->txtOutput->setPlainText(qS);
    cout << "Кодс: {" << qS.toStdString() << "}" <<endl;
}


void MainWindow::Encode()
{
    huffmanCoder.TestString = ui->textEdit->toPlainText().toStdString();
    huffmanCoder.Encrypt();

    return;
}

void MainWindow::WriteFile()
{
    if(!ui->txtFilePath->toPlainText().isEmpty())
    {
        huffmanCoder.outFile = ui->txtFilePath->toPlainText().toStdString();
        huffmanCoder.WriteHuffmanEncoding();
        ui->txtOutput->setPlainText("Successfully written.");
    }
    else
    {
        ui->txtOutput->setPlainText("The file fullname is empty");
    }
}
void MainWindow::ReadFile()
{
    if(!ui->txtFilePath->toPlainText().isEmpty())
    {
        string str = ui->txtFilePath->toPlainText().toStdString();
        huffmanCoder.inFile = str;
        QString qS =  qS.fromStdString(huffmanCoder.ReadHuffmanEncoding());
        ui->txtOutput->setPlainText("Successfully read. String: \n"+qS);
    }
    else
    {
        ui->txtOutput->setPlainText("The file fullname is empty");
    }
}
