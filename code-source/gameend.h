#ifndef GAMEEND_H
#define GAMEEND_H

#include <QSlider>
#include <QDateTime>
#include <QDebug>

class GameEnd
{
private:
    int death;
    int win;
    int gameTime;
    int nbCoins;
    int stateSliderCoins;
    long long timeStart;
    float ellapsedTime;
    float finalTime;
    QString date;
    bool isInPause;
    float timeInPause = 0;
    long long timeStartPause;
    long long timeEndPause;
    bool init;

    bool gameIsPaused;
public:
    QSlider* mySliderWin;
    QSlider* mySliderLose;
    QSlider* mySliderGameTime;
    QSlider* mySliderCoins;

    // getters
    int getDeath(){ return death; }
    int getWin(){ return win; }
    float getEllapsedTime(){return ellapsedTime; }
    float getFianalTime(){return finalTime; }
    QString getDate() {return date; }
    int getNbCoins(){return nbCoins; }
    bool getGameIsPaused(){return gameIsPaused; }

    // setter
    void setIsInPause(bool val);
    void setNbCoins(int val){nbCoins = val; }
    void setGameIsPaused(bool val){ gameIsPaused = val; }

    // méthodes
    GameEnd();
    void playerWon();
    void playerLost();
    void resetObject();
    void setTimeStart();
    void timeEllapsed();
    void timeEllapsedInPause();
    void timeFinal();
    void addCoin();
};

#endif // GAMEEND_H
