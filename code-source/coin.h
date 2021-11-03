#ifndef COIN_H
#define COIN_H

#include <QGraphicsPixmapItem>

class Coin  : public QGraphicsPixmapItem
{
private:
    QString description;
public:
    Coin(QString description, QString imageFileName);
    QString getDescription() {return description; }
};

#endif // COIN_H
