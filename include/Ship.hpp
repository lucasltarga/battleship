#pragma once
#include <vector>

#include "Cell.hpp"

class Board;
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
    
    int randOrientation();
    int randPosition();
    bool positionIsValid(int posX, int posY, Board board);
};