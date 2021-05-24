#include "../include/RankingDAOTxt.hpp"

RankingDAOTxt::RankingDAOTxt(){
    
}

RankingDAOTxt::~RankingDAOTxt(){
    
}

void RankingDAOTxt::save(){
    // std::ofstream file(FILENAME, std::ios_base::out);
    // if(file.is_open()){
    //     for(auto r : Ranking::getRanking()){
    //         file << r->getName() << std::endl;
    //         file << r->getPoints() << std::endl;
    //     }
    // }    
}

void RankingDAOTxt::load(){
    // std::ifstream file(FILENAME);

    // if(file.is_open()){
    //     char name[MAX_LINE_SIZE];
    //     int points;

    //     while(!file.eof()){
    //         if(file.is_open()){
    //             file >> name;
    //             file >> points;
    //             Ranking::getRanking().push_back(new PosRanking(name, points));
    //         }
    //     }
    // }else{
    //     std::cout << "(RankingDAOTxt::load()) Error loading file." << std::endl;
    // }
    // file.close();
}