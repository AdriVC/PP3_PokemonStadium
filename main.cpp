#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Jugador.h"
#include <QApplication>
#include <vector>
using std::vector;

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.show();


    return a.exec();
}
