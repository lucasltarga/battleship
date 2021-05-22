#include "../include/Player.hpp"

Player::Player(){
    this->name = "";
    this->points = 0;
    this->board = nullptr;
}

Player::~Player(){
    delete this->board;
}

std::string Player::getName(){
    return this->name;
}

int Player::getPoints(){
    return this->points;
}

Board* Player::getBoard(){
    return this->board;
}

void Player::setName(std::string name){
    this->name = name;
}

void Player::setPoints(int points){
    this->points = points;
}

void Player::setBoard(Board* board){
    this->board = board;
}