#include "../include/UI.hpp"

UI::UI(){
}

UI::~UI(){
}

void UI::clear(){
    #ifdef __unix__
        system("clear");
    #elif __WIN32
        system("cls");
    #endif
}

void UI::drawTopUI(Player* player){
    std::cout << "==============================" << std::endl;
    std::cout << player->getName() << " ---------- " 
                << "Points: " << player->getPoints() << std::endl;
    player->getBoard()->draw();
    std::cout << "==============================" << std::endl;
}

void UI::drawBottomUI(Player* player){
    std::cout << "It's your turn, " << player->getName() << "!" << std::endl;
}

void UI::drawMainMenu(){
    std::cout << "=== Battleship ===" << std::endl;
    std::cout << "Select an option: " << std::endl;
    std::cout << "(1) - New game - Singleplayer" << std::endl;
    std::cout << "(2) - New game - Multiplayer" << std::endl;
    std::cout << "(3) - Load saved game" << std::endl;
    std::cout << "(4) - Ranking" << std::endl;
}

void UI::drawRanking(){
    std::vector<Player*> players = Ranking::getPlayers();
    std::cout << "=== Ranking ===" << std::endl;
    if(players.empty()){
        std::cout << "Ranking is not ready yet :(" << std::endl;
    }
    else{
        for(int i = 0; i < players.size(); i++){
            std::cout << i+1 << " - " << players.at(i)->getName() << ":" <<
                players.at(i)->getPoints() << "points" << std::endl;
        }
    }
}

std::string UI::getInput(){
    std::cout << "Input: ";
    std::string input;
    std::getline(std::cin, input);
    return input;
}