#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QGraphicsView>

#include "character.h"
#include "gamescene.h"
#include "gameend.h"
#include "score.h"
#include "song.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

#include <QtWidgets/QPushButton>
#include <QLabel>

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:

    // User Interface
    Ui::MainWindow *ui;

    // Know which display is on screen (current view)
    int windowView;

    // Main menu buttons
    QPushButton* buttonPlay;
    QPushButton* buttonLeaderBoard;
    QPushButton* buttonSettings;
    QPushButton* buttonCredits;
    QPushButton* buttonExit;

    // Game button + timer
    QPushButton* buttonPause;
    QTimer* timer;
    GameScene* mainSceneGame;
    QGraphicsView* mainViewGame;
    QGraphicsView* mainViewGlobal;
    bool isMainSceneGameDeclared = false;

    // Leaderboard buttons + label + bool
    QPushButton* buttonBackMenuFromLeaderBoard;
    QPushButton* buttonResetLeaderboard;
    QLabel* textLeaderboard;
    bool boolConfirmEraseLeaderboard = false;

    // Settings button
    QPushButton* buttonBackMenuFromSettings;

    // Credits button
    QPushButton* buttonBackMenuFromCredits;

    // Quit buttons + label
    QPushButton* buttonBackMenuFromQuit;
    QPushButton* buttonQuitGame;
    QLabel* textQuit;

    // Pause buttons + bool
    QPushButton* buttonResume;
    QPushButton* buttonBackMenuFromPause;
    QPushButton* buttonRestart;
    bool comeFromPause = false;

    // End a game object + bool
    GameEnd* gameEndItem;
    bool resetingGameEndItem = false;

    // Win labels + buttons + bools
    QLabel* textWin;
    QLabel* textTime;
    QLabel* textCoins;
    QLabel* textScore;
    QLabel* textName;
    QPushButton* buttonReplay;
    QPushButton* buttonBackMenuFromWin;
    bool comeFromWin = false;
    bool boolSongWinNotplayed = true;

    // Lose buttons + bools
    QPushButton* buttonRetry;
    QPushButton* buttonBackMenuFromLose;
    bool comeFromLose = false;
    bool boolSongLoseNotplayed = true;

    // Score object
    Score* scoreItem;

    // Array with all buttons
    Song* playerItem;

    // Initialisations
    void initImages();
    void initGameEndItem();
    void initButtons(int, int, int, const QFont);
    void initConnects();
    void initGameScene();
    void initLabels(int, int, int);
    void initScoreItem();

public:
    MainWindow(QWidget *parent = nullptr);
    void keyPressEvent(QKeyEvent * event);
    void keyReleaseEvent(QKeyEvent *keyEvent);
    ~MainWindow();

public slots:
    void displayMenu();
    void displayLeaderBoard();
    void displayGame();
    void displayPause();
    void displaySettings();
    void displayCredits();
    void displayQuit();
    void displayWin();
    void displayLose();
    void retry();
    void refreshTimer();
    void resetLeaderboard();
    void displayCoins();

};
#endif // MAINWINDOW_H
