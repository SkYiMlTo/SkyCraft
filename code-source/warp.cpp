#include "warp.h"

Warp::Warp(QString description, QString imageFileName) : QGraphicsPixmapItem(QPixmap(imageFileName)), description(description)
{

}
