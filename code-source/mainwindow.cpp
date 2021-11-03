#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "character.h"
#include "gameend.h"
#include "score.h"
#include "song.h"

#include <QPixmap>
#include <QtWidgets/QVBoxLayout>
#include <QDebug>
#include <QGraphicsScene>
#include <QTimer>
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    windowView = 0;

    setMinimumSize(1360,790);
    setMaximumSize(1360,790);

    setWindowTitle("SkyCraft"); // Set Title of the game

    const auto fontButtons = QFont("Calibri", 24);
    int minH = 75;
    int maxW = 170;
    int widthButtons = 630;

    initGameEndItem();
    initScoreItem();
    initImages(); // Set background images
    initButtons(maxW, minH, widthButtons, fontButtons); // Set buttons of != menus
    initConnects(); // Set connects
    initLabels(maxW, minH, widthButtons); // Set labels

    playerItem = new Song();
}

void MainWindow::initLabels(int maxW, int minH, int widthButtons)
{
    // Add all menus labels
    const auto fontQuit = QFont("Calibri", 32);
    textQuit = new QLabel("Are you sure ?", ui->quit);
    textQuit->setFont(fontQuit);
    textQuit->setStyleSheet("QLabel {  color : white; }");
    textQuit->setGeometry(widthButtons - 550, 150, maxW + 100, minH);

    const auto fontWin = QFont("Monotype Corsiva", 50);
    textWin = new QLabel("You win !", ui->win);
    textWin->setFont(fontQuit);
    textWin->setStyleSheet("QLabel {  color : white; }");
    textWin->setGeometry(widthButtons - 50, 80, maxW + 100, minH);

    textScore = new QLabel("Score : ", ui->win);
    textScore->setFont(fontQuit);
    textScore->setStyleSheet("QLabel {  color : white; }");
    textScore->setGeometry(widthButtons - 525, 200, maxW + 100, minH);

    textTime = new QLabel("Time : ", ui->win);
    textTime->setFont(fontQuit);
    textTime->setStyleSheet("QLabel {  color : white; }");
    textTime->setGeometry(widthButtons - 525, 350, maxW + 200, minH);

    textCoins = new QLabel("Coins : ", ui->win);
    textCoins->setFont(fontQuit);
    textCoins->setStyleSheet("QLabel {  color : white; }");
    textCoins->setGeometry(widthButtons - 525, 400, maxW + 150, minH);

    textName = new QLabel("Enter your name : ", ui->win);
    textName->setFont(fontQuit);
    textName->setStyleSheet("QLabel {  color : white; }");
    textName->setGeometry(widthButtons - 550, 500, maxW + 125, minH);

    textLeaderboard = new QLabel("Leaderboard", ui->leaderboard);
    textLeaderboard->setFont(fontQuit);
    textLeaderboard->setStyleSheet("QLabel {  color : black; }");
    textLeaderboard->setGeometry(widthButtons - 150, 25, maxW + 125, minH);
}

void MainWindow::initScoreItem()
{
        scoreItem = new Score();
}

void MainWindow::initGameEndItem()
{
    gameEndItem = new GameEnd();
}

