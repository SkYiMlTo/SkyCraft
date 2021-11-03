#include "gamescene.h"
#include "character.h"
#include "mainwindow.h"
#include "groundbloc.h"
#include "castle.h"
#include "gameend.h"
#include "coin.h"
#include "song.h"
#include "banzaibill.h"

#include <QGraphicsView>
#include <QPushButton>
#include <QDebug>
#include <QString>
#include <QList>
#include <QGraphicsItem>
#include <string>

GameScene::GameScene(GameEnd* gameEnd, Song* player)
{
    // Init the background
    background.load(":/images/backgroundGameMario.png");
    setSceneRect(0, 0, background.width(), background.height());

    // Refresh
    this->timer = new QTimer(this);
    this->timer->start(15);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));

    gameEndItem = gameEnd;
    playerItem = player;
    player->GameStart();

    this->timerBill = new QTimer(this);
    this->timerBill->start(30);
    connect(timerBill, SIGNAL(timeout()), this, SLOT(moveBill()));

    addHero();
    createMap();
    addEnd();
    addCoins();
}

void GameScene::addHero()
{
    // Create character and add him to the game
    characterItem = new Character("Mario", ":/images/mario2_50fixe.png");
    addItem(characterItem);
    characterItem->setPos(50, background.height()/2 /* + 170*/); // Initial pos of Mario
}

void GameScene::createMap()
{
    //Create all static map
    addGround();

    // # PART 1
    //Begin warp
    warpItem = new Warp("warp", ":/images/warp.png");
    addItem(warpItem);
    warpItem->setPos(1568, 555);
    // Group of 3 start
    for(int loop = 0; loop < 3; loop++){
        GroundBloc* bloc = new GroundBloc("bloc", ":/images/blocMario");
        addItem(bloc);
        bloc->setScale(0.15);
        bloc->setPos((50 + (495 * 0.15 * (6 + loop))), 450);
        arrayBlocGround.push_back(bloc);
    }
    // 2 blocs plat1
    GroundBloc* bloc4 = new GroundBloc("bloc", ":/images/blocMario");
    addItem(bloc4);
    bloc4->setScale(0.15);
    bloc4->setPos((50 + (495 * 0.15 * 11)), 400);
    arrayBlocGround.push_back(bloc4);
    GroundBloc* bloc5 = new GroundBloc("bloc", ":/images/blocMario");
    addItem(bloc5);
    bloc5->setScale(0.15);
    bloc5->setPos((50 + (495 * 0.15 * 12)), 400);
    arrayBlocGround.push_back(bloc5);

    // # PART 2
    // First Group of 3 plat2
    for(int loop = 0; loop < 3; loop++){
        GroundBloc* bloc = new GroundBloc("bloc", ":/images/blocMario");
        addItem(bloc);
        bloc->setScale(0.15);
        bloc->setPos((50 + (495 * 0.15 * (27 + loop))), 450);
        arrayBlocGround.push_back(bloc);
    }
    // Second Group of 3 plat2
    for(int loop = 0; loop < 3; loop++){
        GroundBloc* bloc = new GroundBloc("bloc", ":/images/blocMario");
        addItem(bloc);
        bloc->setScale(0.15);
        bloc->setPos((50 + (495 * 0.15 * (32 + loop))), 350);
        arrayBlocGround.push_back(bloc);
    }
    // Third Group of 3 plat2
    for(int loop = 0; loop < 3; loop++){
        GroundBloc* bloc = new GroundBloc("bloc", ":/images/blocMario");
        addItem(bloc);
        bloc->setScale(0.15);
        bloc->setPos((50 + (495 * 0.15 * (37 + loop))), 250);
        arrayBlocGround.push_back(bloc);
    }
    // Fourth Group of 2 plat2
    for(int loop = 42; loop < 44; loop++){
        GroundBloc* bloc = new GroundBloc("bloc", ":/images/blocMario");
        addItem(bloc);
        bloc->setScale(0.15);
        bloc->setPos((495 * 0.15 *  loop), 573);
        arrayBlocGround.push_back(bloc);
    }
    // Gig warp and 2 blocs
    warpItem2 = new Warp("warp", ":/images/warp.png");
    warpItem2->setScale(2);
    addItem(warpItem2);
    warpItem2->setPos(3125, 380);

    // PART 3
    for (int i = 0; i < 4;i++) {
        for(int loop = 57 + i; loop < 61; loop++){
            GroundBloc* bloc = new GroundBloc("bloc", ":/images/blocMario");
            addItem(bloc);
            bloc->setScale(0.15);
            bloc->setPos((495 * 0.15 *  loop), 573 - (i*77));
            arrayBlocGround.push_back(bloc);
        }
    }
    for (int i = 0; i < 4;i++) {
        for(int loop = 63; loop < (67 - i); loop++){
            GroundBloc* bloc = new GroundBloc("bloc", ":/images/blocMario");
            addItem(bloc);
            bloc->setScale(0.15);
            bloc->setPos((495 * 0.15 *  loop), 573 - (i*77));
            arrayBlocGround.push_back(bloc);
        }
    }

    // PART 4
    for(int loop = 76; loop < 85; loop += 4){
        GroundBloc* bloc = new GroundBloc("bloc", ":/images/blocMario");
        addItem(bloc);
        bloc->setScale(0.15);
        bloc->setPos((495 * 0.15 *  loop), 450);
        arrayBlocGround.push_back(bloc);
    }

    // PART 5
    for (int i = 0; i < 5;i++) {
        for(int loop = 90 + i; loop < 95; loop++){
            if((loop != 92 || i == 0) && (loop != 93 || i == 3 || i == 0)){
                GroundBloc* bloc = new GroundBloc("bloc", ":/images/blocMario");
                addItem(bloc);
                bloc->setScale(0.15);
                bloc->setPos((495 * 0.15 *  loop), 573 - (i*77));
                arrayBlocGround.push_back(bloc);
            } else{
                Coin* coinItem = new Coin("coin", ":/images/coinMario3.png");
                addItem(coinItem);
                coinItem->setScale(0.6);
                coinItem->setPos(30 + (495 * 0.15 *  loop), 585 - (i*77));
                arrayCoins.push_back(coinItem);
            }
        }
    }
}

