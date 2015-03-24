#ifndef PLAYERGAME_H
#define PLAYERGAME_H

#include <QDialog>
#include "Jugador.h"

namespace Ui {
class PlayerGame;
}

class PlayerGame : public QDialog
{
    Q_OBJECT

public:
    explicit PlayerGame(Jugador*, QWidget *parent = 0);
    ~PlayerGame();
    Pokemon* randPokemon();
    void resetPokedex();

private slots:
    void on_button_buscarPokemon_clicked();

    void on_button_batalla_clicked();

    void on_button_examinarPokemon_clicked();

    void on_button_salir_clicked();

private:
    Ui::PlayerGame *ui;
    Jugador* jugador;
};

#endif // PLAYERGAME_H
