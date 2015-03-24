#ifndef BATTALLA_H
#define BATTALLA_H

#include <QDialog>

namespace Ui {
class Battalla;
}

class Battalla : public QDialog
{
    Q_OBJECT

public:
    explicit Battalla(QWidget *parent = 0);
    ~Battalla();

private:
    Ui::Battalla *ui;
};

#endif // BATTALLA_H
