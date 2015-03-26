#include "loadpokemon.h"
#include "ui_loadpokemon.h"
#include "Pokemon.h"
#include <vector>
#include <QStringListModel>

loadPokemon::loadPokemon(vector<Pokemon*> lista,Pokemon* oponente, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loadPokemon),
    lista(lista),
    oponente(oponente),
    cancelado(false),
    num_pokemon(0)
{
    ui->setupUi(this);

    QPixmap bkgnd(":/Sprites/Background9.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    QStringListModel *model = new QStringListModel(this);
    QStringList List;
    QString qstr;
    for(int i=0; i<(int)lista.size(); i++){
        qstr = QString::fromStdString(lista[i]->toString());
        List << qstr;
    }
    model->setStringList(List);
    ui->combo_usuarioPokemon->setModel(model);

    qstr = QString::fromStdString(this->oponente->toString());
    ui->lineEdit_oponentePokemon->setText(qstr);

    const char* str = (this->oponente->getSprite()).c_str();
    QImage Logo(str);
    ui->lable_spriteOponente->setPixmap(QPixmap::fromImage(Logo));
}

loadPokemon::~loadPokemon()
{
    delete ui;
}

int loadPokemon::getNumPokemon()const{
    return this->num_pokemon;
}

bool loadPokemon::getCancelado()const{
    return this->cancelado;
}
Pokemon* loadPokemon::getOponente()const{
    return this->oponente;
}

void loadPokemon::on_combo_usuarioPokemon_currentIndexChanged(int index)
{
    const char* str = (lista[index]->getSprite()).c_str();
    QImage Logo(str);
    ui->lable_spriteUsuario->setPixmap(QPixmap::fromImage(Logo));
}

void loadPokemon::on_button_cancelar_clicked()
{
    this->cancelado = true;
    this->close();
}

void loadPokemon::on_button_listo_clicked()
{
    this->num_pokemon = ui->combo_usuarioPokemon->currentIndex();
    if(this->num_pokemon == -1)
        this->num_pokemon =0;
    this->cancelado = false;
    this->close();
}
