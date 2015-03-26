#include "pokedex.h"
#include "ui_pokedex.h"
#include "Pokemon.h"
#include <sstream>
#include <string>
#include <iostream>
#include <QStringList>
#include <QStringListModel>
#include <QString>
#include <vector>
using std::stringstream;
using std::string;
using std::cout;
using std::endl;
using std::vector;

Pokedex::Pokedex(vector<Pokemon*> lista,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Pokedex),
    pokemon_actual(NULL)
{
    this->lista = lista;
    ui->setupUi(this);
    QPixmap bkgnd(":/Sprites/Background7.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    QStringListModel *model = new QStringListModel(this);
    QStringList List;
    QString str;
    for(int i=0; i<(int)this->lista.size(); i++){
        str = QString::fromStdString(this->lista[i]->toString());
        List << str;
    }
    model->setStringList(List);
    ui->combo_listaPokemon->setModel(model);
}

Pokedex::~Pokedex()
{
    delete ui;
}




void Pokedex::on_button_cerrar_clicked()
{
    this->close();
}

void Pokedex::on_combo_listaPokemon_currentIndexChanged(int index)
{
    pokemon_actual = lista[index];
    const char* path = (this->pokemon_actual->getSprite()).c_str();
    QImage Logo(path);
    ui->lable_spritePokemon->setPixmap(QPixmap::fromImage(Logo));

    stringstream ss;
    QString cadena;
    // llamar nombre
    ss << (this->pokemon_actual->getNombre()) << ":";
    cadena = QString::fromStdString(ss.str());
    ui->lable_pokemon->setText(cadena);
    ss.str(string());
    //llamar nivel
    ss << (this->pokemon_actual->getNivel());
    cadena = QString::fromStdString(ss.str());
    ui->lineEdit_nivel->setText(cadena);
    ss.str(string());
    //llamar hp
    ss << (this->pokemon_actual->getHp());
    cadena = QString::fromStdString(ss.str());
    ui->lineEdit_hp->setText(cadena);
    ss.str(string());
    //llamar debilidad
    ss << (this->pokemon_actual->getDebilidad());
    cadena = QString::fromStdString(ss.str());
    ui->lineEdit_debilidad->setText(cadena);
    ss.str(string());
    //llamar ventaja
    ss << (this->pokemon_actual->getVentaja());
    cadena = QString::fromStdString(ss.str());
    ui->lineEdit_ventaja->setText(cadena);
    ss.str(string());
    //llamar fuerza
    ui->progressBar_fuerza->setValue(this->pokemon_actual->getFuerza());
    //llamar resistencia
    ui->progressBar_resistencia->setValue(this->pokemon_actual->getResistencia());
    //llamar velocidad
    ui->progressBar_velocidad->setValue(this->pokemon_actual->getVelocidad());
    //llamar golpe
    ss << (this->pokemon_actual->tackle().getNombre());
    cadena = QString::fromStdString(ss.str());
    ui->lineEdit_golpe->setText(cadena);
    ss.str(string());
    //llamar bloqueo
    ss << (this->pokemon_actual->curl().getNombre());
    cadena = QString::fromStdString(ss.str());
    ui->lineEdit_bloqueo->setText(cadena);
    ss.str(string());
    //llamar ataque
    ss << (this->pokemon_actual->attack(0).getNombre());
    cadena = QString::fromStdString(ss.str());
    ui->lineEdit_ataque->setText(cadena);
    ss.str(string());
    //llamar defensa
    ss << (this->pokemon_actual->defend(0).getNombre());
    cadena = QString::fromStdString(ss.str());
    ui->lineEdit_defensa->setText(cadena);
    ss.str(string());
    //llamar abilidad
    ss << (this->pokemon_actual->hiddenSkill(0).getNombre());
    cadena = QString::fromStdString(ss.str());
    ui->lineEdit_habilidad->setText(cadena);
    ss.str(string());
}
