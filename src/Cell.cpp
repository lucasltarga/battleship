#include "../include/Cell.hpp"

Cell::Cell(){
    this->visible = 0;
    this->value = WATER;
}

Cell::~Cell(){

}

bool Cell::isVisible(){
    return this->visible;
}

char Cell::getValue(){
    return this->value;
}

int Cell::getPosX(){
    return this->posX;
}

int Cell::getPosY(){
    return this->posY;
}
void Cell::setVisible(bool visible){
    this->visible = visible;
}

void Cell::setValue(char value){
    this->value = value;
}

void Cell::setPos(int posX, int posY){
    this->posX = posX;
    this->posY = posY;
}

void Cell::draw(){
    if(this->visible){
        std::cout << this->value;
    }
    else{
        std::cout << "#";
    }
}