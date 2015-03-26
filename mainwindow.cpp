#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "newgame.h"
#include "loadGame.h"
#include "ui_loadGame.h"
#include "ui_newgame.h"
#include "Jugador.h"
#include "playerGame.h"
#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    cuentas(0)
{
    ui->setupUi(this);
    QPixmap bkgnd(":/Sprites/Background.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    QImage Logo(":/Sprites/Logo.png");
    ui->label_logo->setPixmap(QPixmap::fromImage(Logo));

    if(cuentas == 0)
        ui->button_load->setEnabled(false);
    else
        ui->button_load->setEnabled(true);
    if(cuentas >= 10)
        ui->button_new->setEnabled(false);
    else
       ui->button_new->setEnabled(true);
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_button_exit_clicked()
{
    exit(0);
}

void MainWindow::on_button_new_clicked()
{
    newGame* ngame = new newGame(this);
    ngame->exec();
    if(!ngame->ifCancelado()){
        this->setNewPlayer(ngame->getNewJugador());
        ui->button_load->setEnabled(true);
    }
}

void MainWindow::on_button_load_clicked()
{
    LoadGame* lgame = new LoadGame(jugadores,cuentas,this);
    lgame->exec();
    if(!lgame->isCancelado()){
        this->partidaActual = jugadores[lgame->getCurrentGame()];
        PlayerGame* ventanaPartidaActual = new PlayerGame(partidaActual,this);
        ventanaPartidaActual->exec();
    }else {
        if(lgame->isEliminado()){
            jugadores[lgame->getCurrentGame()] = jugadores[cuentas];
            jugadores[cuentas] = NULL;
            cuentas--;
        }
    }
}

void MainWindow::setNewPlayer(Jugador* newPlayer){
    jugadores[cuentas++] = newPlayer;
}
