#pragma once
#include <iostream>

#define WATER '~'
#define CRUISER '1'
#define SUBMARINE '2'
#define DESTROYER '3'
#define BATTLESHIP '4'
#define CARRIER '5'
#define ISLE '^'

class Cell{
    private:
        bool visible;
        char value;
        int posX;
        int posY;

    public:
        Cell();
        ~Cell();

        bool isVisible();
        char getValue();
        int getPosX();
        int getPosY();
        void setVisible(bool visible);
        void setValue(char value);
        void setPos(int posX, int posY);
        void draw();
};