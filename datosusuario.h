#ifndef DATOSUSUARIO_H
#define DATOSUSUARIO_H

#include <QDialog>
#include "Jugador.h"

namespace Ui {
class DatosUsuario;
}

class DatosUsuario : public QDialog
{
    Q_OBJECT

public:
    explicit DatosUsuario(Jugador*,QWidget *parent = 0);
    ~DatosUsuario();
    bool getCancelado()const;

private slots:
    void on_button_guardar_clicked();

    void on_button_cancelar_clicked();

    void on_comboBox_avatar_currentIndexChanged(int index);

    void on_button_retirar_clicked();

private:
    Ui::DatosUsuario *ui;
    Jugador* actual;
    int num_sprite;
    bool cancelado;
};

#endif // DATOSUSUARIO_H
