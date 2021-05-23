#pragma once
#include "RankingDAO.hpp"

class GameSaver{
public:
    GameSaver();
    ~GameSaver();

    static void saveRanking();
    static void loadRanking();
};