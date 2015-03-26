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
    newGame* newgame = new newGame(this);
    newgame->exec();
    if(!newgame->ifCancelado()){
        this->setNewPlayer(newgame->getNewJugador());
        ui->button_load->setEnabled(true);
    }
}

void MainWindow::on_button_load_clicked()
{
    LoadGame* loadgame = new LoadGame(jugadores,cuentas,this);
    loadgame->exec();
    if(!loadgame->isCancelado()){
        this->partidaActual = jugadores[loadgame->getCurrentGame()];
        PlayerGame* ventanaPartidaActual = new PlayerGame(partidaActual,this);
        ventanaPartidaActual->exec();
    }else {
        if(loadgame->isEliminado()){
            jugadores[loadgame->getCurrentGame()] = jugadores[cuentas];
            jugadores[cuentas] = NULL;
            cuentas--;
            if(cuentas == 0){
                ui->button_load->setEnabled(false);
            }
        }
    }
}

void MainWindow::setNewPlayer(Jugador* newPlayer){
    jugadores[cuentas++] = newPlayer;
}
