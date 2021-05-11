#pragma once
#include "Ship.hpp"

class Destroyer : public Ship{
public: 
    Destroyer();
    ~Destroyer();
    virtual void placeShip();

};