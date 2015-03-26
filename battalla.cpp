#include "battalla.h"
#include "ui_battalla.h"
#include "Movida.h"
#include <sstream>
#include <QMessageBox>
#include <cstdlib>
#include <ctime>
using std::stringstream;
using std::srand;
using std::time;

Battalla::Battalla(Pokemon* usuario,Pokemon* oponente,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Battalla),
    usuario(usuario),
    oponente(oponente),
    efectividadUsuario(1.0),
    efectividadOponente(1.0),
    plot(""),
    ganoUsuario(false),
    huyo(false)
{
    srand(time(0));
    ui->setupUi(this);
    QPixmap bkgnd(":/Sprites/Background5.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    this->usuarioHpInicial = usuario->getHp();
    this->oponenteHpInicial = oponente->getHp();
    if(usuario->getVentaja() == this->oponente->getClass()){
        this->efectividadUsuario = 2.0;
    }else if(usuario->getDebilidad() == this->oponente->getClass()){
        this->efectividadUsuario = 0.5;
    }
    if(oponente->getVentaja() == this->usuario->getClass()){
        this->efectividadUsuario = 2.0;
    }else if(oponente->getDebilidad() == this->usuario->getClass()){
        this->efectividadUsuario = 0.5;
    }

    const char* path = (this->oponente->getSprite()).c_str();
    QImage Logo(path);
    ui->lable_oponenteSprite->setPixmap(QPixmap::fromImage(Logo));

    path = (this->usuario->getBackSprite()).c_str();
    QImage Logo2(path);
    ui->lable_usuarioSprite->setPixmap(QPixmap::fromImage(Logo2));

    QString cadena;
    cadena = QString::fromStdString(this->oponente->getNombre());
    ui->lable_oponenteNombre->setText(cadena);
    cadena = QString::fromStdString("");
    stringstream ss;
    ss << "Lv " << this->oponente->getNivel();
    cadena = QString::fromStdString(ss.str());
    ui->lable_oponenteNivel->setText(cadena);
    ui->progress_oponenteHp->setMaximum(this->oponenteHpInicial);
    ui->progress_oponenteHp->setValue(this->oponente->getHp());
    ss.str("");
    cadena = QString::fromStdString(this->usuario->getNombre());
    ui->lable_usuarioNombre->setText(cadena);
    cadena = QString::fromStdString("");
    ss.str(string());
    ss << "Lv " << this->usuario->getNivel();
    cadena = QString::fromStdString(ss.str());
    ui->lable_usuarioNivel->setText(cadena);
    ui->progress_usuarioHp->setMaximum(this->usuarioHpInicial);
    ui->progress_usuarioHp->setValue(this->usuario->getHp());
    ss.str("");
    ss << "A BATALLAR!!";
    cadena = QString::fromStdString(ss.str());
    ui->textEdit_plot->appendPlainText(cadena);

    ss.str(string());
    ss << this->usuario->attack(efectividadUsuario).getNombre();
    ui->button_ataque->setText(ss.str().c_str());
    ss.str(string());
    ss << this->usuario->defend(efectividadUsuario).getNombre();
    ui->button_defensa->setText(ss.str().c_str());
    ss.str(string());
    ss << this->usuario->hiddenSkill(efectividadUsuario).getNombre();
    ui->button_habilidad->setText(ss.str().c_str());

}

Battalla::~Battalla()
{
    delete ui;
}

bool Battalla::getResultadoUsuario()const{
    return ganoUsuario;
}

bool Battalla::getHuyo()const{
    return huyo;
}

double Battalla::getBonoVictoria(){
    return 1.05;
}

void Battalla::pokemonRetirado(){
    stringstream ss;
    QMessageBox msgbox;
    msgbox.setBaseSize(QSize(500, 200));
    if(this->usuario->getHp() <= (int)((double)usuarioHpInicial*0.05)){
        ganoUsuario = false;
        ss << "\nUsted ha perdido y su pokemon ha quedado retirado!";
        QString cadena = QString::fromStdString(ss.str());
        ui->textEdit_plot->appendPlainText(cadena);
        this->plot = ui->textEdit_plot->toPlainText();
        ss.str(string());
        msgbox.setWindowTitle("Batalla Perdida");
        ss << this->usuario->getNombre() << " no ha podido vencer a " << this->oponente->getNombre() << "\n Ha quedado retirado..";
        msgbox.setText(ss.str().c_str());
        msgbox.exec();
        this->close();
    }
    if(this->oponente->getHp() <= (int)((double)oponenteHpInicial*0.05)){
        ganoUsuario = true;
        ss << "\n" << this->oponente->getNombre() << " ha perdido contra su " << this->usuario->getNombre() << "\nFelicidades!";
        QString cadena = QString::fromStdString(ss.str());
        ui->textEdit_plot->appendPlainText(cadena);
        this->plot = ui->textEdit_plot->toPlainText();
        ss.str(string());
        msgbox.setWindowTitle("Batalla Ganada");
        ss << this->usuario->getNombre() << " ha podido vencer a " << this->oponente->getNombre() << "\nFelicidades!";
        msgbox.setText(ss.str().c_str());
        msgbox.exec();
        this->close();
    }
}

void Battalla::ataqueOponente(){
    int movimiento = rand()%5;
    if(movimiento == 0){

        this->usuario->setHp(this->oponente->tackle().getGolpe());
        ui->progress_usuarioHp->setValue(this->usuario->getHp());
        this->oponente->setHp(this->oponente->tackle().getAyuda());
        ui->progress_oponenteHp->setValue(this->oponente->getHp());
        stringstream ss;
        ss << oponente->getNombre() << usuario->tackle().toString();
        QString cadena = QString::fromStdString(ss.str());
        ui->textEdit_plot->appendPlainText(cadena);
        this->pokemonRetirado();

    }else if(movimiento == 1){

        this->usuario->setHp(this->oponente->curl().getGolpe());
        ui->progress_usuarioHp->setValue(this->usuario->getHp());
        this->oponente->setHp(this->oponente->curl().getAyuda());
        ui->progress_oponenteHp->setValue(this->oponente->getHp());
        stringstream ss;
        ss << oponente->getNombre() << this->usuario->curl().toString();
        QString cadena = QString::fromStdString(ss.str());
        ui->textEdit_plot->appendPlainText(cadena);
        this->pokemonRetirado();

    }else if(movimiento == 2){

        this->usuario->setHp(this->oponente->attack(efectividadOponente).getGolpe());
        ui->progress_usuarioHp->setValue(this->usuario->getHp());
        this->oponente->setHp(this->oponente->attack(efectividadOponente).getAyuda());
        ui->progress_oponenteHp->setValue(this->oponente->getHp());
        stringstream ss;
        ss << this->oponente->getNombre() << this->oponente->attack(efectividadOponente).toString();
        QString cadena = QString::fromStdString(ss.str());
        ui->textEdit_plot->appendPlainText(cadena);
        this->pokemonRetirado();

    }else if(movimiento == 3){

        this->usuario->setHp(this->oponente->defend(efectividadOponente).getGolpe());
        ui->progress_usuarioHp->setValue(this->usuario->getHp());
        this->oponente->setHp(this->oponente->defend(efectividadOponente).getAyuda());
        ui->progress_oponenteHp->setValue(this->oponente->getHp());
        stringstream ss;
        ss << this->oponente->getNombre() << this->oponente->defend(efectividadOponente).toString();
        QString cadena = QString::fromStdString(ss.str());
        ui->textEdit_plot->appendPlainText(cadena);
        this->pokemonRetirado();

    }else{

        this->usuario->setHp(this->oponente->hiddenSkill(efectividadOponente).getGolpe());
        ui->progress_usuarioHp->setValue(this->usuario->getHp());
        this->oponente->setHp(this->oponente->hiddenSkill(efectividadOponente).getAyuda());
        ui->progress_oponenteHp->setValue(this->oponente->getHp());
        stringstream ss;
        ss << this->oponente->getNombre() << this->oponente->hiddenSkill(efectividadOponente).toString();
        QString cadena = QString::fromStdString(ss.str());
        ui->textEdit_plot->appendPlainText(cadena);
        this->pokemonRetirado();

    }
}


void Battalla::on_button_tackle_clicked()
{
    this->oponente->setHp(this->usuario->tackle().getGolpe());
    ui->progress_oponenteHp->setValue(this->oponente->getHp());
    this->usuario->setHp(this->usuario->tackle().getAyuda());
    ui->progress_usuarioHp->setValue(this->usuario->getHp());
    stringstream ss;
    ss << "\nUsted " << usuario->tackle().toString();
    QString cadena = QString::fromStdString(ss.str());
    ui->textEdit_plot->appendPlainText(cadena);
    this->ataqueOponente();
}

void Battalla::on_button_curl_clicked()
{
    this->oponente->setHp(this->usuario->curl().getGolpe());
    ui->progress_oponenteHp->setValue(this->oponente->getHp());
    this->usuario->setHp(this->usuario->curl().getAyuda());
    ui->progress_usuarioHp->setValue(this->usuario->getHp());
    stringstream ss;
    ss << "\nUsted " << this->usuario->curl().toString();
    QString cadena = QString::fromStdString(ss.str());
    ui->textEdit_plot->appendPlainText(cadena);
    this->ataqueOponente();
}

void Battalla::on_button_ataque_clicked()
{
    this->oponente->setHp(this->usuario->attack(efectividadUsuario).getGolpe());
    ui->progress_oponenteHp->setValue(this->oponente->getHp());
    this->usuario->setHp(this->usuario->attack(efectividadUsuario).getAyuda());
    ui->progress_usuarioHp->setValue(this->usuario->getHp());
    stringstream ss;
    ss << "\nUsted " << this->usuario->attack(efectividadUsuario).toString();
    QString cadena = QString::fromStdString(ss.str());
    ui->textEdit_plot->appendPlainText(cadena);
    this->ataqueOponente();
}

void Battalla::on_button_defensa_clicked()
{
    this->oponente->setHp(this->usuario->defend(efectividadUsuario).getGolpe());
    ui->progress_oponenteHp->setValue(this->oponente->getHp());
    this->usuario->setHp(this->usuario->defend(efectividadUsuario).getAyuda());
    ui->progress_usuarioHp->setValue(this->usuario->getHp());
    stringstream ss;
    ss << "\nUsted " << this->usuario->defend(efectividadUsuario).toString();
    QString cadena = QString::fromStdString(ss.str());
    ui->textEdit_plot->appendPlainText(cadena);
    this->ataqueOponente();
}

void Battalla::on_button_habilidad_clicked()
{
    this->oponente->setHp(this->usuario->hiddenSkill(efectividadUsuario).getGolpe());
    ui->progress_oponenteHp->setValue(this->oponente->getHp());
    this->usuario->setHp(this->usuario->hiddenSkill(efectividadUsuario).getAyuda());
    ui->progress_usuarioHp->setValue(this->usuario->getHp());
    stringstream ss;
    ss << "\nUsted " << this->usuario->hiddenSkill(efectividadUsuario).toString();
    QString cadena = QString::fromStdString(ss.str());
    ui->textEdit_plot->appendPlainText(cadena);
    this->ataqueOponente();
}

void Battalla::on_button_huir_clicked()
{
    stringstream ss;
    QMessageBox msgbox;
    ss << "\nUsted huyo...";
    QString cadena = QString::fromStdString(ss.str());
    ui->textEdit_plot->appendPlainText(cadena);
    this->plot = ui->textEdit_plot->toPlainText();
    ss.str(string());
    msgbox.setWindowTitle("Batalla Perdida");
    ss << "Ha huido del " << this->oponente->getNombre();
    msgbox.setText(ss.str().c_str());
    msgbox.exec();
    this->huyo = true;
    this->close();
}
