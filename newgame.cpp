#include "newgame.h"
#include "ui_newgame.h"
#include "Jugador.h"
#include "mainwindow.h"
#include <string>
#include <sstream>
#include <QMessageBox>
using std::stringstream;
using std::string;

newGame::newGame(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newGame),
    cancelado(true),
    num_sprite(0)
{
    ui->setupUi(this);
    QPixmap bkgnd(":/Sprites/Background2.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    ui->comboBox_avatar->setIconSize(QSize(92,92));
    stringstream ss;
    const char* str;
    for(int i=0; i<10; i++){
        ss <<":/Sprites/Player" << i << ".png";
        str = ss.str().c_str();
        const QImage Logo(str);
        ss.str(string());
        ui->comboBox_avatar->insertItem(i,QPixmap::fromImage(Logo),ss.str().c_str());
        ss.str(string());
    }
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

void newGame::on_button_cancelar_clicked()
{
    this->cancelado = true;
    this->close();
}

void newGame::on_button_ok_clicked()
{
    if(ui->lineEdit_nombre->text().toStdString() != ""){
        string nombre = ui->lineEdit_nombre->text().toStdString();
        this->num_sprite = ui->comboBox_avatar->currentIndex();
        jugador = new Jugador(nombre,num_sprite);
        this->cancelado = false;
        this->close();
    }else{
        QMessageBox msgbox;
        msgbox.setBaseSize(QSize(250, 150));
        msgbox.setText("Favor ingrese un nombre para continuar");
        msgbox.exec();
    }
}
