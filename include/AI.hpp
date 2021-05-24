#pragma once
#include "Player.hpp"
#include <random>
#include <stack>

class AI : public Player{
private:
    std::stack<Cell*> nextShots;

public:
    AI();
    ~AI();

    void randomShoot(Board* board);
    Cell* getNextShot();
    void updateNextShots(Cell* cell, Board* board);
    bool shoot(Board* board);
};