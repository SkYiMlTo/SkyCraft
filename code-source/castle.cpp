#include "castle.h"

Castle::Castle(QString description, QString imageFileName) : QGraphicsPixmapItem(QPixmap(imageFileName)), description(description)
{

}