void MainWindow::initImages()
{
    // Add all menus images
    int widthLabel_background_menu = ui->label_background_menu->width();
    int heightLabel_background_menu = ui->label_background_menu->height();

    QPixmap picMenu(":/images/menuMarioBg.jpg");
    ui->label_background_menu->setPixmap(picMenu.scaled(widthLabel_background_menu,heightLabel_background_menu, Qt::KeepAspectRatio));

    QPixmap picSettings(":/images/settingsMarioBg.jpg");
    ui->label_background_settings->setPixmap(picSettings.scaled(widthLabel_background_menu,heightLabel_background_menu, Qt::KeepAspectRatio));

    QPixmap picCredits(":/images/creditsMarioBg.jpg");
    ui->label_background_credits->setPixmap(picCredits.scaled(widthLabel_background_menu,heightLabel_background_menu, Qt::KeepAspectRatio));

    QPixmap picQuit(":/images/quitMarioBg.jpg");
    ui->label_background_quit->setPixmap(picQuit.scaled(widthLabel_background_menu,heightLabel_background_menu, Qt::KeepAspectRatio));

    QPixmap picWin(":/images/winMarioBg.jpg");
    ui->label_background_win->setPixmap(picWin.scaled(widthLabel_background_menu,heightLabel_background_menu, Qt::KeepAspectRatio));

    QPixmap picLose(":/images/gameOver3.png");
    ui->label_background_lose->setPixmap(picLose.scaled(widthLabel_background_menu,heightLabel_background_menu, Qt::KeepAspectRatio));

    QPixmap picLeaderboard(":/images/leaderboardMarioBg.jpg");
    ui->label_background_leaderboard->setPixmap(picLeaderboard.scaled(widthLabel_background_menu,heightLabel_background_menu, Qt::KeepAspectRatio));

    QPixmap picPause(":/images/pauseMarioBg.jpg");
    ui->label_background_pause->setPixmap(picPause.scaled(widthLabel_background_menu,heightLabel_background_menu, Qt::KeepAspectRatio));

    QPixmap picCoin(":/images/coinMario3.png");
    ui->label_picCoin_game->setPixmap(picCoin.scaled(51, 51, Qt::KeepAspectRatio));

    QPixmap picClock(":/images/clock.png");
    ui->label_picTime_game->setPixmap(picClock.scaled(51, 51, Qt::KeepAspectRatio));

}

