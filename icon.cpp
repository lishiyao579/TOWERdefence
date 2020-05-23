#include "icon.h"
#include<iostream>
int ICON::GRID_SIZE = 32;


pair<string,ICON> pairArray[] =
{
    make_pair("player",ICON("player",1,13, 1, 2)),
    make_pair("stone",ICON("stone",4,9, 1, 1)),
    make_pair("fruit",ICON("fruit",3,6, 1, 1)),
    make_pair("tower",ICON("tower",0,11,2,2)),
    make_pair("position",ICON("position",5,0,2,2))
};

map<string,ICON> ICON::GAME_ICON_SET(pairArray,pairArray+sizeof(pairArray)/sizeof(pairArray[0]));


ICON::ICON(string name, int x, int y, int w, int h){
    this->typeName = name;
    this->srcX = x;
    this->srcY = y;
    this->width = w;
    this->height = h;
}

ICON ICON::findICON(string type){
    map<string,ICON>::iterator kv;
    kv = ICON::GAME_ICON_SET.find(type);
    if (kv==ICON::GAME_ICON_SET.end()){

       cout<<"Error: cannot find ICON"<<endl;
       return ICON();
    }
    else{
        return kv->second;
    }
}
