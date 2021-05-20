#include "../include/Board.hpp"
#include "../include/Cruiser.hpp"
#include "../include/Submarine.hpp"
#include "../include/Destroyer.hpp"
#include "../include/Battleship.hpp"
#include "../include/Carrier.hpp"
#include <random>

#define SIZE 10

Board::Board() :
    //cria um board de vector com tamanho e tipo
    //o tipo é vector de ponteiros pra celulas e insere NULL em todas elas
    //Se inserirmos Cell direto ele gera varios apontamentos para a MESMA celula
    board(SIZE, std::vector<Cell*>(SIZE, nullptr))
{
    this->size = SIZE;

    //para cada coordenada de board insere uma nova celula
    for(int i = 0; i < this->size; i++){
        for(int j = 0; j < this->size; j++){
            board[i][j] = new Cell();
        }
    }
}

Board::~Board(){
    for(int i = 0; i < this->size; i++){
        for(int j = 0; j < this->size; j++){
            delete(board[i][j]);
        }
    }
}

std::vector<std::vector<Cell*> > Board::getBoard(){
    return this->board;
}

int Board::getSize(){
    return this->size;
}

void Board::setBoard(std::vector<std::vector<Cell*> > board){
    this->board = board;
}

void Board::setSize(int size){
    this->size = size;
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