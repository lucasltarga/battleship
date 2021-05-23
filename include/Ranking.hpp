#pragma once
#include "Player.hpp"

class Ranking{
private:
    static std::vector<Player*> players;

public:
    Ranking();
    ~Ranking();

    static std::vector<Player*> getPlayers();
    static void updateRanking(Player* player);
};