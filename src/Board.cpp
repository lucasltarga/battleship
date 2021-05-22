#include "../include/Board.hpp"

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

std::vector<Ship*> Board::getShips(){
    return this->ships;
}

std::vector<Cell*> Board::getIsles(){
    return this->isles;
}

int Board::getSize(){
    return this->size;
}

void Board::setBoard(std::vector<std::vector<Cell*> > board){
    this->board = board;
}

void Board::setShips(std::vector<Ship*> ships){
    this->ships = ships;
}

void Board::setIsles(std::vector<Cell*> isles){
    this->isles = isles;
}

void Board::setSize(int size){
    this->size = size;
}

void Board::draw(){
    if(!this->board.empty()){
        std::cout << "   ";
        for(int i = 0; i < this->size; i++){
            std::cout << char(i+65) << " ";
        }
        std::cout << std::endl;
        for(int i = 0; i < this->size; i++){
            std::cout << " " << i << " ";
            for(int j = 0; j < this->size; j++){
                if(board[i][j]){
                    board[i][j]->draw();
                }
                else{
                    std::cout << "(Board::draw) ERROR: Cannot draw cell." << std::endl;
                }
                std::cout << " ";
            }
            std::cout << std::endl;
        }
    }
    else{
        std::cout << "(Board::draw) ERROR: Cannot draw board." << std::endl;
    }
}