void GameScene::addGround()
{
    // Add all grounds blocs
    for(int loop = -1, nbBlocs = 104; loop < nbBlocs; loop++){
        if ((loop < 16 || loop > 18) && (loop < 24 || loop > 25) && (loop <= 46 || loop >= 51) && (loop < 61 || loop > 62) && (loop < 69 || loop > 70) && (loop < 75 || loop > 85)){
            GroundBloc* bloc = new GroundBloc(/*QString::number(loop)*/ "bloc", ":/images/blocMario");
            addItem(bloc);
            bloc->setScale(0.15);
            bloc->setPos(/*(50 + */(495 * 0.15 * loop)/*)*/, 650);
            arrayBlocGround.push_back(bloc);
        }
    }
}

void GameScene::addEnd()
{
    // Add the end castle
    castleItem = new Castle("castle", ":/images/castle");
    addItem(castleItem);
    castleItem->setPos(7300,260);
}

void GameScene::addCoins()
{
    // PART 1
    for(int loop = 1; loop < 3; loop++){
        Coin* coinItem3 = new Coin("coin", ":/images/coinMario3.png");
        addItem(coinItem3);
        coinItem3->setScale(0.6);
        coinItem3->setPos((200 + (495 * 0.15 * (6 + loop))), 300 - (50*loop));
        arrayCoins.push_back(coinItem3);
    }
    for(int loop = 1; loop < 4; loop++){
        Coin* coinItem3 = new Coin("coin", ":/images/coinMario3.png");
        addItem(coinItem3);
        coinItem3->setScale(0.6);
        coinItem3->setPos(((495 * 0.15 * (15 + loop))), 150 + (50*loop));
        arrayCoins.push_back(coinItem3);
    }

    // PART 2
    // Coins plat 2 - 4 coins under
    for (int i = 0; i < 2; i++) {
        for(int loop = 1; loop < 3; loop++){
            Coin* coinItem3 = new Coin("coin", ":/images/coinMario3.png");
            addItem(coinItem3);
            coinItem3->setScale(0.6);
            coinItem3->setPos((200 + (495 * 0.15 * (35 + loop))), 550 - (i*75));
            arrayCoins.push_back(coinItem3);
        }
    }
    for(int loop = 1; loop < 3; loop++){
        Coin* coinItem3 = new Coin("coin", ":/images/coinMario3.png");
        addItem(coinItem3);
        coinItem3->setScale(0.6);
        coinItem3->setPos(495 * 0.15 * (29 + loop), 300 - (50*loop));
        arrayCoins.push_back(coinItem3);
    }
    for(int loop = 1; loop < 3; loop++){
        Coin* coinItem3 = new Coin("coin", ":/images/coinMario3.png");
        addItem(coinItem3);
        coinItem3->setScale(0.6);
        coinItem3->setPos(495 * 0.15 * (34 + loop), 200 - (50*loop));
        arrayCoins.push_back(coinItem3);
    }

    // PART 3
    for(int loop = 1; loop < 3; loop++){
        Coin* coinItem3 = new Coin("coin", ":/images/coinMario3.png");
        addItem(coinItem3);
        coinItem3->setScale(0.6);
        coinItem3->setPos(25 + (495 * 0.15 * (47 + loop)), 475);
        arrayCoins.push_back(coinItem3);
    }

    for(int loop = 1; loop < 3; loop++){
        Coin* coinItem3 = new Coin("coin", ":/images/coinMario3.png");
        addItem(coinItem3);
        coinItem3->setScale(0.6);
        coinItem3->setPos(25 + (495 * 0.15 * (60 + loop)), 150);
        arrayCoins.push_back(coinItem3);
    }

    for(int loop = 1; loop < 3; loop++){
        Coin* coinItem3 = new Coin("coin", ":/images/coinMario3.png");
        addItem(coinItem3);
        coinItem3->setScale(0.6);
        coinItem3->setPos(25 + (495 * 0.15 * (68 + loop)), 475);
        arrayCoins.push_back(coinItem3);
    }

    for(int loop = 1; loop < 7; loop++){
        if(loop != 3 && loop != 4){
            Coin* coinItem3 = new Coin("coin", ":/images/coinMario3.png");
            addItem(coinItem3);
            coinItem3->setScale(0.6);
            coinItem3->setPos(50 + (495 * 0.15 * (76 + loop)), 225);
            arrayCoins.push_back(coinItem3);
        }
    }
}

