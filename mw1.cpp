#include "mw1.h"
#include "ui_mw1.h"
#include "button.h"
#include "gamewindow.h"
#include "intrwindow.h"
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

    connect(btn1,&QPushButton::clicked,this,[=](){
        GameWindow *gm = new GameWindow;
        btn1->zoomDown();
        btn1->zoomUp();
        QTimer::singleShot(300,this,[=](){
            this->close();
            gm->show();
        });

    });

    Button *btn2 = new Button(":/pics/helpbtn.png");
    btn2->setParent(this);
    btn2->move(300,600);

    IntrWindow *help = new IntrWindow;
    connect(btn2,&QPushButton::clicked,this,[=](){
        btn2->zoomDown();
        btn2->zoomUp();
        QTimer::singleShot(300,this,[=](){
            this->hide();
            help->show();
        });
    });
    connect(help,&IntrWindow::back,this,[=](){
        help->hide();
        this->show();
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
