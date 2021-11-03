#ifndef GROUNDBLOC_H
#define GROUNDBLOC_H

#include <QGraphicsPixmapItem>

class GroundBloc : public QGraphicsPixmapItem
{
private:

    enum StateBloc {
             standing = 0,
             falling
        };

    StateBloc currentState;
    QString description;

public:
    GroundBloc(QString description, QString imageFileName);
    QString getDescription() {return description; }
};

#endif // GROUNDBLOC_H
