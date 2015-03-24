#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Jugador.h"
#include "newgame.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setNewPlayer(Jugador*);
    //Ui getUi()const;

private slots:
    void on_button_exit_clicked();

    void on_button_new_clicked();

    void on_button_load_clicked();

public:
    Ui::MainWindow *ui;
    Jugador* jugadores[10];
    int cuentas;
    Jugador* partidaActual;
};

#endif // MAINWINDOW_H
