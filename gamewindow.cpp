#include "gamewindow.h"
#include <iostream>
#include <ctime>
#include <stdlib.h>
const int _towerCost = 200;
const int _hitAward = 25;

template <typename T>
void deleteObject(T *obj){
    delete obj;
    obj = NULL;
}
GameWindow::GameWindow(QWidget *parent) : QMainWindow(parent)
{
    _totalGold=1000;
    _waves=0;
    _startPos=QPoint(0,175);
    _endPos=QPoint(0,555);
    _win=-1;
    _hp=3;
    _towerType=QString::null;
    timer = new QTimer(this);

    setFixedSize(32*32,22*32);
    _game.initWorld();            //init game world
    showMenu();
    setAward();
    this->loadTurnPoints();

    QTimer::singleShot(100,this,SLOT(loadWave()));

    connect(timer,&QTimer::timeout,this,[=](){
        updateMap();
        checkWin();
    });
    timer->start(30);//30ms触发一次timeout↑
    QMediaPlayer * player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/sounds/bg.mp3"));
    player->setVolume(30);
    player->play();
  //  qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));//设置随机种子

}


void GameWindow::paintEvent(QPaintEvent *e){

    QPainter *pa= new QPainter();
    pa->begin(this);
    QPixmap bgpic(":/pics/bg.jpg");
    pa->drawPixmap(0, 0, bgpic);
    drawMenu(pa);
    this->_game.show(pa);
    this->showGold(pa);
    this->showWave(pa);
    this->showHp(pa);
    for(int i=0;i<_towers.size();i++){//画塔
        _towers[i]->setTower(pa,QPoint(_towers[i]->getPosX(),_towers[i]->getPosY()));
    }
    for(int i=0;i<enemys.size();i++){//画怪
        enemys[i]->setEnermy(pa);
    }

    for(int i=0;i<_bullets.size();i++){//画子弹
        _bullets[i]->setBullet(pa);
    }
    if(_win==1){
        winGame(pa);
    }
    if(_win==0){
        loseGame(pa);
    }
    pa->end();
    delete pa;
}
void GameWindow::setTower(QPoint &pos){
    Tower *t=new Tower(pos,this,_towerType);
    _towers.push_back(t);
    update();
    t->onSet();
}

void GameWindow::updateMap()
{
    for(int i=0;i<_towers.size();i++){
        _towers[i]->searchEnemy();
    }
    update();
}

bool GameWindow::checkTower(QPoint p) const//检查附近一定范围内是不是有塔 保证不重叠
{
    for(int i =0;i<_towers.size();i++ ){
        if(abs(p.x()-_towers[i]->getPosX())<=2*ICON::GRID_SIZE && abs(p.y()-_towers[i]->getPosY())<=2*ICON::GRID_SIZE){
            return true;
        }
    }
    return false;
}

void GameWindow::mousePressEvent(QMouseEvent *event)
{
    QPoint pressPos = event->pos();
    //QTimer* doubleTimer =new QTimer(this);
    if(_towerType==QString::null)
        return;
    if(event->button() == Qt::LeftButton)//左键放塔
    {
        if(!checkTower(pressPos) && Position::checkTowerPosition(pressPos) && canBuyTower())
        {
            setTower(pressPos);

            _totalTower++;
            _totalGold -= _towerCost;
        }
    }
    else if(event->button() ==Qt::RightButton){//右键拆塔
        if(checkTower(pressPos))
            eraseTower(pressPos);
    }

}
bool GameWindow::canBuyTower() const
{
    if(this->_totalGold >= _towerCost)
        return true;
    return false;
}

void GameWindow::loadTurnPoints()
{
    QPoint *begin=new QPoint(0,160);
    turnPoints.push_back(begin);

    QPoint *p1=new QPoint(840,160);
    turnPoints.push_back(p1);

    QPoint *p2=new QPoint(840,540);
    turnPoints.push_back(p2);

    QPoint *p3=new QPoint(600,540);
    turnPoints.push_back(p3);

    QPoint *p4=new QPoint(600,285);
    turnPoints.push_back(p4);

    QPoint *p5=new QPoint(190,285);
    turnPoints.push_back(p5);

    QPoint *p6=new QPoint(190,540);
    turnPoints.push_back(p6);

    QPoint *des=new QPoint(0,540);
    turnPoints.push_back(des);
}


void GameWindow::setEnemy(){
    WaterEnemy *e=new WaterEnemy(*turnPoints[0],*turnPoints.back(),this);
    enemys.push_back(e);
    e->move();
}

void GameWindow::setBoss(){
    BossEnemy *b=new BossEnemy(*turnPoints[0],*turnPoints.back(),this);
    enemys.push_back(b);
    b->move();
}

