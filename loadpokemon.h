#ifndef LOADPOKEMON_H
#define LOADPOKEMON_H

#include <QDialog>
#include <vector>
#include "Pokemon.h"
using std::vector;

namespace Ui {
class loadPokemon;
}

class loadPokemon : public QDialog
{
    Q_OBJECT

public:
    explicit loadPokemon(vector<Pokemon*>,Pokemon*,QWidget *parent = 0);
    ~loadPokemon();
    int getNumPokemon()const;
    bool getCancelado()const;
    Pokemon* getOponente()const;

private slots:
    void on_combo_usuarioPokemon_currentIndexChanged(int index);

    void on_button_cancelar_clicked();

    void on_button_listo_clicked();

private:
    Ui::loadPokemon *ui;
    vector<Pokemon*> lista;
    Pokemon* oponente;
    bool cancelado;
    int num_pokemon;
};

#endif // LOADPOKEMON_H
