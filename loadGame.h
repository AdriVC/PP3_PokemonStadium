#ifndef LOADGAME_H
#define LOADGAME_H

#include <QDialog>
#include "Jugador.h"

namespace Ui {
class LoadGame;
}

class LoadGame : public QDialog
{
    Q_OBJECT

public:
    explicit LoadGame(Jugador**,int,QWidget *parent = 0);
    ~LoadGame();
    bool isCancelado()const;
    int getCurrentGame()const;
    bool isEliminado()const;

private slots:

    void on_combo_savedGames_currentIndexChanged(int index);

    void on_button_ok_clicked();

    void on_button_cancelar_clicked();

    void on_button_eliminar_clicked();

private:
    Ui::LoadGame *ui;
    Jugador** jugadores;
    int juego;
    bool cancelado,eliminado;
};

#endif // LOADGAME_H
