#ifndef NEWGAME_H
#define NEWGAME_H

#include <QDialog>
#include "Jugador.h"
#include "mainwindow.h"

namespace Ui {
class newGame;
}

class newGame : public QDialog
{
    Q_OBJECT

public:
    explicit newGame(QWidget *parent = 0);
    Jugador* getNewJugador();
    bool ifCancelado();
    ~newGame();

private slots:

    void on_rbutton_femenino_clicked();

    void on_rbutton_masculino_clicked();

    void on_button_avatarf0_clicked();
    void on_button_avatarm0_clicked();
    void on_button_avatarf1_clicked();
    void on_button_avatarm1_clicked();
    void on_button_avatarf2_clicked();
    void on_button_avatarm2_clicked();
    void on_button_avatarf3_clicked();
    void on_button_avatarm3_clicked();
    void on_button_avatarf4_clicked();
    void on_button_avatarm4_clicked();


    void on_button_cancelar_clicked();

    void on_button_ok_clicked();

private:
    Ui::newGame *ui;
    //QMainWindow* ventanaPrincipal;
    Jugador* jugador;
    bool cancelado;
    int num_sprite;
};

#endif // NEWGAME_H
