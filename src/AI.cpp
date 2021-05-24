#include "../include/AI.hpp"

AI::AI(){
    srand(time(nullptr));
}

AI::~AI(){

}

void AI::randomShoot(Board* board){
    int pos[2];
    Cell* cell;
    do{
        pos[0] = rand()%BOARDSIZE;
        pos[1] = rand()%BOARDSIZE;
        cell = board->getBoard()[pos[0]][pos[1]];
    }while(cell->isVisible());
    this->nextShots.push(cell);
}

Cell* AI::getNextShot(){
    Cell* nextShot = this->nextShots.top();
    this->nextShots.pop();
    return nextShot;
}

/**
 * Checks each direction and pushes non-visible
 * cells into nextShots stack
*/
void AI::updateNextShots(Cell* cell, Board* board){
    int x = cell->getPosX();
    int y = cell->getPosY();

    if( (x+1) < BOARDSIZE && !board->getBoard()[x+1][y]->isVisible()){
        nextShots.push(board->getBoard()[x+1][y]);
    }
    if( (x-1) >= 0 && !board->getBoard()[x-1][y]->isVisible()){
         nextShots.push(board->getBoard()[x-1][y]);
    }
    if( (y+1) < BOARDSIZE && !board->getBoard()[x][y+1]->isVisible()){
        nextShots.push(board->getBoard()[x][y+1]);
    }
    if( (y-1) >= 0 && !board->getBoard()[x][y-1]->isVisible()){
        nextShots.push(board->getBoard()[x][y-1]);
    }
}

bool AI::shoot(Board* board){
    if(nextShots.empty()){
        randomShoot(board);
    }
    Cell* cell = this->getNextShot();
    cell->setVisible(true);
    if(cell->getValue() != WATER){
        //if hit an isle, loses points
        if(cell->getValue() == ISLE){
            std::vector<Cell*> isles = board->getIsles();
            for(int i = 0; i < (int)isles.size(); i++){
                if(isles.at(i)->getPosX() == cell->getPosX() && isles.at(i)->getPosY() == cell->getPosY()){
                    isles.erase(isles.begin()+i);
                    this->setPoints(this->getPoints()-1);
                }
            }
            return 1;
        }
        else{
            this->setPoints(this->getPoints()+1);
            //add adj cells to nextshots stack
            updateNextShots(cell, board);

            std::vector<Ship*> ships = board->getShips();

            //checks each ship
            for(int i = 0; i < (int)ships.size(); i++){
                //finds the part
                std::vector<Cell*> parts = ships.at(i)->getParts();
                for(int j = 0; j < (int)parts.size(); j++){
                    if(parts[j]->getPosX() == cell->getPosX() && parts[j]->getPosY() == cell->getPosY()){
                        //destroy ship part
                        parts.erase(parts.begin()+j);
                        this->setPoints(this->getPoints()+1);
                        break;
                    }
                }
                if(parts.empty()){
                    //destroy ship
                    ships.erase(ships.begin()+i);
                    this->setPoints(this->getPoints()+2);
                    break;
                }
            }
            return 1;
        }
    }
    return 0;
}