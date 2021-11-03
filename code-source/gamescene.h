#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "character.h"
#include "groundbloc.h"
#include "castle.h"
#include "warp.h"
#include "gameend.h"
#include "coin.h"
#include "song.h"
#include "banzaibill.h"

#include <QGraphicsScene>
#include <QPixmap>
#include <QTimer>
#include <QPainter>
#include <QRectF>

#include <vector>
using namespace std;

class GameScene : public QGraphicsScene
{
    Q_OBJECT
private:
    QPixmap background;
    QTimer* timer;

    // Handle jump
    bool inJump = false;
    bool reachedTopJump;
    int jumpOnGround;
    bool actions4 = false;
    bool actions5 = false;

    // Graphics objects on the level
    Character* characterItem;
    vector<GroundBloc*> arrayBlocGround;
    vector<Coin*> arrayCoins;
    Castle* castleItem;
    Warp* warpItem;
    Warp* warpItem2;

    // Graphics BanzaiBill (missile) + timer to update their position
    QTimer* timerBill;
    QVector<BanzaiBill*> vectorBanzaiBill;

    // Communication object received from MainWindow
    GameEnd * gameEndItem;

    //Init varibles for the game
    bool finalTimeSet = false;
    bool notWin = true;
    bool boolExitSpawn = false;
    int speedHero;

    Song* playerItem;

    // Private methodes to create map (static part)
    void addGround();
    void createMap();
    void addHero();
    void addEnd();
    void addCoins();

public:
    //Methodes
    GameScene(GameEnd*, Song*);
    string determineTypeObject(QGraphicsItem* item);
    void drawBackground(QPainter* painter, const QRectF& rect);
    void receiveKeyPressed(QKeyEvent *event);
    void receiveKeyRelease(QKeyEvent *event);
    void keyPressEvent(QKeyEvent * event);
    void keyReleaseEvent(QKeyEvent *keyEvent);
    const Character* getCharacterItem();
    void putMarioStanding();
    void temp();

//    ~GameScene();

public slots :
    void update();
    void moveBill();
};

#endif // GAMESCENE_H
