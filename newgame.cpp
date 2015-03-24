#include "newgame.h"
#include "ui_newgame.h"
#include "Jugador.h"
#include "mainwindow.h"
#include <string>
using std::string;

newGame::newGame(QWidget *parent) :
    QDialog(parent),
    num_sprite(0),
    cancelado(true),
    ui(new Ui::newGame)
{
    ui->setupUi(this);
    QPixmap bkgnd(":/Sprites/Background2.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
    ui->button_avatarf0->setEnabled(false);
    ui->button_avatarf1->setEnabled(false);
    ui->button_avatarf2->setEnabled(false);
    ui->button_avatarf3->setEnabled(false);
    ui->button_avatarf4->setEnabled(false);
    ui->button_avatarm0->setEnabled(false);
    ui->button_avatarm1->setEnabled(false);
    ui->button_avatarm2->setEnabled(false);
    ui->button_avatarm3->setEnabled(false);
    ui->button_avatarm4->setEnabled(false);
    ui->button_avatarf0->setIcon(QIcon(":/Sprites/Female0.png"));
    ui->button_avatarf1->setIcon(QIcon(":/Sprites/Female1.png"));
    ui->button_avatarf2->setIcon(QIcon(":/Sprites/Female2.png"));
    ui->button_avatarf3->setIcon(QIcon(":/Sprites/Female3.png"));
    ui->button_avatarf4->setIcon(QIcon(":/Sprites/Female4.png"));
    ui->button_avatarm0->setIcon(QIcon(":/Sprites/Male0.png"));
    ui->button_avatarm1->setIcon(QIcon(":/Sprites/Male1.png"));
    ui->button_avatarm2->setIcon(QIcon(":/Sprites/Male2.png"));
    ui->button_avatarm3->setIcon(QIcon(":/Sprites/Male3.png"));
    ui->button_avatarm4->setIcon(QIcon(":/Sprites/Male4.png"));
}

newGame::~newGame()
{
    delete ui;
}

Jugador* newGame::getNewJugador(){
    return jugador;
}

bool newGame::ifCancelado(){
    return cancelado;
}

void newGame::on_rbutton_femenino_clicked()
{
    ui->button_avatarf0->setEnabled(true);
    ui->button_avatarf1->setEnabled(true);
    ui->button_avatarf2->setEnabled(true);
    ui->button_avatarf3->setEnabled(true);
    ui->button_avatarf4->setEnabled(true);
    ui->button_avatarm0->setEnabled(false);
    ui->button_avatarm1->setEnabled(false);
    ui->button_avatarm2->setEnabled(false);
    ui->button_avatarm3->setEnabled(false);
    ui->button_avatarm4->setEnabled(false);
}

void newGame::on_rbutton_masculino_clicked()
{
    ui->button_avatarf0->setEnabled(false);
    ui->button_avatarf1->setEnabled(false);
    ui->button_avatarf2->setEnabled(false);
    ui->button_avatarf3->setEnabled(false);
    ui->button_avatarf4->setEnabled(false);
    ui->button_avatarm0->setEnabled(true);
    ui->button_avatarm1->setEnabled(true);
    ui->button_avatarm2->setEnabled(true);
    ui->button_avatarm3->setEnabled(true);
    ui->button_avatarm4->setEnabled(true);
}


void newGame::on_button_avatarf0_clicked()
{
    this->num_sprite = 0;
}

void newGame::on_button_avatarm0_clicked()
{
    this->num_sprite = 0;
}

void newGame::on_button_avatarf1_clicked()
{
    this->num_sprite = 1;
}

void newGame::on_button_avatarm1_clicked()
{
    this->num_sprite = 1;
}

void newGame::on_button_avatarf2_clicked()
{
    this->num_sprite = 2;
}

void newGame::on_button_avatarm2_clicked()
{
    this->num_sprite = 2;
}

void newGame::on_button_avatarf3_clicked()
{
    this->num_sprite = 3;
}

void newGame::on_button_avatarm3_clicked()
{
    this->num_sprite = 3;
}

void newGame::on_button_avatarf4_clicked()
{
    this->num_sprite = 4;
}

void newGame::on_button_avatarm4_clicked()
{
    this->num_sprite = 4;
}



void newGame::on_button_cancelar_clicked()
{
    this->cancelado = true;
    this->close();
}

void newGame::on_button_ok_clicked()
{
    string nombre = ui->lineEdit_nombre->text().toStdString();
    bool genero;
    if(ui->rbutton_femenino->isChecked())
        genero = true;
    else
        genero = false;
    jugador = new Jugador(nombre,genero,num_sprite);
    this->cancelado = false;
    this->close();
}