void GameWindow::loadWave()
{
    ++_waves;
    const int enemyFre =500;

    for (int i=1; i<=6; i++) //每波6个
    {
        QTimer::singleShot(i*enemyFre,this,[=](){
            setEnemy();
            setBoss();
        });
     //   setEnemy();
    }

//    return true;
}
bool GameWindow::canLoadWave(){
    if (_waves >= _maxwave)        //每轮5波！！！to do：怎么储存更好？
        return false;
    return true;
}
void GameWindow::showGold(QPainter *p){
    p->save();
    QRectF rect(10,10,300,50);
    QFont font("Consolas",16,true);
    QString gold("$$$：%1");
    p->setFont(font);
    p->setPen(QColor("blue"));
    p->drawText(rect,gold.arg(_totalGold));
    p->restore();
}
void GameWindow::showWave(QPainter *p){
    p->save();
    QRectF rect(400,10,300,50);
    QFont font("Consolas",16,true);
    QString gold("wave：%1");
    p->setFont(font);
    p->setPen(QColor("blue"));
    p->drawText(rect,gold.arg(_waves));
    p->restore();
}
void GameWindow::showHp(QPainter *p){
    p->save();
    QRectF rect(200,10,300,50);
    QFont font("Consolas",16,true);
    QString gold("hp：%1");
    p->setFont(font);
    p->setPen(QColor("blue"));
    p->drawText(rect,gold.arg(_hp));
    p->restore();
}
vector<WaterEnemy*> GameWindow::Enemys() const{
    return enemys;
}
void GameWindow::setBullet(Bullet* bullet){
    _bullets.push_back(bullet);
    bullet->move();
}

void GameWindow::eraseBullet(Bullet *bullet){
    auto iter = remove(_bullets.begin(), _bullets.end(), bullet);

    _bullets.erase(iter, _bullets.end());
 //   deleteObject(bullet);
 //   delete bullet;//erase 只是从vector删除，bullet还在！！导致看似没攻击却降血

}
void GameWindow::eraseEnemy(WaterEnemy *enemy){
    _totalGold+=_hitAward;
    auto iter = remove(enemys.begin(), enemys.end(), enemy);

    enemys.erase(iter, enemys.end());
        deleteObject(enemy);
    if (enemys.size()==_resi){
        loadWave();
    }
 //
 //   delete enemy;
}

void GameWindow::checkWin(){
    if(enemys.empty()&&!canLoadWave()){
        _win=1;
        update();
    }
}
void GameWindow::eraseEnemy(BossEnemy *boss){
    _totalGold+=_hitAward;
    auto iter = remove(enemys.begin(), enemys.end(), boss);

    enemys.erase(iter, enemys.end());
        deleteObject(boss);
    if (enemys.size()==_resi){
        loadWave();
    }
}
void GameWindow::eraseTower(QPoint p){
    for(int i =0;i<_towers.size();i++ ){
        if(abs(p.x()-_towers[i]->getCenX())<=2*ICON::GRID_SIZE && abs(p.y()-_towers[i]->getCenY())<=2*ICON::GRID_SIZE){
            auto iter = remove(_towers.begin(), _towers.end(), _towers[i]);

            _towers.erase(iter, _towers.end());
            deleteObject(_towers[i]);
            _totalGold+=_towerCost;//拆塔补钱
            break;
        }
    }
}
void GameWindow::enemyAtEnd(){
    int nowHp=_hp-1;
    if(nowHp>0)
        _hp=nowHp;
    else
        _win=0;
}
void GameWindow::winGame(QPainter* p){
    p->drawPixmap(0,0,QPixmap(":/pics/winbg.png"));
    p->save();
    QRectF rect(400,350,200,250);
    QFont font("Consolas",16,true);
    QString words("YOU WIN！");
    p->setFont(font);
    p->setPen(QColor("blue"));
    p->drawText(rect,words);
    p->restore();
    nextLevel();

}
void GameWindow::loseGame(QPainter *p){
    p->drawPixmap(0,0,QPixmap(":/pics/winbg.png"));
    p->save();
    QRectF rect(400,350,200,250);
    QFont font("Consolas",16,true);
    QString words("YOU LOSE！");
    p->setFont(font);
    p->setPen(QColor("blue"));
    p->drawText(rect,words);
    p->restore();
    exitGame();
}

void GameWindow::nextLevel(){
    Button *btn=new Button(":/pics/next.png");
    btn->setParent(this);
    btn->move(500,550);
    btn->show();
    connect(btn, &QPushButton::clicked, this, [=](){
        btn->zoomDown();
        btn->zoomUp();

    });
}
void GameWindow::exitGame(){
    Button *btn=new Button(":/pics/next.png");
    btn->setParent(this);
    btn->move(500,550);
    btn->show();
    connect(btn, &QPushButton::clicked, this, [=](){
        btn->zoomDown();
        btn->zoomUp();
        this->close();
    });
}
void GameWindow::setTowerType(QString type){
     _towerType=type;
}
void GameWindow::showMenu(){
    Button *t1=new Button(":/pics/fire1.png");
    t1->setParent(this);
    t1->move(930,100);
    t1->show();
    connect(t1, &QPushButton::clicked, this, [=](){
        t1->zoomDown();
        t1->zoomUp();
        setTowerType("fire1");
    });
    Button *t2=new Button(":/pics/fire2.png");
    t2->setParent(this);
    t2->move(930,250);
    t2->show();
    connect(t2, &QPushButton::clicked, this, [=](){
        t2->zoomDown();
        t2->zoomUp();
        setTowerType("fire2");
    });
}
void GameWindow::drawMenu(QPainter *pa){
    pa->save();
    pa->setPen(QPen(Qt::black,5));
    QFont font("黑体",16,true);
    pa->setFont(font);
    pa->drawText(900,20,100,50,Qt::AlignCenter,"菜单区");
    pa->drawLine(900,0,900,704);
    //pa->drawRects(QRect(930,100,100,100));
    pa->restore();

}
void GameWindow::setAward(){
    Button *t1=new Button(":/pics/award.png");
    t1->setParent(this);
    t1->move(300,0);
    t1->show();
    connect(t1, &QPushButton::clicked, this, [=](){
        t1->zoomDown();
        t1->zoomUp();
        _totalGold+=20;
    });
}
