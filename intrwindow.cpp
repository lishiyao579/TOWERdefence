#include "intrwindow.h"
#include <QPainter>
IntrWindow::IntrWindow(QWidget *parent) : QMainWindow(parent)
{
    setFixedSize(32*32,32*22);
    Button *btn=new Button(":/pics/return.png");
    btn->setParent(this);
    btn->move(450,600);
    connect(btn, &QPushButton::clicked, this, [=](){
        btn->zoomDown();
        btn->zoomUp();
        emit back();
    });


}

void IntrWindow::paintEvent(QPaintEvent *event){
    QPainter *p =new QPainter(this);
    p->drawPixmap(0,0,QPixmap(":/pics/helpbg.png"));
    QRectF rect(100,100,800,500);
    QFont font("黑体",16,true);
    p->setFont(font);
    p->setPen(QColor(255,143,36));
    //painter.drawText(const QRectF(fmt.width(text), fmt.height()),Qt::AlignLeft, text);
    p->drawText(rect,Qt::AlignCenter,"这里要传一个帮助文档");

}
