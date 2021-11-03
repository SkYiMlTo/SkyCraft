#include "score.h"
#include "gameend.h"

#include <QString>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <string.h>

Score::Score()
{
    scoresFile = "./scores.txt";
}

int Score::findRank(float value)
{
    // Use this function to find rank of a score in the scores.txt file
    int rank = 1;
    QFile file(scoresFile);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream flux(&file);
    QStringList line;
    while(! flux.atEnd())
    {
        line = flux.readLine().split(";");
        if(line[1].toFloat() > value)
            rank++;
    }
    file.close();
    return rank;
}

int Score::getNbLinesFile()
{
    // Return nb of line in scores.txt (know how many scores there is in)
    QFile file(scoresFile);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream flux(&file);
    int nbOfLines = 0;
    while(! flux.atEnd())
    {
        QString monstring = file.readLine();
        nbOfLines++;
    }
    file.close();
    return nbOfLines;
}

void Score::writeScore(QString username, GameEnd * gameEndItem)
{
    // If user leave the Username field empty we put "DefaultUser"
    if(username == "")
        username = "DefaultUser";

    QFile file(scoresFile); // Call constructor of QFile

    if (file.open(QIODevice::Append | QIODevice::Text)) {

    // If open in writing mode success
        QString semicolon = ";";
        QString myChain = username + semicolon + QString::number(10000 - (100*gameEndItem->getFianalTime()) + (50*gameEndItem->getNbCoins())) + semicolon + QString::number(gameEndItem->getFianalTime()) + semicolon + QString::number(gameEndItem->getNbCoins()) + semicolon + gameEndItem->getDate() + "\n";
        file.write(myChain.toStdString().c_str());

    // Close file
    file.close();
    }
}

void Score::deleteAllScores()
{
    // Empty scores.txt file
    QFile file(scoresFile); // Call constructor of QFile
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
    file.close();
    }
}

QString *Score::getAllScores()
{
    // Method to use for display scores in LeaderBoard

    // Recover scores in the scores.txt file
    QFile file(scoresFile);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream flux(&file);
    QString line;
    QString* array = new QString[getNbLinesFile()];
    int rank = 0;

    //We write every score order from best to worst in an array
    while(! flux.atEnd())
    {
        line = flux.readLine();
        float value = line.split(";")[1].toFloat();
        rank = findRank(value);
        int indice = 0;
        while(true){
            if(array[rank-1+indice] == ""){
                array[rank-1+indice] = line;
                break;
            }
            else
                indice++;
        }
    }

    // Close scores.txt
    file.close();

    // Return the array (created) to display
    return array;
}
