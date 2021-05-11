#pragma once
#include "Ship.hpp"

class Submarine : public Ship{
public:
    Submarine();
    ~Submarine();
    virtual void placeShip();

};