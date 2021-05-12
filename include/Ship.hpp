#pragma once
#include <vector>
#include "../include/Board.hpp"
#include "Cell.hpp"

class Ship{
private:
    int size;
    std::vector<Cell*> parts;
    char type;
    bool orientation;

public:
    Ship();
    ~Ship();

    int getSize();
    std::vector<Cell*> getParts();
    char getType();
    bool getOrientation();
    void setSize(int size);
    void setParts(std::vector<Cell*> parts);
    void setType(char type);
    void setOrientation(bool orientation);
    virtual void place(Board board) = 0;
    int randOrientation();
    int randPosition();
    bool positionIsValid(int posX, int posY, Board board);
};