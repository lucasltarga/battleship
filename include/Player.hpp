#pragma once
#include <string>
#include "Board.hpp"

#define BOARDSIZE 10

class Player{
private:
    std::string name;
    int points;
    Board* board;

public:
    Player();
    virtual ~Player();

    std::string getName();
    int getPoints();
    Board* getBoard();
    void setName(std::string name);
    void setPoints(int points);
    void setBoard(Board* board);
    virtual bool shoot(Board* board) = 0;
};