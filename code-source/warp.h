#ifndef WARP_H
#define WARP_H

#include <QGraphicsPixmapItem>

class Warp : public QGraphicsPixmapItem
{
private:
    QString description;
public:
    QString getDescription() {return description; }
    Warp(QString description, QString imageFileName);
};

#endif // WARP_H
