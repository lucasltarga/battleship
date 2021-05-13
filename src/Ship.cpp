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
int randOrientation(){
    //Retorna 1 ou 2
    // 1 horizontal
    // 2 vertical
    srand((unsigned)time(0));
    return (rand()%3)+1;
}
int randPosition(){
    srand((unsigned)time(0));
    return (rand()%10);
}
bool positionIsValid(int posX, int posY, Board board){
    if(board.getBoard()[posX][posY]->getValue() != NULL){
        if(board.getBoard()[posX][posY]->getValue() == '~'){
            return 1;
        }
        else{
            return 0;
        }
    }
    else{
        return 0;
    }
}