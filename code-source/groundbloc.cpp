#include "groundbloc.h"

GroundBloc::GroundBloc(QString description, QString imageFileName) : QGraphicsPixmapItem(QPixmap(imageFileName)), description(description)
{
    currentState = standing;
}
