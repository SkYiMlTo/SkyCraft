#ifndef BANZAIBILL_H
#define BANZAIBILL_H

#include <QGraphicsPixmapItem>
#include <QTimer>

#include <QObject>

class BanzaiBill  : public QGraphicsPixmapItem
{
private:
    QString description;
    QTimer* timer;
    int speed;
public:
    BanzaiBill(QString description, QString imageFileName, int speed);
    void move();

    //getter
    int getPosY();
};
#endif // BANZAIBILL_H
