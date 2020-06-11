#include "world.h"
//#include<iostream>
using namespace std;

World::~World(){
}

void World::initWorld(){
    //TODO 下面的内容应该改为从地图文件装载

    RPGObj *p1 = new RPGObj;
    p1->initObj("stone");
    p1->setPosX(6);
    p1->setPosY(4);

    RPGObj *p2 = new RPGObj;
    p2->initObj("stone");
    p2->setPosX(1);
    p2->setPosY(4);

    RPGObj *p3 = new RPGObj;
    p3->initObj("stone");
    p3->setPosX(6);
    p3->setPosY(8);

    for(int i=0;i<posNum; i++)
    {
        RPGObj *p = new Position;
        p->initObj("position");
        p->setPosX(Position::towerPos[i].x());
        p->setPosY(Position::towerPos[i].y());
        this->_objs.push_back(p);
    }



    this->_objs.push_back(p1);
    this->_objs.push_back(p2);
    this->_objs.push_back(p3);

    QMediaPlayer * player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/sounds/hdl.mp3"));
    player->setVolume(0);           //目前音量设为0
    player->play();


}


void World::show(QPainter * painter){
    int n = this->_objs.size();
    for (int i=0;i<n;i++){
        this->_objs[i]->show(painter);
    }
    //this->_player->show(painter);



}

void World::eraseObj(int x, int y){// to do !!!
    vector<RPGObj*>::iterator it;
    it = _objs.begin();
    while(it!=_objs.end()){
        int flag1 = ((*it)->getObjType()=="stone"); //不是石头
        int flag2 = ((*it)->getPosX() == x) && ((*it)->getPosY()==y);//位置重叠

        if (flag1 && flag2){
            cout<<(*it)->getObjType()<<endl;
            (*it)->onErase();
            delete (*it);
            it = this->_objs.erase(it);
            break;
         }
        else{
            it++;
        }
    }

}

