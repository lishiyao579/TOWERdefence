#ifndef RPGOBJ_H
#define RPGOBJ_H
#include <QObject>
#include <QMediaPlayer>
#include <QImage>
#include <QPainter>
#include <string>
#include <icon.h>
#include <map>
#include <QUrl>

using namespace std;
class RPGObj :public QObject
{
    Q_OBJECT
public:
    RPGObj(){}

    void initObj(string type);
    void show(QPainter * painter);

    void setPosX(int x){this->_pos_x=x;}
    void setPosY(int y){this->_pos_y=y;}

    int getPosX() const{return this->_pos_x;}
    int getPosY() const{return this->_pos_y;}
    int getHeight() const{return this->_icon.getHeight();}
    int getWidth() const{return this->_icon.getWidth();}


    string OBJtypeall[4]={"stone","waterenermy","tower","position"};

    string getObjType() const{return this->_icon.getTypeName();}//返回类名

protected:
    //所有坐标，单位均为游戏中的格

    QImage _pic;
    int _pos_x, _pos_y;//该物体在游戏中当前位置（左上角坐标）
    ICON _icon;//可以从ICON中获取对象的素材，尺寸等信息
signals:

public slots:
};

#endif // RPGOBJ_H
