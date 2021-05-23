#include "../include/PosRanking.hpp"

PosRanking::PosRanking(){
    this->name = nullptr;
    this->points = 0;
}

PosRanking::PosRanking(std::string name, int points){
    this->name = name;
    this->points = points;
}

PosRanking::~PosRanking(){

}

std::string PosRanking::getName(){
    return this->name;
}
int PosRanking::getPoints(){
    return this->points;
}
void PosRanking::setName(std::string name){
    this->name = name;
}
void PosRanking::setPoints(int points){
    this->points = points;
}