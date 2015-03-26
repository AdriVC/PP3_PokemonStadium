#ifndef BATTALLA_H
#define BATTALLA_H

#include <QDialog>
#include "Pokemon.h"

namespace Ui {
class Battalla;
}

class Battalla : public QDialog
{
    Q_OBJECT

public:
    explicit Battalla(Pokemon*,Pokemon*,QWidget *parent = 0);
    ~Battalla();
    bool getResultadoUsuario()const;
    void pokemonRetirado();
    void ataqueOponente();
    double getBonoVictoria();
    bool getHuyo()const;

private slots:
    void on_button_tackle_clicked();

    void on_button_curl_clicked();

    void on_button_ataque_clicked();

    void on_button_defensa_clicked();

    void on_button_habilidad_clicked();

    void on_button_huir_clicked();


private:
    Ui::Battalla *ui;
    Pokemon* usuario;
    Pokemon* oponente;
    int usuarioHpInicial;
    int oponenteHpInicial;
    double efectividadUsuario;
    double efectividadOponente;
    QString plot;
    bool ganoUsuario;
    bool huyo;
};

#endif // BATTALLA_H
