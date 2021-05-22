#pragma once
#include "Player.hpp"
#include <random>

class AI : public Player{
private:
    int nextShot[2];
    int nextShotDirection;

public:
    AI();
    ~AI();

    void randomShoot();
    int* getNextShot();
    bool isBoundary(int posX, int posY);
    bool shoot(Board* board);
};