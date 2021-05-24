#include "../include/BoardBuilder.hpp"

BoardBuilder::BoardBuilder(){
    this->reset();
    this->auxPos[0] = 0;
    this->auxPos[1] = 0;

    //rand() will be used in randposition()
    srand(time(nullptr)); 
}

BoardBuilder::~BoardBuilder(){

}

void BoardBuilder::reset(){
    this->board = new Board();
}

/** 
 *  These set methods place q of each element on the board, 
 *  in random directions and positions, first checking if the
 *  cells are empty.
*/

void BoardBuilder::setCruiser(int q){
    for(int i = 0; i < q; i++){
        int dir = randDirection();
        randPosition(auxPos);

        Ship* ship = this->board->createShip(CRUISER);

        while(!checkEmptyCells(2, auxPos[0], auxPos[1], dir)){
            randPosition(auxPos);
        }

        placeParts(2, auxPos[0], auxPos[1], dir, ship);
    }   
}

void BoardBuilder::setSubmarine(int q){
    for(int i = 0; i < q; i++){
        int dir = randDirection();
        randPosition(auxPos);

        Ship* ship = this->board->createShip(SUBMARINE);

        while(!checkEmptyCells(3, auxPos[0], auxPos[1], dir)){
            randPosition(auxPos);
        }

        placeParts(3, auxPos[0], auxPos[1], dir, ship);
    }   
}

void BoardBuilder::setDestroyer(int q){
    for(int i = 0; i < q; i++){
        int dir = randDirection();
        randPosition(auxPos);

        Ship* ship = this->board->createShip(DESTROYER);

        while(!checkEmptyCells(4, auxPos[0], auxPos[1], dir)){
            randPosition(auxPos);
        }

        placeParts(4, auxPos[0], auxPos[1], dir, ship);
    }   
}

void BoardBuilder::setBattleship(int q){
    for(int i = 0; i < q; i++){
        int dir = randDirection();
        randPosition(auxPos);

        Ship* ship = this->board->createShip(BATTLESHIP);

        while(!checkEmptyCells(5, auxPos[0], auxPos[1], dir)){
            randPosition(auxPos);
        }

        placeParts(5, auxPos[0], auxPos[1], dir, ship);
    }       
}

//TODO: debug this method.
//segfault eventually
void BoardBuilder::setCarrier(int q){
    for(int i = 0; i < q; i++){
        int dir = randDirection();
        randPosition(auxPos);

        Ship* ship = this->board->createShip(CARRIER);

        if(dir == static_cast<int>(CardinalDirections::NORTH)
            || dir == static_cast<int>(CardinalDirections::SOUTH)){
                    
            while(!checkEmptyCells(5, auxPos[0], auxPos[1], dir) &&
                    !checkEmptyCells(5, auxPos[0]+1, auxPos[1], dir)){
                randPosition(auxPos);
            }

            placeParts(5, auxPos[0], auxPos[1], dir, ship);
            placeParts(5, auxPos[0]+1, auxPos[1], dir, ship);
        }

        if(dir == static_cast<int>(CardinalDirections::WEST) ||
            dir == static_cast<int>(CardinalDirections::EAST)){
                    
            while(!checkEmptyCells(5, auxPos[0], auxPos[1], dir) &&
                    !checkEmptyCells(5, auxPos[0], auxPos[1]+1, dir)){
                randPosition(auxPos);
            }

            placeParts(5, auxPos[0], auxPos[1], dir, ship);
            placeParts(5, auxPos[0], auxPos[1]+1, dir, ship);
        }
    }
}

void BoardBuilder::setIsles(int q){
    for(int i = 0; i < q; i++){
        randPosition(auxPos);

        //while cell is not empty
        while(this->board->getBoard()[auxPos[0]][auxPos[1]]->getValue() != WATER){
            randPosition(auxPos);
        }

        Cell* cell = this->board->getBoard()[auxPos[0]][auxPos[1]];
        cell->setValue(ISLE);
        this->board->getIsles().push_back(cell);
    }       
}

int* BoardBuilder::randPosition(int* pos){
    pos[0] = rand()%BOARDSIZE;
    pos[1] = rand()%BOARDSIZE;
    return pos;
}

int BoardBuilder::randDirection(){
    return rand()%4;
}

bool BoardBuilder::isBoundary(int posX, int posY){
    if(posX < 0 || posX >= BOARDSIZE
        || posY < 0 || posY >= BOARDSIZE)
        return true;
    else
        return false;
}

/** 
*   Recursive method used to check if positions are available 
*   to place board elements like ships or isles.
*   Uses posX and posY as an initial point then checks q cells
*   in the given direction. Returns 1 if cells are empty.
*/
bool BoardBuilder::checkEmptyCells(int q, int posX, int posY, int direction){
    if(!isBoundary(posX, posY)){
        if(this->board->getBoard()[posX][posY]->getValue() != WATER){
            return 0;
        }
        else if(q==1){
            return 1;
        }
        else{
            if(direction == static_cast<int>(CardinalDirections::NORTH)){
                return checkEmptyCells(--q, posX, --posY, direction);
            }
            else if(direction == static_cast<int>(CardinalDirections::SOUTH)){
                return checkEmptyCells(--q, posX, ++posY, direction);
            }
            else if(direction == static_cast<int>(CardinalDirections::WEST)){
                return checkEmptyCells(--q, --posX, posY, direction);
            }
            else if(direction == static_cast<int>(CardinalDirections::EAST)){
                return checkEmptyCells(--q, ++posX, posY, direction);
            }
        }

    }
    else
        return 0;
    return 0;
}

void BoardBuilder::placeParts(int q, int posX, int posY, int direction, Ship* ship){
    if(direction == static_cast<int>(CardinalDirections::NORTH)){
        for(int i = 0; i < q; i++){
            Cell* cell = this->board->getBoard()[posX][posY-i];
            int x = cell->getPosX();
            int y = cell->getPosY();
            char value = cell->getValue();
            cell->setValue(ship->getType());      
            ship->getParts().push_back(ship->createPart(x, y, value));
        }
    }
    else if(direction == static_cast<int>(CardinalDirections::SOUTH)){
        for(int i = 0; i < q; i++){
            Cell* cell = this->board->getBoard()[posX][posY+i];
            int x = cell->getPosX();
            int y = cell->getPosY();
            char value = cell->getValue();
            cell->setValue(ship->getType());      
            ship->getParts().push_back(ship->createPart(x, y, value));          
        }
    }
    else if(direction == static_cast<int>(CardinalDirections::WEST)){
        for(int i = 0; i < q; i++){
            Cell* cell = this->board->getBoard()[posX-i][posY];
            int x = cell->getPosX();
            int y = cell->getPosY();
            char value = cell->getValue();
            cell->setValue(ship->getType());      
            ship->getParts().push_back(ship->createPart(x, y, value));
        }
    }
    else if(direction == static_cast<int>(CardinalDirections::EAST)){
        for(int i = 0; i < q; i++){
            Cell* cell = this->board->getBoard()[posX+i][posY];
            int x = cell->getPosX();
            int y = cell->getPosY();
            char value = cell->getValue();
            cell->setValue(ship->getType());      
            ship->getParts().push_back(ship->createPart(x, y, value));
        }    
    }
}

Board* BoardBuilder::getResult(){
    return this->board;
}