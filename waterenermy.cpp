#include "waterenermy.h"

WaterEnermy::WaterEnermy()
{

}

bool WaterEnermy::inShootCircle(QPoint ener,QPoint tow,int range){
    //????怎么调攻击范围


}
bool WaterEnermy::atTurnPoint(QPoint ener, TurnPoint* tur, int range){


}
void WaterEnermy::onErase(){
    QMediaPlayer * player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/sounds/crash.mp3"));
    player->setVolume(30);
    player->play();
}

void WaterEnermy::run(){

    if(atTurnPoint(_nowPos, _pos.getNowTurn(),10/*!!!to do 如何调用攻击范围？？？*/))
    {
        if(_pos.haveNextTurn())
        {
            /*_nowPos=_pos.getNowTurn();
            _nowPos=_pos.getNextTurn();*/
        }
        else
        {
        //到终点，死，擦除?????怎么处理
            this->onErase();
        }
    }

}
