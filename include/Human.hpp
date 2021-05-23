#pragma once
#include "Player.hpp"

class Human : public Player{
public:
    Human();
    ~Human();

    std::string getInput();
    bool isInputValid(int * pos);
    bool shoot(Board* board);
    void convertCoordinates(std::string input, int * pos);
};