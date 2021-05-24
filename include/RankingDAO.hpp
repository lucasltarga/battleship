#pragma once
#include "Ranking.hpp"
#include <iostream>

class RankingDAO{
public:
    RankingDAO();
    ~RankingDAO();

    virtual void save() = 0;
    virtual void load() = 0;
};