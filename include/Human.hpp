#pragma once
#include "Player.hpp"

class Human : public Player{
public:
    Human();
    ~Human();

    std::string getInput();
    bool isInputValid(std::string input);
    bool shoot(Board* board);
};