#include "rpgobj.h"
#include <iostream>

void RPGObj::initObj(string type)
{
    if(type=="waterenermy"){
        this->_icon = ICON::findICON(type);
        QImage waterEnermy;
        waterEnermy.load(":/pics/water1.png");//引入水怪图
        this->_pic = waterEnermy.copy(QRect(_icon.getSrcX()*ICON::GRID_SIZE, _icon.getSrcY()*ICON::GRID_SIZE, _icon.getWidth()*ICON::GRID_SIZE, _icon.getHeight()*ICON::GRID_SIZE));
    }
    else if(type=="tower"){
        this->_icon = ICON::findICON(type);
        QImage tower;
        tower.load(":/pics/fire1.png");
        this->_pic = tower.copy(QRect(_icon.getSrcX()*ICON::GRID_SIZE, _icon.getSrcY()*ICON::GRID_SIZE, _icon.getWidth()*ICON::GRID_SIZE, _icon.getHeight()*ICON::GRID_SIZE));
    }
    else
    {
        int flag=0;
        for(int i=0;i<4;i++)
            if(type==RPGObj::OBJtypeall[i])
                flag=1;
        if(!flag){
            cout<<"invalid ICON type."<<endl;
            return;
        }

        this->_icon = ICON::findICON(type);
        QImage all;

        all.load(":/pics/TileB.png");
        this->_pic = all.copy(QRect(_icon.getSrcX()*ICON::GRID_SIZE, _icon.getSrcY()*ICON::GRID_SIZE, _icon.getWidth()*ICON::GRID_SIZE, _icon.getHeight()*ICON::GRID_SIZE));
    }
    return;
}

void RPGObj::show(QPainter * pa){
    int gSize = ICON::GRID_SIZE;
    pa->drawImage(this->_pos_x*gSize,this->_pos_y*gSize,this->_pic);
}


void RPGObj::onErase(){
    QMediaPlayer * player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/sounds/2953.mp3"));
    player->setVolume(30);
    player->play();
}

