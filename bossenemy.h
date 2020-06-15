#ifndef BOSSENEMY_H
#define BOSSENEMY_H
#include "waterenemy.h"

class BossEnemy : public WaterEnemy
{
public:
    BossEnemy(QPoint nowpos, QPoint endpos, GameWindow *game);
};

#endif // BOSSENEMY_H
