#ifndef CHARACTER_H
#define CHARACTER_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QKeyEvent>

class Character : public QGraphicsPixmapItem
{
private:
    QString description;
    int speed;
    int speedVertical;

    bool right = false;
    bool left = false;
    bool moving = false;

    enum State {
             standing = 0,
             walkingRight,
             walkingLeft,
             jumping,
             combinedJumpWalkRight,
             combinedJumpWalkLeft
        };

    // Mario State
    State stateMario;

public:
    //Constructeur
    Character(QString description, QString imageFileName);

    // Getters
    int getSpeed() const { return speed; }
    const QString &getDescription() const { return this->description; }
    State getStateMario(){ return stateMario; }
    int getPosX(){return x(); }
    int getPosY(){return y(); }
    QString getDescription() {return description; }

    // Setters
    void setDescription(const QString &description) { this->description = description; }
    void setSpeed(int speed) { this->speed = speed; }
    void setStateMario(State newStateMario){ this->stateMario = newStateMario; }
    void setMarioStanding(){stateMario = standing; }

    // Méthodes
    void move();
    void receiveKeyPressed(QKeyEvent * event);
    void receiveKeyRelease(QKeyEvent *keyEvent);

};

#endif // CHARACTER_H