void MainWindow::initButtons(int maxW, int minH, int widthButtons,const QFont font)
{
    // Add all menus buttons
    // Menu buttons
    buttonPlay = new QPushButton("Play", ui->menu);
    buttonPlay->setFont(font);
    buttonPlay->setGeometry(widthButtons,100,maxW,minH);
    buttonPlay->setStyleSheet("color: black;" "background-color: white;");

    buttonLeaderBoard = new QPushButton("Leaderboard", ui->menu);
    buttonLeaderBoard->setFont(font);
    buttonLeaderBoard->setGeometry(widthButtons,230,maxW,minH);
    buttonLeaderBoard->setStyleSheet("color: black;" "background-color: white;");

    buttonSettings = new QPushButton("Settings", ui->menu);
    buttonSettings->setFont(font);
    buttonSettings->setGeometry(widthButtons,360,maxW,minH);
    buttonSettings->setStyleSheet("color: black;" "background-color: white;");

    buttonCredits = new QPushButton("Credits", ui->menu);
    buttonCredits->setFont(font);
    buttonCredits->setGeometry(widthButtons,490,maxW,minH);
    buttonCredits->setStyleSheet("color: black;" "background-color: white;");

    buttonExit = new QPushButton("Exit", ui->menu);
    buttonExit->setFont(font);
    buttonExit->setGeometry(widthButtons,620,maxW,minH);
    buttonExit->setStyleSheet("color: black;" "background-color: white;");

    // Game button
    buttonPause = new QPushButton("Pause", ui->game);
    buttonPause->setFont(font);
    buttonPause->setGeometry(10,10,maxW,minH); // (0,0) => Top left corner
    buttonPause->setStyleSheet("color: black;" "background-color: white;");

    // Leaderboard buttons
    buttonBackMenuFromLeaderBoard = new QPushButton("Menu", ui->leaderboard);
    buttonBackMenuFromLeaderBoard->setFont(font);
    buttonBackMenuFromLeaderBoard->setGeometry(widthButtons - 550,250,maxW,minH);
    buttonBackMenuFromLeaderBoard->setStyleSheet("color: black;" "background-color: white;");

    buttonResetLeaderboard = new QPushButton("Reset Leaderboard", ui->leaderboard);
    buttonResetLeaderboard->setFont(font);
    buttonResetLeaderboard->setGeometry(widthButtons - 75,650,maxW + 100,minH);
    buttonResetLeaderboard->setStyleSheet("color: black;" "background-color: white;");

    // Settings button
    buttonBackMenuFromSettings = new QPushButton("Menu", ui->settings);
    buttonBackMenuFromSettings->setFont(font);
    buttonBackMenuFromSettings->setGeometry(widthButtons,650,maxW,minH);
    buttonBackMenuFromSettings->setStyleSheet("color: black;" "background-color: white;");

    // Credits button
    buttonBackMenuFromCredits = new QPushButton("Menu", ui->credits);
    buttonBackMenuFromCredits->setFont(font);
    buttonBackMenuFromCredits->setGeometry(widthButtons,650,maxW,minH);
    buttonBackMenuFromCredits->setStyleSheet("color: black;" "background-color: white;");

    // Quit buttons
    buttonBackMenuFromQuit = new QPushButton("No", ui->quit);
    buttonBackMenuFromQuit->setFont(font);
    buttonBackMenuFromQuit->setGeometry(widthButtons - 300,430,maxW,minH);
    buttonBackMenuFromQuit->setStyleSheet("color: black;" "background-color: white;");

    buttonQuitGame = new QPushButton("Yes", ui->quit);
    buttonQuitGame->setFont(font);
    buttonQuitGame->setGeometry(widthButtons + 200,450,maxW,minH);
    buttonQuitGame->setStyleSheet("color: black;" "background-color: white;");

    // Pause buttons
    buttonBackMenuFromPause = new QPushButton("Menu", ui->pause);
    buttonBackMenuFromPause->setFont(font);
    buttonBackMenuFromPause->setGeometry(widthButtons - 50, 550, maxW, minH);
    buttonBackMenuFromPause->setStyleSheet("color: black;" "background-color: white;");

    buttonResume = new QPushButton("Resume", ui->pause);
    buttonResume->setFont(font);
    buttonResume->setGeometry(widthButtons - 200 - 50,350,maxW,minH);
    buttonResume->setStyleSheet("color: black;" "background-color: white;");

    buttonRestart = new QPushButton("Restart", ui->pause);
    buttonRestart->setFont(font);
    buttonRestart->setGeometry(widthButtons + 200 - 50,350,maxW,minH);
    buttonRestart->setStyleSheet("color: black;" "background-color: white;");

    // Lose buttons
    buttonRetry = new QPushButton("Retry", ui->lose);
    buttonRetry->setFont(font);
    buttonRetry->setGeometry(widthButtons + 100,550,maxW,minH);
    buttonRetry->setStyleSheet("color: black;" "background-color: white;");

    buttonBackMenuFromLose = new QPushButton("Menu", ui->lose);
    buttonBackMenuFromLose->setFont(font);
    buttonBackMenuFromLose->setGeometry(widthButtons - 200,550,maxW,minH);
    buttonBackMenuFromLose->setStyleSheet("color: black;" "background-color: white;");

    // Win buttons
    buttonReplay = new QPushButton("Replay", ui->win);
    buttonReplay->setFont(font);
    buttonReplay->setGeometry(widthButtons + 400,250,maxW,minH);
    buttonReplay->setStyleSheet("color: black;" "background-color: white;");

    buttonBackMenuFromWin = new QPushButton("Menu", ui->win);
    buttonBackMenuFromWin->setFont(font);
    buttonBackMenuFromWin->setGeometry(widthButtons + 400,500,maxW,minH);
    buttonBackMenuFromWin->setStyleSheet("color: black;" "background-color: white;");
}

