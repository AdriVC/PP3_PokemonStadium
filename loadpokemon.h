#ifndef LOADPOKEMON_H
#define LOADPOKEMON_H

#include <QDialog>

namespace Ui {
class loadPokemon;
}

class loadPokemon : public QDialog
{
    Q_OBJECT

public:
    explicit loadPokemon(QWidget *parent = 0);
    ~loadPokemon();

private slots:
    void on_combo_savedGames_currentIndexChanged(int index);

    void on_button_cancelar_clicked();

    void on_button_ok_clicked();

private:
    Ui::loadPokemon *ui;
};

#endif // LOADPOKEMON_H
