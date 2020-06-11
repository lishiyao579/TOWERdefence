#include "gamewindow.h"
#include <iostream>

//using namespace std;

const int towerCost = 200;

GameWindow::GameWindow(QWidget *parent) : QMainWindow(parent),_totalGold(1000),_waves(0),_startPos(0,175),_endPos(0,555)
{
    setFixedSize(32*32,22*32);

    _game.initWorld();            //init game world
    this->loadTurnPoints();

    timer = new QTimer(this);

    QTimer::singleShot(100,this,SLOT(loadWave()));

    connect(timer,SIGNAL(timeout()),this,SLOT(updateMap()));
    timer->start(30);//30ms触发一次timeout↑
 //   timer->setInterval(50);

  //  qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));//设置随机种子
}



void GameWindow::paintEvent(QPaintEvent *e){

    QPainter *pa= new QPainter();
    pa->begin(this);
    QPixmap bgpic(":/pics/bg.jpg");
    pa->drawPixmap(0, 0, bgpic);

    this->_game.show(pa);
    this->showGold(pa);
    this->showWave(pa);
    for(int i=0;i<_tower.size();i++){//画塔
        _tower[i]->setTower(pa,QPoint(_tower[i]->getPosX(),_tower[i]->getPosY()));
    }
    for(int i=0;i<_enemy.size();i++){//画怪
        _enemy[i]->setEnermy(pa);
    }
    pa->end();
    delete pa;
}
void GameWindow::setTower(QPoint pos){
    Tower *t=new Tower(pos);//,this);
    _tower.push_back(t);
    update();
}

/*
void GameWindow::keyPressEvent(QKeyEvent *e)
{
    //direction = 1,2,3,4 for 上下左右
    if(e->key() == Qt::Key_A)
    {
        this->_game.handlePlayerMove(3,1);
    }
    else if(e->key() == Qt::Key_D)
    {
        this->_game.handlePlayerMove(4,1);
    }
    else if(e->key() == Qt::Key_W)
    {
        this->_game.handlePlayerMove(1,1);
    }
    else if(e->key() == Qt::Key_S)
    {
         this->_game.handlePlayerMove(2,1);
    }
    this->repaint();
}

void MW1::randomMove(){

    int d = 1 + rand()%4;//生成随机运动的方向
    this->_game.handlePlayerMove(d,1);
    this->repaint();
}
*/
void GameWindow::updateMap()
{

    update();
}

bool GameWindow::checkTower(QPoint p) const//检查附近一定范围内是不是有塔 保证不重叠
{
    for(int i =0;i<_tower.size();i++ ){
        if(abs(p.x()-_tower[i]->getPosX())<=2*ICON::GRID_SIZE && abs(p.y()-_tower[i]->getPosY())<=2*ICON::GRID_SIZE){
            return true;
        }
    }
    return false;
}

void GameWindow::mousePressEvent(QMouseEvent *event)
{
    QPoint pressPos = event->pos();
    if(event->button() == Qt::LeftButton)
    {
        if(!checkTower(pressPos) && Position::checkTowerPosition(pressPos) && canBuyTower())
        {
            this->setTower(pressPos);

            _totalTower++;
            _totalGold -= towerCost;
        }
    }
    else if(event->button() ==Qt::RightButton){

    }

}
bool GameWindow::canBuyTower() const
{
    if(this->_totalGold >= towerCost)
        return true;
    return false;
}

void GameWindow::loadTurnPoints()
{
    QPoint *begin=new QPoint(0,160);
    _turnPoint.push_back(begin);

    QPoint *p1=new QPoint(835,160);
    _turnPoint.push_back(p1);

    QPoint *p2=new QPoint(835,540);
    _turnPoint.push_back(p2);

    QPoint *p3=new QPoint(600,540);
    _turnPoint.push_back(p3);

    QPoint *p4=new QPoint(600,285);
    _turnPoint.push_back(p4);

    QPoint *p5=new QPoint(190,285);
    _turnPoint.push_back(p5);

   QPoint *p6=new QPoint(190,540);
    _turnPoint.push_back(p6);

    QPoint *des=new QPoint(0,540);
    _turnPoint.push_back(des);

}

void GameWindow::removeEnemy(WaterEnemy *enemy)
{
//    _enemy.erase();
    delete enemy;
    if (_enemy.size()==0)
    {
        ++_waves; // 当前波数加1
        // 继续读取下一波
        if (!loadWave())
        {
            // 当没有下一波时，这里表示游戏胜利
            // 设置游戏胜利标志为true
            //m_gameWin = true;
            // 游戏胜利转到游戏胜利场景
            // 这里暂时以打印处理
        }
    }
}

void GameWindow::setEnemy(){
    WaterEnemy *e=new WaterEnemy(*_turnPoint[0],*_turnPoint.back());
    _enemy.push_back(e);
    e->move();
}

bool GameWindow::loadWave()
{
    if (_waves >= 5)        //每轮5波！！！to do：怎么储存更好？
        return false;

    const int enemyFre =200;

    for (int i=1; i<=6; i++) //每波6个
    {
        QTimer::singleShot(i*enemyFre,this,SLOT(setEnemy()));
     //   setEnemy();
    }

    _waves++;
    return true;
}
void GameWindow::showGold(QPainter *p){
    p->save();
    QRectF rect(10,10,300,50);
    QFont font("黑体",16,true);
    QString gold("$$$：%1");
    p->setFont(font);
    p->setPen(QColor("blue"));
    p->drawText(rect,gold.arg(_totalGold));
    p->restore();
}
void GameWindow::showWave(QPainter *p){
    p->save();
    QRectF rect(400,10,300,50);
    QFont font("黑体",16,true);
    QString gold("wave：%1");
    p->setFont(font);
    p->setPen(QColor("blue"));
    p->drawText(rect,gold.arg(_waves));
    p->restore();
}

void GameWindow::setBullet(Bullet* bullet){

}