void MainWindow::initConnects()
{
    //Add all menus connects
    // Menu connects
    QWidget::connect(buttonPlay, SIGNAL(clicked()), this, SLOT(displayGame()));
    QWidget::connect(buttonSettings, SIGNAL(clicked()), this, SLOT(displaySettings()));
    QWidget::connect(buttonCredits, SIGNAL(clicked()), this, SLOT(displayCredits()));
    QWidget::connect(buttonExit, SIGNAL(clicked()), this, SLOT(displayQuit()));

    // LeaderBoard connect
    QWidget::connect(buttonLeaderBoard, SIGNAL(clicked()), this, SLOT(displayLeaderBoard())); // Display Leaderboard
    QWidget::connect(buttonBackMenuFromLeaderBoard, SIGNAL(clicked()), this, SLOT(displayMenu()));
    QWidget::connect(buttonResetLeaderboard, SIGNAL(clicked()), this, SLOT(resetLeaderboard()));

    // Game connect
    QWidget::connect(buttonPause, SIGNAL(clicked()), this, SLOT(displayPause()));

    // Settings connect
    QWidget::connect(buttonBackMenuFromSettings, SIGNAL(clicked()), this, SLOT(displayMenu()));

    // Credits connect
    QWidget::connect(buttonBackMenuFromCredits, SIGNAL(clicked()), this, SLOT(displayMenu()));

    // Quit connects
    QWidget::connect(buttonBackMenuFromQuit, SIGNAL(clicked()), this, SLOT(displayMenu()));
    QWidget::connect(buttonQuitGame, SIGNAL(clicked()), qApp, SLOT(quit()));

    // Pause connects
    QWidget::connect(buttonResume, SIGNAL(clicked()), this, SLOT(displayGame()));
    QWidget::connect(buttonBackMenuFromPause, SIGNAL(clicked()), this, SLOT(displayMenu()));
    QWidget::connect(buttonRestart, SIGNAL(clicked()), this, SLOT(retry()));

    // Win connect
    QWidget::connect(gameEndItem->mySliderWin, SIGNAL(valueChanged(int)), this, SLOT(displayWin())); // Display Win
    QWidget::connect(buttonBackMenuFromWin, SIGNAL(clicked()), this, SLOT(displayMenu()));
    QWidget::connect(buttonReplay, SIGNAL(clicked()), this, SLOT(retry()));

    // Lose connects
    QWidget::connect(gameEndItem->mySliderLose, SIGNAL(valueChanged(int)), this, SLOT(displayLose())); // Display Lose
    QWidget::connect(buttonBackMenuFromLose, SIGNAL(clicked()), this, SLOT(displayMenu()));
    QWidget::connect(buttonRetry, SIGNAL(clicked()), this, SLOT(retry()));

    // Time connect
    QWidget::connect(gameEndItem->mySliderGameTime, SIGNAL(valueChanged(int)), this, SLOT(refreshTimer())); // RefreshTime

    // Coins connect
    QWidget::connect(gameEndItem->mySliderCoins, SIGNAL(valueChanged(int)), this, SLOT(displayCoins())); // Display Win
}

void MainWindow::initGameScene()
{
    // Init main view and game scene to user
    mainViewGame = new QGraphicsView();
    mainSceneGame = new GameScene(gameEndItem, playerItem);
    mainViewGame->setScene(mainSceneGame);

    // Remove vertical & horizontal scroll bars
    ui->graphicsView_game->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView_game->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    ui->graphicsView_game->setScene(mainSceneGame);
    ui->graphicsView_game->setFocus();

    // Set view of all the level
    mainViewGlobal = new QGraphicsView();
    mainViewGlobal->setScene(mainSceneGame);
    mainViewGlobal->scale(0.2, 0.2);
    mainViewGlobal->resize(1535, 156);
    mainViewGlobal->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    mainViewGlobal->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    mainViewGlobal->setWindowTitle("SkyCraft Global View");
    mainViewGlobal->show();
}

