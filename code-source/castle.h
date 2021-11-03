#ifndef CASTLE_H
#define CASTLE_H

#include <QGraphicsPixmapItem>

class Castle : public QGraphicsPixmapItem
{
private:
        QString description;
public:
    Castle(QString description, QString imageFileName);
};

#endif // CASTLE_H
