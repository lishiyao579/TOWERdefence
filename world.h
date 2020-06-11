#ifndef WORLD_H
#define WORLD_H
#include "rpgobj.h"
#include <vector>
#include <string>
#include <QPainter>
//#include "tower.h"
#include "position.h"
#include "icon.h"
#include "rpgobj.h"
#include <QMediaPlayer>
#include <iostream>


class World
{
public:
    World(){}
    ~World();
    void initWorld();

    void show(QPainter * painter);
        //显示游戏世界所有对象

    void eraseObj(int x, int y);

private:
    vector<RPGObj *> _objs;

};

#endif // WORLD_H
