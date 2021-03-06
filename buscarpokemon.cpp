#include "buscarpokemon.h"
#include "ui_buscarpokemon.h"
#include "Pokemon.h"
#include "Movida.h"
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <QMessageBox>
using std::stringstream;
using std::pow;
using std::srand;
using std::time;
using std::cout;
using std::endl;

BuscarPokemon::BuscarPokemon(Pokemon* oponente, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BuscarPokemon),
    oponente(oponente),
    be(1),
    hp_inicial(500),
    gano(false),
    plot("")
{
    ui->setupUi(this);
    srand(time(0));
    QPixmap bkgnd(":/Sprites/Background6.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    const char* path = (this->oponente->getSprite()).c_str();
    QImage Logo(path);
    ui->lable_oponenteSprite->setPixmap(QPixmap::fromImage(Logo));

    QString cadena;
    cadena = QString::fromStdString(this->oponente->getNombre());
    ui->lable_oponenteNombre->setText(cadena);
    cadena = QString::fromStdString("");
    stringstream ss;
    ss << "Lv " << this->oponente->getNivel();
    cadena = QString::fromStdString(ss.str());
    ui->lable_nivel->setText(cadena);
    this->hp_inicial = this->oponente->getHp();
    ui->progress_oponenteHp->setMaximum(this->hp_inicial);
    ui->progress_oponenteHp->setValue(this->oponente->getHp());
    ss.str("");
    ss << "Un " << this->oponente->getNombre() << " salvaje ha aparecido!!";
    cadena = QString::fromStdString(ss.str());
    ui->textEdit_plot->appendPlainText(cadena);

}

BuscarPokemon::~BuscarPokemon()
{
    delete ui;
}

bool BuscarPokemon::getGano()const{
    return gano;
}

QString BuscarPokemon::getPlot()const{
    return plot;
}

Pokemon* BuscarPokemon::getOponente()const{
    return oponente;
}

void BuscarPokemon::pokemonRetirado(){
    stringstream ss;
    QMessageBox msgbox;
    msgbox.setBaseSize(QSize(500, 200));
    if(this->oponente->getHp() <= (int)((double)hp_inicial*0.1)){
        gano = false;
        ss << "\n" << this->oponente->getNombre() << " ha sido debilidato tanto que se ha retirado!";
        QString cadena = QString::fromStdString(ss.str());
        ui->textEdit_plot->appendPlainText(cadena);
        this->plot = ui->textEdit_plot->toPlainText();
        ss.str(string());
        msgbox.setWindowTitle("Pokemon se Escapo");
        ss << "No pudo caputrar a " << this->oponente->getNombre() << " porque quedo muy debilitado";
        msgbox.setText(ss.str().c_str());
        msgbox.exec();
        this->close();
    }
}

void BuscarPokemon::on_button_lanzarRoca_clicked()
{

    Movida lanzarRoca("lanzar roca",this->oponente->getHp()*-0.2,0,60,1);
    this->oponente->setHp(lanzarRoca.getGolpe());
    ui->progress_oponenteHp->setValue(this->oponente->getHp());
    stringstream ss;
    ss << "Usted " << lanzarRoca.toString();
    QString cadena = QString::fromStdString(ss.str());
    ui->textEdit_plot->appendPlainText(cadena);
    this->pokemonRetirado();
}

void BuscarPokemon::on_button_lanzarComida_clicked()
{
    Movida lanzarComida("lanzar comida",this->oponente->getHp()*0.1,0,75,1);
    this->oponente->setHp(lanzarComida.getGolpe());
    this->be=2;
    ui->progress_oponenteHp->setValue(this->oponente->getHp());
    stringstream ss;
    ss << "\nUsted " << lanzarComida.toString();
    QString cadena = QString::fromStdString(ss.str());
    ui->textEdit_plot->appendPlainText(cadena);
    this->pokemonRetirado();
}

void BuscarPokemon::on_button_capturar_clicked()
{
    stringstream ss;
    QMessageBox msgbox;
    msgbox.setBaseSize(QSize(500, 150));
    int a = be*(3*hp_inicial-2*this->oponente->getHp())/5*hp_inicial;
    if(a >= 225000){
        //pokemon capturado
        ss << "Usted ha capturado a " << this->oponente->getNombre();
        QString cadena = QString::fromStdString(ss.str());
        ui->textEdit_plot->appendPlainText(cadena);
        gano = true;
        ss.str(string());
        msgbox.setWindowTitle("Pokemon Atrapado!");
        ss << "Ha capturado a " << this->oponente->getNombre() << "!";
        msgbox.setText(ss.str().c_str());
        msgbox.exec();
        this->close();
    }else{
        int b = 64535*pow((double)a/50500,0.25);
        int n1 = rand()%65536;
        int n2 = rand()%65536;
        int n3 = rand()%65536;
        int n4 = rand()%65536;
        int contador =0;
        if(b >= n1)
            contador++;
        if(b >= n2)
            contador++;
        if(b >= n3)
            contador++;
        if(b >= n4)
            contador++;
        if(contador <= 1){
            // el pokemon se libero
            ss << this->oponente->getNombre() << " se libero!!";
        } else if(contador == 2){
            //casi lo tenia
            ss << "Casi lo tenia!";
        } else if(contador == 3){
            //parecia estar atrapado
            ss << this->oponente->getNombre() << " parecia estar atrapado!";
        } else{
            // nombre de pokemon fue atrapado
            ss << "Usted ha capturado a " << this->oponente->getNombre();
            gano = true;
            ss.str(string());
            msgbox.setWindowTitle("Pokemon Atrapado!");
            ss << "Ha capturado a " << this->oponente->getNombre() << "!";
            msgbox.setText(ss.str().c_str());
            msgbox.exec();
            this->close();
        }
    }
    QString cadena = QString::fromStdString(ss.str());
    ui->textEdit_plot->appendPlainText(cadena);
}

void BuscarPokemon::on_button_huir_clicked()
{
    stringstream ss;
    QMessageBox msgbox;
    msgbox.setBaseSize(QSize(500, 150));
    ss << "Usted huyo...";
    QString cadena = QString::fromStdString(ss.str());
    ui->textEdit_plot->appendPlainText(cadena);
    this->plot = ui->textEdit_plot->toPlainText();
    ss.str(string());
    msgbox.setWindowTitle("Pokemon se Escapo");
    ss << "Ha huido del " << this->oponente->getNombre();
    msgbox.setText(ss.str().c_str());
    msgbox.exec();
    this->close();
}
