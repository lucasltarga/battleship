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

    this->ships.push_back(new Cruiser());
    this->ships.push_back(new Submarine());
    this->ships.push_back(new Destroyer()); 
    this->ships.push_back(new Battleship()); 
    this->ships.push_back(new Carrier());

    this->createIsles(4);
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

//Ilhas tem SIZE = 1
void Board::createIsles(int q){
    int c = 0;
    int pos[2];


    while(c < q){
        _randPosition(pos);
        board[pos[0]][pos[1]]->setValue(ISLE);
        isles.push_back(board[pos[0]][pos[1]]);
        c++;
    }
}
void Board::placeParts(int posX, int posY, char type){
    board[posX][posY]->setValue(type);
}

void Board::_randPosition(int* pos){
    srand(time(NULL));

    do{
        pos[0] = rand() % SIZE;
        pos[1] = rand() % SIZE;

    }while(!this->_positionIsValid(pos[0], pos[1]));
}

//Método movido para a classe ship
// bool Board::_positionIsValid(int posX, int posY){
//     if(board[posX][posY] != nullptr){
//         if(board[posX][posY]->getValue() == '~'){
//             return 1;
//         }
//         else{
//             return 0;
//         }
//     }
//     else{
//         return 0;
//     }
// }

void Board::placeShips(){

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