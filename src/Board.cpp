#include "../include/Board.hpp"
#include "../include/Cruiser.hpp"
#include "../include/Submarine.hpp"
#include "../include/Destroyer.hpp"
#include "../include/Battleship.hpp"
#include "../include/Carrier.hpp"
#include <random>

#define SIZE 10

Board::Board() :
    board(SIZE, std::vector<Cell*>(SIZE, nullptr))
{
    this->size = SIZE;

    for(int i = 0; i < this->size; i++){
        for(int j = 0; j < this->size; j++){
            board[i][j] = new Cell();
        }
    }

    this->ships.push_back(new Cruiser());
    this->ships.push_back(new Submarine());
    this->ships.push_back(new Destroyer()); 
    this->ships.push_back(new Battleship()); 
    this->ships.push_back(new Carrier());   
}

Board::~Board(){
}

std::vector<std::vector<Cell*>> Board::getBoard(){
    return this->board;
}

int Board::getSize(){
    return this->size;
}

void Board::setBoard(std::vector<std::vector<Cell*>> board){
    this->board = board;
}

void Board::setSize(int size){
    this->size = size;
}

void Board::createIsles(int q){
    int c = 0;
    int pos[2];

    while(c < q){
        _randPosition(pos);
        board[pos[0]][pos[1]]->setValue(ISLE);
        isles.push_back(board[pos[0]][pos[1]]);
    }
}

void Board::_randPosition(int* pos){
    srand(time(NULL));

    do{
        pos[0] = rand() % SIZE;
        pos[1] = rand() % SIZE;

    }while(!this->_positionIsValid(pos[0], pos[1]));
}

bool Board::_positionIsValid(int posX, int posY){
    if(board[posX][posY] != nullptr){
        if(board[posX][posY]->getValue() == '~'){
            return 1;
        }
        else{
            return 0;
        }
    }
    else{
        return 0;
    }
}

//TODO
void Board::placeCarrier(){

}

//TODO
void Board::placeCruiser(){

}

//TODO
void Board::placeSubmarine(){

}

//TODO
void Board::placeBattleship(){

}

//TODO
void Board::placeDestroyer(){

}

void Board::placeShips(){
    placeCarrier();
    placeBattleship();
    placeDestroyer();
    placeSubmarine();
    placeCruiser();
}

void Board::draw(){
    std::cout << "   ";
    for(int i = 0; i < this->size; i++){
        std::cout << char(i+65) << " ";
    }
    std::cout << std::endl;
    for(int i = 0; i < this->size; i++){
        if(i < 9){
            std::cout << " " << i+1 << " ";
        }
        else{
            std::cout << i+1 << " ";
        }
        for(int j = 0; j < this->size; j++){
            board[i][j]->draw();
            std::cout << " ";
        }
        std::cout << std::endl;
    }
}