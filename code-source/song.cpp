#include "song.h"

#include <QMediaPlayer>
#include <QMediaPlaylist>

Song::Song()
{
    // Init player for differents songs (playlist used to make song loop and not played only one time)
    playerMenu = new QMediaPlayer();
    playerGame = new QMediaPlayer();

    playlistMenu = new QMediaPlaylist();
    playlistMenu->addMedia(QUrl("qrc:/songs/menuTheme.wav"));
    playlistMenu->setPlaybackMode(QMediaPlaylist::Loop);

    playlistGame = new QMediaPlaylist();
    playlistGame->addMedia(QUrl("qrc:/songs/gameTheme.wav"));
    playlistGame->setPlaybackMode(QMediaPlaylist::Loop);

    playerMenu->setPlaylist(playlistMenu);
    playerMenu->play();
}

void Song::GameStart()
{
    //Stop menu song and play game song
    playerMenu->stop();

    playerGame->setPlaylist(playlistGame);
    playerGame->play();
}

void Song::MenuStart()
{
    //Stop game song and play menu song
    playerGame->stop();

    playerMenu->setPlaylist(playlistMenu);
    playerMenu->play();
}

void Song::songCoin()
{
    // Sound effect when player catch coin
    QMediaPlayer*playerEffects = new QMediaPlayer();
    playerEffects->setMedia(QUrl("qrc:/songs/coinSound.wav"));
    playerEffects->setVolume(75);
    playerEffects->play();
}

void Song::songJump()
{
    // Sound effect when player jump
    QMediaPlayer*playerEffects = new QMediaPlayer();
    playerEffects->setMedia(QUrl("qrc:/songs/jumpMario2.wav"));
    playerEffects->setVolume(25);
    playerEffects->play();
}

void Song::songWin()
{
    // Sound effect when player win
    playerGame->stop();
    QMediaPlayer*playerEffects = new QMediaPlayer();
    playerEffects->setMedia(QUrl("qrc:/songs/winMario.wav"));
    playerEffects->play();
}

void Song::songLose()
{
    // Sound effect when player lose
    playerGame->stop();
    QMediaPlayer*playerEffects = new QMediaPlayer();
    playerEffects->setMedia(QUrl("qrc:/songs/loseMario2.wav"));
    playerEffects->play();
}

void Song::beginPause()
{
    // Sound effect when player catch coin (+ stop game song)
    playerGame->pause();
    QMediaPlayer*playerEffects = new QMediaPlayer();
    playerEffects->setMedia(QUrl("qrc:/songs/pauseSoundEffect2.wav"));
    playerEffects->play();
}

void Song::endPause()
{
    // Sound effect when player catch coin
    playerGame->play();
}

