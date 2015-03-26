#include "loadGame.h"
#include "ui_loadGame.h"
#include <QStringListModel>
#include "Jugador.h"
#include <QString>
#include <iostream>
#include <QMessageBox>
#include <sstream>
using std::stringstream;

LoadGame::LoadGame(Jugador** jugadores,int num_cuentas, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoadGame),
    cancelado(false),
    eliminado(false)
{
    this->jugadores = new Jugador*[num_cuentas];
    for(int i=0; i<num_cuentas; i++){
        this->jugadores[i] = jugadores[i];
    }
    ui->setupUi(this);

    QStringListModel *model = new QStringListModel(this);
    QStringList List;
    QString str;
    for(int i=0; i<num_cuentas; i++){
        str = QString::fromStdString(jugadores[i]->toString());
        List << str;
    }
    model->setStringList(List);
    ui->combo_savedGames->setModel(model);

    QPixmap bkgnd(":/Sprites/Background3.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

}

LoadGame::~LoadGame()
{
    delete ui;
}

bool LoadGame::isCancelado()const{
    return cancelado;
}

bool LoadGame::isEliminado()const{
    return eliminado;
}

int LoadGame::getCurrentGame()const{
    return juego;
}

void LoadGame::on_combo_savedGames_currentIndexChanged(int index)
{
    const char* str = (jugadores[index]->getSprite()).c_str();
    QImage Logo(str);
    ui->image->setPixmap(QPixmap::fromImage(Logo));
}

void LoadGame::on_button_ok_clicked()
{
    juego = ui->combo_savedGames->currentIndex();
    if(juego == -1)
        juego =0;
    this->cancelado = false;
    this->close();
}

void LoadGame::on_button_cancelar_clicked()
{
    this->cancelado = true;
    this->close();
}

void LoadGame::on_button_eliminar_clicked()
{
    stringstream ss;
    QMessageBox msgbox;
    msgbox.setBaseSize(QSize(500, 150));
    msgbox.setWindowTitle("Eliminar Juego");
    ss << "Esta seguro que desea el juego " << jugadores[ui->combo_savedGames->currentIndex()]->toString() << "?";
    msgbox.setText(ss.str().c_str());
    msgbox.setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
    msgbox.setDefaultButton(QMessageBox::Cancel);
    if(msgbox.exec() == QMessageBox::Yes){
        ss.str(string());
        ss << jugadores[ui->combo_savedGames->currentIndex()]->toString() << " ha sido eliminado.";
        msgbox.setText(ss.str().c_str());
        msgbox.setStandardButtons(QMessageBox::Ok);
        msgbox.setDefaultButton(QMessageBox::Ok);
        msgbox.exec();
        this->juego = ui->combo_savedGames->currentIndex();
        this->eliminado = true;
        this->cancelado = true;
        this->close();
    }
}
