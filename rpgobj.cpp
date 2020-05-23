#include "rpgobj.h"
#include <iostream>

void RPGObj::initObj(string type)
{
    //TODO 所支持的对象类型应定义为枚举
    if (type.compare("player")==0){
        this->_coverable = false;
        this->_eatable = false;
    }
    else if (type.compare("stone")==0){
        this->_coverable = false;
        this->_eatable = false;
    }
    else if (type.compare("fruit")==0){
        this->_coverable = false;
        this->_eatable = true;
    }
    else if (type.compare("tower")==0){
        this->_coverable = false;
        this->_eatable = false;
    }
    else if (type.compare("position")==0){
        this->_coverable = false;
        this->_eatable = false;
    }
    else{
        //TODO 应由专门的错误日志文件记录
        cout<<"invalid ICON type."<<endl;
        return;
    }

    this->_icon = ICON::findICON(type);
    QImage all;

    all.load(":/pics/TileB.png");
    this->_pic = all.copy(QRect(_icon.getSrcX()*ICON::GRID_SIZE, _icon.getSrcY()*ICON::GRID_SIZE, _icon.getWidth()*ICON::GRID_SIZE, _icon.getHeight()*ICON::GRID_SIZE));
}

void RPGObj::show(QPainter * pa){
    int gSize = ICON::GRID_SIZE;
    pa->drawImage(this->_pos_x*gSize,this->_pos_y*gSize,this->_pic);
}

int RPGObj::getNextX(int direction){
    switch (direction){
        case 1:
            return this->_pos_x;
        case 2:
           return this->_pos_x;
        case 3:
           return this->_pos_x-1;
        case 4:
           return this->_pos_x+1;
    }
}

int RPGObj::getNextY(int direction){
    switch (direction){
        case 1:
            return this->_pos_y - 1;
        case 2:
           return this->_pos_y + 1;
        case 3:
           return this->_pos_y;
        case 4:
           return this->_pos_y;
    }
}

void RPGObj::onErase(){
    QMediaPlayer * player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/sounds/2953.mp3"));
    player->setVolume(30);
    player->play();
}

