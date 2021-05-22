#include "../include/Human.hpp"

Human::Human(){
}

Human::~Human(){
}

std::string Human::getInput(){
    std::string input;
    getline(std::cin, input);
    return input;
}

bool Human::isInputValid(std::string input){
    //TODO
    return 0;
}

/**
 * Checks if shot hits water, isle or ship.
 * Ship parts and isles are destroyed if hit.
 * Player earns or loses points respectively.
 * Returns 1 if hits something.
*/
bool Human::shoot(Board* board){
    //TODO: need to get user input
    int pos[2] = {5,5}; //temp
    
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

        /**
         * Finds the ship part that was shot and destroy it.
         * If ship is fully destroyed, player earns bonus points.
        */
        else if(hitCell->getValue() != WATER){
            std::vector<Ship*> ships = board->getShips();

            //checks each ship
            for(int i = 0; i < (int)ships.size(); i++){
                //finds the part
                std::vector<Cell*> parts = ships.at(i)->getParts();
                for(int j = 0; j < (int)parts.size(); j++){
                    if(parts[j]->getPosX() == pos[0] && parts[j]->getPosY() == pos[1]){
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