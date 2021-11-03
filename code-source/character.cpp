#include "character.h"

#include <QKeyEvent>
#include <QDebug>
#include <QWidget>

Character::Character(QString description, QString imageFileName) : QGraphicsPixmapItem(QPixmap(imageFileName)), description(description) {
    this->speed = 0;
    this->speedVertical = 0;
    this->stateMario = standing;

}

void Character::receiveKeyPressed(QKeyEvent *keyEvent)
{
    // Actions when a key is pressed
    if(keyEvent->key() == Qt::Key_Up || (keyEvent->key() == Qt::Key_Up && keyEvent->isAutoRepeat()) || keyEvent->key() == Qt::Key_Z || (keyEvent->key() == Qt::Key_Z && keyEvent->isAutoRepeat()))
        {
            moving = true;
            stateMario = jumping;
            if(right)
            {
                stateMario = combinedJumpWalkRight;
            }
            if(left)
            {
                stateMario = combinedJumpWalkLeft;
            }
        }
    if (keyEvent->key() == Qt::Key_Right || keyEvent->key() == Qt::Key_D)
        {
            right = true;
            stateMario = walkingRight;
            if(moving)
            {
                stateMario = combinedJumpWalkRight;
            }
        }
    if (keyEvent->key() == Qt::Key_Left || keyEvent->key() == Qt::Key_Q)
        {
            left = true;
            stateMario = walkingLeft;
            if(moving)
            {
                stateMario = combinedJumpWalkLeft;
            }
        }
}

void Character::receiveKeyRelease(QKeyEvent *keyEvent)
{
    // Actions when a key is released
    if(keyEvent->key() == Qt::Key_Up || keyEvent->key() == Qt::Key_Z)
         {
            if (stateMario == 4){
                stateMario = walkingRight;
            } else if (stateMario == 5){
                stateMario = walkingLeft;
            } else{
                stateMario = standing;
            }
            moving = false;
         }
    if (keyEvent->key() == Qt::Key_Right || keyEvent->key() == Qt::Key_D)
         {
            right = false;
            stateMario = standing;
         }
    if (keyEvent->key() == Qt::Key_Left || keyEvent->key() == Qt::Key_Q)
         {
            left = false;
            stateMario = standing;
         }
}
