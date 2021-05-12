#pragma once
#include "Ship.hpp"

class Battleship : public Ship{
public: 
    Battleship();
    ~Battleship();
    void place(Board board);
};
