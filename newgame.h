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
