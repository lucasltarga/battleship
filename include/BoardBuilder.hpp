#pragma once
#include "../include/Board.hpp"
#include "../include/Battleship.hpp"
#include "../include/Carrier.hpp"
#include "../include/Destroyer.hpp"
#include "../include/Cruiser.hpp"
#include "../include/Submarine.hpp"
#include <random>

#define BOARDSIZE 10

enum class CardinalDirections{
    NORTH = 0,
    SOUTH,
    WEST,
    EAST
};

class BoardBuilder{
private:
    Board* board;
    int auxPos[2];

public:
    BoardBuilder();
    ~BoardBuilder();

    void reset();
    void setCruiser(int q);
    void setSubmarine(int q);
    void setDestroyer(int q);
    void setBattleship(int q);
    void setCarrier(int q);
    void setIsles(int q);

    int* randPosition(int* pos);
    int randDirection();
    bool isBoundary(int posX, int posY);
    bool checkEmptyCells(int q, int posX, int posY, int direction);
    void placeParts(int q, int posX, int posY, int direction, Ship* ship);
    Board* getResult();
};