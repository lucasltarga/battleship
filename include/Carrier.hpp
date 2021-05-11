#pragma once
#include "Ship.hpp"

class Carrier : public Ship{
public:
    Carrier();
    ~Carrier();
    virtual void placeShip();
       
};
