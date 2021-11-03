#include "gameend.h"


#include <QDateTime>
#include <QDebug>
#include <iostream>
#include <cmath>

using namespace std;

// Object to use for make connexion between the main window
// and the game scene

void GameEnd::setIsInPause(bool val)
{
    if(val)
        timeStartPause = (long long)(QDateTime::currentMSecsSinceEpoch());
    else{
        if(!init){
            timeEndPause = (long long)(QDateTime::currentMSecsSinceEpoch());
            timeEllapsedInPause();
        }else{
            init = false;
        }
    }
    isInPause = val;
}

GameEnd::GameEnd()
{
    mySliderWin = new QSlider(Qt::Horizontal);
    mySliderWin->setValue(0);
    mySliderLose = new QSlider(Qt::Horizontal);
    mySliderWin->setValue(0);
    mySliderGameTime = new QSlider(Qt::Horizontal);
    mySliderGameTime->setValue(0);
    nbCoins = 0;
    mySliderCoins = new QSlider(Qt::Horizontal);
    mySliderCoins->setValue(1);
    win = 0;
    death = 0;
    isInPause = false;
    timeInPause = 0;
    init = true;
    gameIsPaused = false;
}

void GameEnd::playerWon()
{
    win = 1;
    mySliderWin->setValue(win);
}

void GameEnd::playerLost()
{
    death = 1;
    mySliderLose->setValue(death);
}

void GameEnd::resetObject()
{
    win = 0;
    mySliderWin->setValue(win);

    death = 0;
    mySliderLose->setValue(death);

    timeInPause = 0;
    init = true;
}

void GameEnd::setTimeStart()
{
    timeStart = (long long)(QDateTime::currentMSecsSinceEpoch());
    timeInPause = 0;
}

void GameEnd::timeEllapsed()
{
    long long timeNow = (long long)(QDateTime::currentMSecsSinceEpoch());
    ellapsedTime = round((int(timeNow - timeStart))/10)/100 - timeInPause;
    if(mySliderGameTime->value() == 0)
        mySliderGameTime->setValue(1);
    else
        mySliderGameTime->setValue(0);
}

void GameEnd::timeEllapsedInPause()
{
    timeInPause += round((int(timeEndPause - timeStartPause))/10)/100;
}

void GameEnd::timeFinal()
{
    // Save final time user done
    long long timeNow = (long long)(QDateTime::currentMSecsSinceEpoch());
    finalTime = round((int(timeNow - timeStart))/10)/100 - timeInPause;
    date = QDateTime::currentDateTime().toString("dd MMMM yyyy hh:mm:ss");
}

void GameEnd::addCoin()
{
    // Add coin user picked
    nbCoins++;
    if(stateSliderCoins){
        stateSliderCoins = 0;
        mySliderCoins->setValue(stateSliderCoins);
    } else{
        stateSliderCoins = 1;
        mySliderCoins->setValue(stateSliderCoins);
    }
}
