#include "mainwindow.h"
#include <QApplication>
#include "iostream"
#include "QtCore"
#include "QtGui"
#include <QTextCodec>
#include <StringBitStream.h>

int main(int argc, char *argv[])
{
	//qApp->addLibraryPath("C:/qt/plugins");
	//setlocale(LC_ALL, "Russian");

	//auto codec = QTextCodec::codecForName("UTF-8");
	//QTextCodec::setCodecForLocale(codec);

	//QApplication a(argc, argv);
	//MainWindow w;
	//w.show();

	//return a.exec();

	StringBitStream *sBS = new StringBitStream("new string to be performed on");
	std::cout << sBS->Read()+49 << "213123 ";
	system("pause");
	delete sBS;
}
