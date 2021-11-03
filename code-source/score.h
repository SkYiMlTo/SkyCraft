#ifndef SCORE_H
#define SCORE_H

#include "gameend.h"

#include <QString>
#include <QFile>
#include <QString>

class Score
{
private:
    QString scoresFile;
    int findRank(float);
public:
    Score();
    int getNbLinesFile();
    void writeScore(QString, GameEnd *);
    void deleteAllScores();
    QString *getAllScores();
};

#endif // SCORE_H