void MainWindow::displayMenu()
{
    // Set game mode to not pause (prepare next game)
    gameEndItem->setGameIsPaused(false);

    // Change current widget
    ui->mainStackedWidget->setCurrentWidget(ui->menu);
    windowView = 0; // # Update widget ID

    // If user won before, we save his score
    if (comeFromWin){
        scoreItem->writeScore(ui->playername_lineEdit->text(), gameEndItem);
        ui->playername_lineEdit->setText("");
    }
    // If user was in pause we close global view of the game scene
    if (comeFromPause)
        mainViewGlobal->close();

    // Delete scene and view of game to free memory
    if (comeFromPause || comeFromLose || comeFromWin){
        delete mainSceneGame;
        delete mainViewGame;
        comeFromPause = false;
        comeFromLose = false;
        comeFromWin = false;

        playerItem->MenuStart();
    }

    // Update variables
    boolConfirmEraseLeaderboard = false;
    boolSongLoseNotplayed = true;
    boolSongWinNotplayed = true;
    buttonResetLeaderboard->setText("Reset Leaderboard");
}

void MainWindow::displayLeaderBoard()
{
    // Show leaderboard
    ui->mainStackedWidget->setCurrentWidget(ui->leaderboard);
    windowView = 8; // #Update widget ID

    // Get all scores
    QString* arrayScores = scoreItem->getAllScores();

    // Build array to display scores
    ui->score_array->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    ui->score_array->setRowCount(scoreItem->getNbLinesFile());
    ui->score_array->setColumnCount(6);
    ui->score_array->resizeColumnsToContents();

    QStringList horzHeaders;
    horzHeaders << "Rank" << "Name" << "Score" << "Time" << "Coins" << "Date";

    // Fill array with headers + scores (saved before)
    ui->score_array->setHorizontalHeaderLabels(horzHeaders);
    for(int loop = 0, max = scoreItem->getNbLinesFile(); loop < max; loop++){
        QStringList values = arrayScores[loop].split(";");
        ui->score_array->setItem(loop,0, new QTableWidgetItem(QString::number(loop+1)));
        ui->score_array->setItem(loop,1, new QTableWidgetItem(values[0]));
        ui->score_array->setItem(loop,2, new QTableWidgetItem(values[1]));
        ui->score_array->setItem(loop,3, new QTableWidgetItem(values[2]));
        ui->score_array->setItem(loop,4, new QTableWidgetItem(values[3]));
        ui->score_array->setItem(loop,5, new QTableWidgetItem(values[4]));
    }
}

void MainWindow::displayGame()
{
    // Set game mode to not pause
    playerItem->endPause();
    gameEndItem->setGameIsPaused(false);

    // Change current widget
    ui->mainStackedWidget->setCurrentWidget(ui->game);
    windowView = 1; // #Update widget ID

    // Update game variables (make sure all iis correct from a previous game)
    isMainSceneGameDeclared = true;
    gameEndItem->setIsInPause(false);
    ui->label_coins_game->setNum(0); // Put back number of coins to current game to 0

    // Resetting GameEnd object (communication between Scene - Vue)
    resetingGameEndItem = true;
    gameEndItem->resetObject();
    resetingGameEndItem = false;

    // If we were not on pause we create game (if in pause game already exist)
    if (!comeFromPause)
        initGameScene();
    setFocus(); // To get all keys instantly and don't have to click or wait
}

void MainWindow::displayPause()
{
    // Stop game
    gameEndItem->setGameIsPaused(true);
    playerItem->beginPause();

    // Change current widget
    ui->mainStackedWidget->setCurrentWidget(ui->pause);
    windowView = 2; // #Update widget ID

    // Upddate variables
    comeFromPause = true;
    gameEndItem->setIsInPause(true);
    isMainSceneGameDeclared = false;

}

void MainWindow::displaySettings()
{
    // Change current widget
    ui->mainStackedWidget->setCurrentWidget(ui->settings);
    windowView = 3; // #Update widget ID
}

void MainWindow::displayCredits()
{
    // Change current widget
    ui->mainStackedWidget->setCurrentWidget(ui->credits);
    windowView = 4; // #Update widget ID
}

void MainWindow::displayQuit()
{
    // Change current widget
    ui->mainStackedWidget->setCurrentWidget(ui->quit);
    windowView = 5; // #Update widget ID
}