string GameScene::determineTypeObject(QGraphicsItem *item)
{
    // Use this to determine which kind of object Mario hit
    if(item == castleItem)
        return "castle";
    if(item == warpItem)
        return "warp";
    if(item == warpItem2)
        return "warp2";
    for (int loop = 0, max = arrayBlocGround.size(); loop < max ; loop ++) {
        if(item == arrayBlocGround[loop])
            return "bloc";
    }
    for (int loop = 0, max = vectorBanzaiBill.size(); loop < max ; loop ++) {
        if(item == vectorBanzaiBill[loop])
            gameEndItem->playerLost();
    }
    for (int loop = 0, max = arrayCoins.size(); loop < max ; loop ++) {
        if(item == arrayCoins[loop]){
            delete item;
            gameEndItem->addCoin();
            playerItem->songCoin();
            break;
        }
    }
    return "";
}

const Character* GameScene::getCharacterItem()
{
    return characterItem;
}

void GameScene::putMarioStanding()
{
    // Make mario not moving (static)
    characterItem->setMarioStanding();
}

void GameScene::drawBackground(QPainter *painter, const QRectF &rect)
{
    Q_UNUSED(rect);
    painter->drawPixmap(QRectF(0,0,background.width(), background.height()), background, sceneRect());
}

void GameScene::receiveKeyPressed(QKeyEvent *event)
{
    // Use to pass keys pressed to character and handle movements (received from MainWindow)
    characterItem->receiveKeyPressed(event);
}

void GameScene::receiveKeyRelease(QKeyEvent *event)
{
    // Use to pass keys pressed to character and handle movements (received from MainWindow)
    characterItem->receiveKeyRelease(event);
}

void GameScene::keyPressEvent(QKeyEvent *event)
{
    // Use to pass keys pressed to character and handle movements
        characterItem->receiveKeyPressed(event);
}

void GameScene::keyReleaseEvent(QKeyEvent *event)
{
    // Use to pass keys pressed to character and handle movements
    characterItem->receiveKeyRelease(event);
}

