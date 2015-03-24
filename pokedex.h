#ifndef POKEDEX_H
#define POKEDEX_H

#include <QDialog>
#include "Pokemon.h"
#include <vector>
using std::vector;

namespace Ui {
class Pokedex;
}

class Pokedex : public QDialog
{
    Q_OBJECT

public:
    explicit Pokedex(vector<Pokemon*>,QWidget *parent = 0);
    ~Pokedex();

private slots:


    void on_button_cerrar_clicked();

    void on_combo_listaPokemon_currentIndexChanged(int index);

private:
    Ui::Pokedex *ui;
    Pokemon* pokemon_actual;
    vector<Pokemon*> lista;
};

#endif // POKEDEX_H
