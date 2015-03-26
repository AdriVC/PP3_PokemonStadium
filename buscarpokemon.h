#ifndef BUSCARPOKEMON_H
#define BUSCARPOKEMON_H

#include <QDialog>
#include <Pokemon.h>

namespace Ui {
class BuscarPokemon;
}

class BuscarPokemon : public QDialog
{
    Q_OBJECT

public:
    explicit BuscarPokemon(Pokemon*,QWidget *parent = 0);
    ~BuscarPokemon();
    bool getGano()const;
    QString getPlot()const;
    Pokemon* getOponente()const;
    void pokemonRetirado();

private slots:


    void on_button_lanzarRoca_clicked();

    void on_button_lanzarComida_clicked();

    void on_button_capturar_clicked();

    void on_button_huir_clicked();

private:
    Ui::BuscarPokemon *ui;
    Pokemon* oponente;
    int be;
    int hp_inicial;
    bool gano;
    QString plot;
};

#endif // BUSCARPOKEMON_H
