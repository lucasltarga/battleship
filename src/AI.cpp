#include "../include/AI.hpp"

AI::AI(){
    srand(time(nullptr));
    this->randomShoot();
}

AI::~AI(){

}

void AI::randomShoot(){
    int pos[2] = {rand()%BOARDSIZE, rand()%BOARDSIZE};
    this->nextShot[0] = pos[0];
    this->nextShot[1] = pos[1];
    this->nextShotDirection = rand()%4;
}

bool AI::isBoundary(int posX, int posY){
    if(posX < 0 || posX >= BOARDSIZE
        || posY < 0 || posY >= BOARDSIZE)
        return true;
    else
        return false;
}

int* AI::getNextShot(){
    return this->nextShot;
}

//TODO
bool AI::shoot(Board* board){
    int* pos = this->getNextShot();

    //condition to avoid segfault
    if(board && board->getBoard()[pos[0]][pos[1]]){
        Cell* hitCell = board->getBoard()[pos[0]][pos[1]];
        hitCell->setVisible(true);

        //if hit an isle, loses points
        if(hitCell->getValue() == ISLE){
            std::vector<Cell*> isles = board->getIsles();
            for(int i = 0; i < (int)isles.size(); i++){
                if(isles.at(i)->getPosX() == pos[0] && isles.at(i)->getPosY() == pos[1]){
                    isles.erase(isles.begin()+i);
                    this->setPoints(this->getPoints()-1);
                }
            }
            return 1;
        }
        else{
            return 0;
        }
        //this->setNextShot();
    }
    return 0;
}