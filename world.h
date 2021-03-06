#ifndef WORLD_H
#define WORLD_H
#include <vector>
#include <string>
#include <QPainter>
#include "position.h"
#include "icon.h"
#include "rpgobj.h"
#include <QMediaPlayer>
#include <iostream>


class World
{
public:
    World(){}
    ~World(){};
    void initWorld();
    void show(QPainter * painter);
        //显示游戏世界所有只初始化一次的对象

private:
    vector<RPGObj *> _objs;

};

#endif // WORLD_H
