#pragma once
#include <vector>
#include "PosRanking.hpp"

class Ranking{
private:
    std::vector<PosRanking*> ranking;

public:
    Ranking();
    ~Ranking();

    std::vector<PosRanking*> getRanking();
    void updateRanking(std::string name, int points);
    void setRanking(std::vector<PosRanking*> ranking);
};