#include "../include/Ranking.hpp"

Ranking::Ranking(){

}

Ranking::~Ranking(){

}

std::vector<Player*> Ranking::getPlayers(){
    return players;
}

void Ranking::updateRanking(Player* player){
    for(int i; i < players.size(); i++){
        if(players.at(i)->getPoints() <= player->getPoints()){
            players.insert(players.begin()+i, player);
        }
    }
    if(players.size() >= 5){
        players.pop_back();
    }
}