#ifndef FRUIT_H
#define FRUIT_H
#include "rpgobj.h"
#include <QMediaPlayer>

class Fruit : public RPGObj
{
public:
    Fruit();
    ~Fruit();
    void onErase();
};

#endif // FRUIT_H
