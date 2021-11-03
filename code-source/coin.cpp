#include "coin.h"

Coin::Coin(QString description, QString imageFileName) : QGraphicsPixmapItem(QPixmap(imageFileName)), description(description)
{

}
