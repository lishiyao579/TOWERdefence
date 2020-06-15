#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <QPainter>
#include <QKeyEvent>
#include <QTimer>
#include "rpgobj.h"
#include "tower.h"
#include<QPoint>
#include<math.h>
#include "waterenemy.h"
#include "icon.h"
#include <QMouseEvent>
#include <QTime>
#include <map>
#include <iostream>
#include "button.h"
#include "bullet.h"
#include "world.h"
#include "bossenemy.h"

class GameWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit GameWindow(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    void loadTurnPoints();
    vector<WaterEnemy*> Enemys()const;
    vector<QPoint*> turnPoints;   //存拐点,只加载一次，其它形象调用
    vector<WaterEnemy*> enemys;    //存怪
    void eraseBullet(Bullet* bullet);
    void eraseEnemy(WaterEnemy *enemy);

//    void keyPressEvent(QKeyEvent *);


protected slots:
    void updateMap();
    void mousePressEvent(QMouseEvent *event);
    void setTower(QPoint pos);
    void setEnemy();
    bool loadWave();
    bool checkTower(QPoint P) const;
    bool canBuyTower() const;
    void setBoss();
   // Tower test;

signals:

public slots:
    void setBullet(Bullet *bullet);



private slots:



private:
    World _game;
    QTimer *timer;
    vector<Tower*> _towers;           //存已经安放了的塔
    vector<Bullet*> _bullets;//存子弹
    vector<BossEnemy*> _bosses;
    int	_totalGold;     //起始金币数
    int _totalTower;       //总塔数
    int _waves;
    QPoint _startPos;
    QPoint _endPos;
    void showGold(QPainter *p);
    void showWave(QPainter *p);
    void winGame(QPainter *p);
    void nextLevel();
    bool _win;
    const int _maxwave=4;//一轮有四波
    const int _resi=2;//每波剩2个时进行下一波

};

#endif // GAMEWINDOW_H

