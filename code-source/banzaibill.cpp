#include "banzaibill.h"

#include <QTimer>
#include <QObject>
#include <QDebug>

using namespace std;

BanzaiBill::BanzaiBill(QString description, QString imageFileName, int speed) : QGraphicsPixmapItem(QPixmap(imageFileName)), description(description), speed(speed)
{

}

void BanzaiBill::move(){
    // Update BanzaiBill position
    QPointF pos = this->pos();
    this->setPos(pos.x(), pos.y() - speed);
}

int BanzaiBill::getPosY()
{
    // Return y position of object
    return this->pos().y();
}
