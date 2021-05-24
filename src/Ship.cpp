#include "../include/Ship.hpp"

//Padrão da orientação = 1 Horizontal, 2 Vertical;
Ship::Ship(){
    this->size = 0;
    this->type = '0';
    this->orientation = 0;
}

Ship::~Ship(){

}

int Ship::getSize(){
    return this->size;
}

std::vector<Cell*> Ship::getParts(){
    return this->parts;
}

char Ship::getType(){
    return this->type;
}

bool Ship::getOrientation(){
    return this->orientation;
}
void Ship::setSize(int size){
    this->size = size;
}
void Ship::setParts(std::vector<Cell*> parts){
    this->parts = parts;
}

void Ship::setType(char type){
    this->type = type;
}

void Ship::setOrientation(bool orientation){
    //TRUE = HORIZONTAL
    //FALSE = VERTICAL
    this->orientation = orientation;
}

 Cell* Ship::createPart(int x, int y, char value){
     this->parts.push_back(new Cell());
     this->parts.back()->setPosX(x);
     this->parts.back()->setPosY(y);
     this->parts.back()->setValue(value);
 }