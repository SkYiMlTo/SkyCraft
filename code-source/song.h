#ifndef SONG_H
#define SONG_H

#include <QMediaPlayer>

class Song
{
private:
    QMediaPlayer* playerMenu;
    QMediaPlayer* playerGame;
    QMediaPlaylist* playlistMenu;
    QMediaPlaylist* playlistGame;
public:
    Song();
    void GameStart();
    void MenuStart();
    void songCoin();
    void songJump();
    void songWin();
    void songLose();
    void beginPause();
    void endPause();
};

#endif // SONG_H
