#include "loadpokemon.h"
#include "ui_loadpokemon.h"

loadPokemon::loadPokemon(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loadPokemon)
{
    ui->setupUi(this);
}

loadPokemon::~loadPokemon()
{
    delete ui;
}

void loadPokemon::on_combo_savedGames_currentIndexChanged(int index)
{

}

void loadPokemon::on_button_cancelar_clicked()
{

}

void loadPokemon::on_button_ok_clicked()
{

}