void MainWindow::displayWin()
{
    // Do all actions if not reseting
    // # If we reset the object we modify values -> value modified -> connect applied -> call this item again and again
    // # This condition block calling this function again when resetting -> Avoid problems
    if(!resetingGameEndItem){

        // Close global view of the game
        mainViewGlobal->close();

        // Change current widget
        ui->mainStackedWidget->setCurrentWidget(ui->win);
        windowView = 6; // #Update widget ID

        // Reset variables
        comeFromWin = true;
        isMainSceneGameDeclared = false;
        if(boolSongWinNotplayed){
            playerItem->songWin();
            boolSongWinNotplayed = false;
        }

        // Display score of played game
        textScore->setText("Score : " + QString::number(10000 - (gameEndItem->getFianalTime()*100) + (50*gameEndItem->getNbCoins())));
        textTime->setText("Time : " + QString::number(gameEndItem->getFianalTime()) + " sec");
        textCoins->setText("Coin(s) : " + QString::number(gameEndItem->getNbCoins()) + " coins");

        // Reset GameEnd object
        resetingGameEndItem = true;
        gameEndItem->resetObject();
        resetingGameEndItem = false;
    }
}

void MainWindow::displayLose()
{
    // Do all actions if not reseting
    // # If we reset the object we modify values -> value modified -> connect applied -> call this item again and again
    // # This condition block calling this function again when resetting -> Avoid problems
    if(!resetingGameEndItem){

        // Close global view of the game
        mainViewGlobal->close();

        // Change current widget
        ui->mainStackedWidget->setCurrentWidget(ui->lose);
        windowView = 7; // #Update widget ID

        // Reset variables
        comeFromLose = true;
        isMainSceneGameDeclared = false;
        if(boolSongLoseNotplayed){
            playerItem->songLose();
            boolSongLoseNotplayed = false;
        }

        // Reset GameEnd object
        resetingGameEndItem = true;
        gameEndItem->resetObject();
        resetingGameEndItem = false;
    }
}

void MainWindow::retry()
{
    // Retry is the name to make another game || Used when win, lose, or pause and user want to do another game

    // If user just won
    if (comeFromWin){
        // Save his score
        scoreItem->writeScore(ui->playername_lineEdit->text(), gameEndItem);

        // Reset variables
        ui->playername_lineEdit->setText("");
        comeFromWin = false;
    }

    //Reset variables
    if (comeFromPause)
        mainViewGlobal->close();
    comeFromLose = false;
    comeFromPause = false;
    delete mainSceneGame;
    delete mainViewGame;
    boolSongLoseNotplayed = true;
    boolSongWinNotplayed = true;
    gameEndItem->setGameIsPaused(false);

    // Display a new game window
    displayGame();
}

void MainWindow::refreshTimer()
{
    // Display time is making user in game - live
    ui->label_time_game->setNum(double(gameEndItem->getEllapsedTime()));
}

void MainWindow::resetLeaderboard()
{
    // Display a second message to make user sure he want to do that and that's not a missclick
    if(!boolConfirmEraseLeaderboard){
        buttonResetLeaderboard->setText("Confirm");
        boolConfirmEraseLeaderboard = true;
    }
    else{
        // Delete leaderboard
        scoreItem->deleteAllScores();
        buttonResetLeaderboard->setText("Reset Leaderboard");
        boolConfirmEraseLeaderboard = false;
        displayLeaderBoard();
    }
}

void MainWindow::displayCoins()
{
    // Display number of coin(s) user have (in game) - live
    ui->label_coins_game->setNum(int(gameEndItem->getNbCoins()));
}

MainWindow::~MainWindow()
{
    // Class destructor
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    // Get keys pressed by user (to move Mario or pause game)
    if (isMainSceneGameDeclared){
        if (event->key() == Qt::Key_P){
            displayPause();
        }else {
            mainSceneGame->receiveKeyPressed(event);
        }
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    // Get keys released by user
    if (isMainSceneGameDeclared){
        mainSceneGame->receiveKeyRelease(event);
    }
}
