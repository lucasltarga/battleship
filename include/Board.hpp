#pragma once

#include "Cell.hpp"
#include "Ship.hpp"
#include "Cruiser.hpp"
#include "Submarine.hpp"
#include "Destroyer.hpp"
#include "Battleship.hpp"
#include "Carrier.hpp"
#include <random>

class Board{
private:
    std::vector<std::vector<Cell*> > board;
    std::vector<Ship*> ships;
    std::vector<Cell*> isles;
    int size;

public:
    Board();
    ~Board();

    std::vector<std::vector<Cell*> > getBoard();
    std::vector<Ship*> getShips();
    std::vector<Cell*> getIsles();
    int getSize();
    void setBoard(std::vector<std::vector<Cell*> > board);
    void setShips(std::vector<Ship*> ships);
    void setIsles(std::vector<Cell*> isles);
    void setSize(int size);
    Ship* createShip(char type);
    void draw();
};