void GameScene::update()
{

    // Refresh timer (we start timer when player move)
    if(characterItem->getPosX() < 100 && !boolExitSpawn){
        gameEndItem->setTimeStart();
        gameEndItem->setNbCoins(0);
        gameEndItem->timeEllapsed();
    }else{
        boolExitSpawn = true;
        gameEndItem->timeEllapsed();
    }

    // Tcheck if collision with end or fall in void
    if(collidingItems(characterItem).length()){
        string myChain = determineTypeObject(collidingItems(characterItem)[0]);
        if (myChain == "castle"){
            if(!finalTimeSet){
                gameEndItem->timeFinal();
                finalTimeSet = true;
            }
            gameEndItem->playerWon();
            notWin = false;
        }
    }
    if (characterItem->getPosY() > 768 && notWin)
        gameEndItem->playerLost();

    // Position update
    if(!gameEndItem->getGameIsPaused()){
    int stateMario = characterItem->getStateMario();
    int xMario = characterItem->getPosX();
    int yMario = characterItem->getPosY();
    if(inJump)
        speedHero = 8; // If jump, speed higher
    else
        speedHero = 7;
    if(stateMario == 5){
        actions5 = true;
    }

    if(stateMario == 4){
        actions4 = true;
    }

    // Tcheck if Mario can jump (if he is not already in the air)
    if ((stateMario == 3 || actions4 == true || actions5 == true) && inJump == false){
        bool youCanJump = false;
        characterItem->setY(characterItem->getPosY() + 2);
        if(collidingItems(characterItem).length()){
            string myChain = determineTypeObject(collidingItems(characterItem)[0]);
            if (myChain == "bloc" || myChain == "warp" || myChain == "warp2")
                youCanJump = true;
        }
        characterItem->setY(characterItem->getPosY() - 2);
        if(youCanJump){
            playerItem->songJump();
            inJump = true;
            reachedTopJump = false;
            jumpOnGround = yMario;
        }
    }

    // Move to the right
    if (stateMario == 1 || actions4 == true){
        characterItem->setX(xMario + speedHero);
        if(collidingItems(characterItem).length()){
            string myChain = determineTypeObject(collidingItems(characterItem)[0]);
            if (myChain == "bloc")
                characterItem->setX(collidingItems(characterItem)[0]->pos().x() - 94); // 94
            if (myChain == "warp")
                characterItem->setX(collidingItems(characterItem)[0]->pos().x() - 100);
            if (myChain == "warp2")
                characterItem->setX(collidingItems(characterItem)[0]->pos().x() - 100);
        }
        actions4 = false;
    }
    // Move to the left
    if (stateMario == 2 || actions5 == true){
        if(xMario - speedHero > - 20) // Don't exit out of the screen (left border)
            characterItem->setX(xMario - speedHero);
        if(collidingItems(characterItem).length()){
            string myChain = determineTypeObject(collidingItems(characterItem)[0]);
            if (myChain == "bloc")
                characterItem->setX(collidingItems(characterItem)[0]->pos().x() +51); // 94
            if (myChain == "warp")
                characterItem->setX(collidingItems(characterItem)[0]->pos().x() + 40);
            if (myChain == "warp2")
                characterItem->setX(collidingItems(characterItem)[0]->pos().x() + 125); // 120
        }
        actions5 = false;
    }

    // Update mario Y position (jumping or falling)
    if (inJump){
        if(yMario < jumpOnGround - 200)
            reachedTopJump = true;
        if(reachedTopJump == 0){
            characterItem->setY(yMario - 10);
            if(collidingItems(characterItem).length()){
                string myChain = determineTypeObject(collidingItems(characterItem)[0]);
                if (myChain == "bloc"){
                    characterItem->setY((collidingItems(characterItem))[0]->pos().y() + 79);
                    inJump = false;
                }
            }
        }
        else{
            inJump = false;
        }
    }else{
        characterItem->setY(characterItem->getPosY() + 10);
        if(collidingItems(characterItem).length()){
              string myChain = determineTypeObject(collidingItems(characterItem)[0]);
            if (myChain == "bloc")
                characterItem->setY(collidingItems(characterItem)[0]->pos().y() - 119); // 118
            if (myChain == "warp")
                characterItem->setY(collidingItems(characterItem)[0]->pos().y() - 128);
            if (myChain == "warp2")
                characterItem->setY(collidingItems(characterItem)[0]->pos().y() - 128);
        }else{
            speedHero = 8;
        }
    }
    }else{
        characterItem->setMarioStanding();
    }

    // View update to keep mario on the center
    QGraphicsView * view = this->views().at(1);
    view->centerOn(characterItem);
    setFocus();
}

void GameScene::moveBill()
{
    // # Banzai Bill are moving enemies
    // # => You touch them, you instantly die (yes that's a bit cruel)

    // Get number of BanziBill(s)
    int nbBanzaiBill = vectorBanzaiBill.size();

    // For every banziBill -> Update position and if they go out of the screen we delete them
    for (int i = 0; i < nbBanzaiBill; i++) {
        BanzaiBill* billItem = this->vectorBanzaiBill[i];
        billItem->move();
        if(billItem->getPosY() < - 100){
            vectorBanzaiBill.remove(i);
            nbBanzaiBill--;
            delete billItem;
        }
    }
    // Add banzaiBill if there is not enough ((< 2 or random(1%)) and less than 5 in total)
    // # 4 banzaiBill max is enough (more will be too hard)
    if((((rand() % (100 - 0 + 1)) + 0) == 5 || nbBanzaiBill < 2) && nbBanzaiBill < 5){
        int speed = (rand() % (15 - 5 + 1)) + 5;
        BanzaiBill* bill;

        // if banzaiBill speed < 10 Black missile, if >=10 red missile
        // # Used to != slow and fast banzaiBill
        if(speed < 10){
            bill = new BanzaiBill("BanziBill", ":/images/banzaiBillMario.png", speed);
        }else{
            bill = new BanzaiBill("BanziBill", ":/images/banzaiBillRedMario.png", speed);
        }
        addItem(bill);
        bill->setPos((rand() % (6300 - 5550 + 1)) + 5550,768); // Take random number in coordinates for part we want (jump of 3 blocs above void)
        vectorBanzaiBill.push_back(bill);
    }

}
