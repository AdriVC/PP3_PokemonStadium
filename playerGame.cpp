#include "Bulbasaur.h"
#include "Chikorita.h"
#include "Charmander.h"
#include "Cyndaquil.h"
#include "Squirtle.h"
#include "Totodile.h"
#include "playerGame.h"
#include "ui_playerGame.h"
#include "loadpokemon.h"
#include "Jugador.h"
#include <iostream>
#include <QString>
#include <QStringList>
#include <QStringListModel>
#include "Chikorita.h"
#include "pokedex.h"
#include <sstream>
#include <cstdlib>
#include <ctime>
#include "buscarpokemon.h"
#include "datosusuario.h"
#include "battalla.h"
#include "Pokemon.h"
using std::cout;
using std::endl;
using std::stringstream;
using std::srand;
using std::time;

PlayerGame::PlayerGame(Jugador* jugadorActual,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PlayerGame),
    jugador(jugadorActual)
{
    ui->setupUi(this);
    srand(time(0));

    QPixmap bkgnd(":/Sprites/Background4.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    QString tituloWindow = QString::fromStdString("Partida Actual: "+this->jugador->getNombre());
    this->setWindowTitle(tituloWindow);

    const char* path = (this->jugador->getSprite()).c_str();
    QImage Logo(path);
    ui->lable_sprite->setPixmap(QPixmap::fromImage(Logo));

    ui->button_batalla->setEnabled(false);
    ui->button_verPokedex->setEnabled(false);

    stringstream ss;
    ss << (this->jugador->getNombre()) << ":";
    QString nombre = QString::fromStdString(ss.str());
    ui->lable_username->setText(nombre);
    ss.str("");

    this->resetPokedex();
}

PlayerGame::~PlayerGame()
{
    delete ui;
}

Pokemon* PlayerGame::randPokemon(){
    const int num_pokemonTot = 6;
    int random = rand()%num_pokemonTot;
    if(random == 0)
        return new Bulbasaur();
    else if(random == 1)
        return new Chikorita();
    else if(random == 2)
        return new Charmander();
    else if(random == 3)
        return new Cyndaquil();
    else if(random == 4)
        return new Squirtle();
    else
        return new Totodile();
}

void PlayerGame::on_button_buscarPokemon_clicked()
{
    BuscarPokemon* buscarpoke = new BuscarPokemon(this->randPokemon(),this);
    buscarpoke->exec();
    if(buscarpoke->getGano()){
        jugador->addPokemon(buscarpoke->getOponente());
        this->resetPokedex();
    }
}

void PlayerGame::resetPokedex(){
    stringstream ss;
    ss <<"Pokemon [" << (jugador->getPokedex().size()) << "]:";
    QString poke = QString::fromStdString(ss.str());
    ui->label_pokedex->setText(poke);

    QStringListModel *model = new QStringListModel(this);
    QStringList List;
    QString str;
    for(int i=0; i<(int)this->jugador->getPokedex().size(); i++){
        str = QString::fromStdString(this->jugador->getPokedex()[i]->toString());
    List << str;
    }
    model->setStringList(List);
    ui->list_pokedex->setModel(model);
    if(jugador->getPokedex().size() > 0){
        ui->button_batalla->setEnabled(true);
        ui->button_verPokedex->setEnabled(true);
    }else{
        ui->button_batalla->setEnabled(false);
        ui->button_verPokedex->setEnabled(false);
    }
}

void PlayerGame::on_button_batalla_clicked()
{
    Pokemon* oponente = randPokemon();
    loadPokemon* nuevaloadPoke = new loadPokemon(jugador->getPokedex(),oponente,this);
    nuevaloadPoke->exec();
    if(!nuevaloadPoke->getCancelado()){
        Battalla* nuevaBatalla = new Battalla(jugador->getPokedex()[nuevaloadPoke->getNumPokemon()],oponente,this);
        nuevaBatalla->exec();
        if(nuevaBatalla->getResultadoUsuario()){
            this->jugador->addBatallaGanada();
            this->jugador->getPokedex()[nuevaloadPoke->getNumPokemon()]->setNivel(nuevaBatalla->getBonoVictoria());
        }else{
            this->jugador->addBatallaPerdida();
            if(!nuevaBatalla->getHuyo()){
                this->jugador->eliminarPokemon(nuevaloadPoke->getNumPokemon());
            }
        }
        this->resetPokedex();
    }
}

void PlayerGame::on_button_verPokedex_clicked()
{
    Pokedex* poke = new Pokedex(this->jugador->getPokedex(),this);
    poke->exec();
}

void PlayerGame::on_button_salir_clicked()
{
    this->close();
}

void PlayerGame::on_button_datos_clicked()
{
    DatosUsuario* ventanaDatos = new DatosUsuario(jugador,this);
    ventanaDatos->exec();
    if(!ventanaDatos->getCancelado()){
        QString tituloWindow = QString::fromStdString("Partida Actual: "+this->jugador->getNombre());
        this->setWindowTitle(tituloWindow);

        const char* path = (this->jugador->getSprite()).c_str();
        QImage Logo(path);
        ui->lable_sprite->setPixmap(QPixmap::fromImage(Logo));

        stringstream ss;
        ss << (this->jugador->getNombre()) << ":";
        QString nombre = QString::fromStdString(ss.str());
        ui->lable_username->setText(nombre);
        ss.str("");

        this->resetPokedex();
    }
}
