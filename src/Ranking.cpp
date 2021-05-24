#include "../include/Ranking.hpp"

Ranking::Ranking(){

}

Ranking::~Ranking(){

}

std::vector<PosRanking*> Ranking::getRanking(){
    return this->ranking;
}

void Ranking::updateRanking(std::string name, int points){
    for(int i; i < (int)ranking.size(); i++){
        if(ranking.at(i)->getPoints() <= points){
            ranking.insert(ranking.begin()+i, new PosRanking(name, points));
        }
    }
    if(ranking.size() >= 5){
        ranking.pop_back();
    }
}

void Ranking::setRanking(std::vector<PosRanking*> ranking){
    this->ranking = ranking;
}