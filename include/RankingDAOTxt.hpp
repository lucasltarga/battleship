#pragma once
#include "RankingDAO.hpp"
#include <fstream>

#define FILENAME "../data/ranking.txt"
#define MAX_LINE_SIZE 100

class RankingDAOTxt : public RankingDAO{
public:
    RankingDAOTxt();
    ~RankingDAOTxt();

    void save();
    void load();
};