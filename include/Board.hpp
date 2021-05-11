#pragma once

#include "Cell.hpp"
#include "Ship.hpp"
#include <vector>

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
        int getSize();
        void setBoard(std::vector<std::vector<Cell*> > board);
        void setSize(int size);

        void createIsles(int q);
        void _randPosition(int* pos);
        bool _positionIsValid(int posX, int posY);
        void placeCarrier();
        void placeCruiser();
        void placeSubmarine();
        void placeBattleship();
        void placeDestroyer();
        void placeShips();
        void draw();
};