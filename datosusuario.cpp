#include "datosusuario.h"
#include "ui_datosusuario.h"
#include "Jugador.h"
#include <vector>
#include <sstream>
#include <QStringListModel>
#include <QMessageBox>
#include "Pokemon.h"
#include <iostream>
using std::cout;
using std::endl;
using std::vector;
using std::stringstream;

DatosUsuario::DatosUsuario(Jugador* actual,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DatosUsuario),
    actual(actual),
    cancelado(false)
{
    ui->setupUi(this);

    QPixmap bkgnd(":/Sprites/Background9.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    stringstream ss;
    QString cadena;
    // llamar nombre
    cadena = QString::fromStdString(this->actual->getNombre());
    ui->lineEdit_nombre->setText(cadena);
    //llamar batallas ganadas
    ss << this->actual->getBatallasGanadas();
    cadena = QString::fromStdString(ss.str());
    ui->lineEdit_batallasGanadas->setText(cadena);
    ss.str(string());
    //llamar batallas perdidas
    ss << this->actual->getBatallasPerdidas();
    cadena = QString::fromStdString(ss.str());
    ui->lineEdit_batallasPerdidas->setText(cadena);
    ss.str(string());
    //llamar batallas totales
    ss << this->actual->getBatallasGanadas()+this->actual->getBatallasPerdidas();
    cadena = QString::fromStdString(ss.str());
    ui->lineEdit_batallasTotales->setText(cadena);
    ss.str(string());
    //llamar pokemon activos
    ss << this->actual->getPokedex().size();
    cadena = QString::fromStdString(ss.str());
    ui->lineEdit_pokemonActivos->setText(cadena);
    ss.str(string());
    //llamar pokemon retirados
    ss << this->actual->getTotalPokemon() - this->actual->getPokedex().size();
    cadena = QString::fromStdString(ss.str());
    ui->lineEdit_pokemonRetirados->setText(cadena);
    ss.str(string());
    //llamar total pokemon
    ss << this->actual->getTotalPokemon();
    cadena = QString::fromStdString(ss.str());
    ui->lineEdit_totalPokemon->setText(cadena);
    ss.str(string());

    ui->comboBox_avatar->setIconSize(QSize(92,92));
    const char* str;
    for(int i=0; i<10; i++){
        ss <<":/Sprites/Player" << i << ".png";
        str = ss.str().c_str();
        const QImage Logo(str);
        ss.str(string());
        ui->comboBox_avatar->insertItem(i,QPixmap::fromImage(Logo),ss.str().c_str());
        ss.str(string());
    }

    QStringListModel *model = new QStringListModel(this);
    QStringList List;
    QString qstr;
    for(int i=0; i<(int)this->actual->getPokedex().size(); i++){
        qstr = QString::fromStdString(this->actual->getPokedex()[i]->toString());
        List << qstr;
    }
    model->setStringList(List);
    ui->comboBox_retirarPokemon->setModel(model);

    num_sprite = this->actual->getSpriteNum();
    str = (this->actual->getSprite()).c_str();
    QImage Logo(str);
    ui->lable_sprite->setPixmap(QPixmap::fromImage(Logo));

}

DatosUsuario::~DatosUsuario()
{
    delete ui;
}

bool DatosUsuario::getCancelado()const{
    return cancelado;
}

void DatosUsuario::on_button_guardar_clicked()
{
    this->cancelado = false;
    actual->setNombre(ui->lineEdit_nombre->text().toStdString());
    actual->setSprite(num_sprite);
    this->close();
}

void DatosUsuario::on_button_cancelar_clicked()
{
    this->cancelado = true;
    this->close();
}


void DatosUsuario::on_comboBox_avatar_currentIndexChanged(int index)
{
    stringstream ss;
    ss << ":/Sprites/Player" << index << ".png";
    const char* str = ss.str().c_str();
    QImage Logo(str);
    ui->lable_sprite->setPixmap(QPixmap::fromImage(Logo));
    num_sprite = ui->comboBox_avatar->currentIndex();

}

void DatosUsuario::on_button_retirar_clicked()
{
    stringstream ss;
    QMessageBox msgbox;
    msgbox.setBaseSize(QSize(500, 150));
    msgbox.setWindowTitle("Retirar Pokemon");
    ss << "Esta seguro que desea retirar a " << (actual->getPokedex())[ui->comboBox_retirarPokemon->currentIndex()]->toString() << "?";
    msgbox.setText(ss.str().c_str());
    msgbox.setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
    msgbox.setDefaultButton(QMessageBox::Cancel);
    if(msgbox.exec() == QMessageBox::Yes){
        ss.str(string());
        ss << (actual->getPokedex())[ui->comboBox_retirarPokemon->currentIndex()]->toString() << " ha sido retirado.";
        msgbox.setText(ss.str().c_str());
        msgbox.setStandardButtons(QMessageBox::Ok);
        msgbox.setDefaultButton(QMessageBox::Ok);
        msgbox.exec();
        vector<Pokemon*>::iterator ret1 = actual->getPokedex().begin();
        int ret = ui->comboBox_retirarPokemon->currentIndex();
        cout << ret << " " << actual->getPokedex().size() << endl;
        actual->getPokedex().erase(ret1 +ret);
        cout << actual->getPokedex().size() << endl;

        QStringListModel *model = new QStringListModel(this);
        QStringList List;
        QString qstr;
        for(int i=0; i<(int)this->actual->getPokedex().size(); i++){
            qstr = QString::fromStdString(this->actual->getPokedex()[i]->toString());
            List << qstr;
        }
        model->setStringList(List);
        ui->comboBox_retirarPokemon->setModel(model);
    }
}
