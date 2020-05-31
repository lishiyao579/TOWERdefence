#include "mw1.h"
#include "ui_mw1.h"
#include "button.h"
#include "gamewindow.h"
#include <QPushButton>
using namespace std;


MW1::MW1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MW1)
{
    ui->setupUi(this);
    setFixedSize(32*32,22*32);

   // StartWindow *win = new StartWindow;
    //win->show();
    //  connect()
    Button *btn1 = new Button(":/pics/startbtn.png");
    btn1->setParent(this);
    btn1->move(600,600);
//    btn->move(this->size().width()/2, this->size().height()/2);
    GameWindow *gm = new GameWindow;
    connect(btn1,&QPushButton::clicked,this,[=](){
        this->close();
        gm->show();
    });

}

MW1::~MW1()
{
    delete ui;
}

void MW1::paintEvent(QPaintEvent *e){

    QPainter *pa;
    pa = new QPainter();
    pa->begin(this);

    QPixmap bgpic(":/pics/startpix.jpg");
    pa->drawPixmap(0, 0, bgpic);


    pa->end();
    delete pa;
}
