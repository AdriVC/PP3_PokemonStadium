#include "battalla.h"
#include "ui_battalla.h"

Battalla::Battalla(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Battalla)
{
    ui->setupUi(this);
    QPixmap bkgnd(":/Sprites/Background5.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

Battalla::~Battalla()
{
    delete ui;
}
