#include "fruit.h"

Fruit::Fruit()
{

}

Fruit::~Fruit()
{

}

void Fruit::onErase(){
    QMediaPlayer * player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/sounds/crash.mp3"));
    player->setVolume(30);
    player->play();
}

