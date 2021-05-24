#include "../include/Human.hpp"
#include <sstream>

Human::Human(){
}

Human::~Human(){
}

std::string Human::getInput(){
    std::string input;
    getline(std::cin, input);
    return input;
}
void Human::convertCoordinates(std::string input, int * pos){
    int posAux, tam;
    char aux;
    std::string posix , posiy;
    int position[2] = {0,0};

    //converting the x coordinate
    posAux = input.find(" ", 0);
    posix = input.substr(0, posAux);
    std::stringstream ss;
    ss << posix;
    ss >> position[0];

    //converting the y coordinate
    tam = posAux+1;
    posAux = input.find(" ", posAux+1);
    posiy = input.substr(tam, posAux-tam);
    aux = posiy[0];
    position[1] = ((int)aux - 65);
    pos[0] = position[0];
    pos[1] = position[1];

}

bool Human::isInputValid(int *pos){
    if (pos[0] >= 0 && pos[0] < 10 && pos[1] >= 0 && pos[1] < 10){
        return 1;
    }else{
        std::cout << "Please, try a valid coordnate" << std::endl;
        return 0;
    }
    return 0;
}

/**
 * Checks if shot hits water, isle or ship.
 * Ship parts and isles are destroyed if hit.
 * Player earns or loses points respectively.
 * Returns 1 if hits something.
*/
bool Human::shoot(Board* board){
    //get user input, convert the coordnates and test if is valid and visible.
    bool valid = false;
    int pos[2] = {0,0};
    do{
        std::cout << "Enter the two coordinates with space between them" << std::endl;
        convertCoordinates(getInput(), pos);
        if (isInputValid(pos)){
            Cell* Celula = board->getBoard()[pos[0]][pos[1]];
            valid = !Celula->isVisible();
        }
    }while(!valid);
    
    
    
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