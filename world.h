#ifndef WORLD_H
#define WORLD_H
#include "fruit.h"
#include "rpgobj.h"
#include <vector>
#include <string>
#include <QPainter>
#include "player.h"
#include "tower.h"
#include "position.h"

class World
{
public:
    World(){this->_player = new Player;}
    ~World();
    void initWorld();

    void show(QPainter * painter);
        //显示游戏世界所有对象
    void handlePlayerMove(int direction, int steps);
        //假定只有一个玩家

    void eraseObj(int x, int y);

private:
    vector<RPGObj *> _objs;
    Player * _player;
};

#endif // WORLD_H
