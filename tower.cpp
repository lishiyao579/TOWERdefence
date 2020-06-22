#include "tower.h"
#include "gamewindow.h"

int Tower::_attackRange=100;
int Tower::_shootFreq=120;

Tower::Tower(QPoint p,GameWindow * game,QString type)
{
    this->setPosX(p.x());
    this->setPosY(p.y());

    _game=game;
    _timer=new QTimer(this);
    _enemy=NULL;
    _type=type;
    if(type=="fire1"){
        _pix=QPixmap(":/pics/fire1.png");
        _canSlow=false;
    }
    else if(type=="fire2"){
        _pix=QPixmap(":/pics/fire2.png");
        _canSlow=true;
    }
    connect(_timer, SIGNAL(timeout()), this, SLOT(shoot()));

    //槽函数和信号参数数量必须相同！！！


}
Tower::~Tower(){
    delete _timer;
    _timer=NULL;
}

void Tower::setTower(QPainter* painter, QPoint p)
{
      painter->save();

      painter->drawPixmap(p.x()-_pix.height()/2,p.y()-_pix.width()/2,_pix);

      painter->setPen(Qt::darkRed);//画攻击圈
      painter->drawEllipse(p,_attackRange,_attackRange);
      painter->restore();
    //  onSet();//????
}

void Tower::searchEnemy(){

    if(_enemy){
        if(!_enemy->inShootCircle(QPoint(getPosX(),getPosY()),_attackRange)){
            _enemy = NULL;
            _timer->stop();
        }
    }
    else{
        for(int i=0;i<_game->Enemys().size();i++){
            if(_game->Enemys()[i]->inShootCircle(QPoint(getPosX(),getPosY()),_attackRange)){
                lockEnemy(_game->Enemys()[i]);
                break;
            }
        }
    }

}
void Tower::lockEnemy(WaterEnemy *enemy){
    _enemy=enemy;
    _timer->start(this->_shootFreq);
}

void Tower::shoot(){
  //  _timer=new QTimer(this);
    int hurt=10;
    Bullet *bullet=new Bullet(hurt,QPoint(getPosX(),getPosY()),_enemy,_game,_canSlow);
 //   bullet->move();
    _game->setBullet(bullet);

}
void Tower::onSet(){
    QMediaPlayer *p = new QMediaPlayer;
    p->setMedia(QUrl(("qrc:/sounds/t-d.mp3")));
    p->setVolume(10);
    p->play();
}

