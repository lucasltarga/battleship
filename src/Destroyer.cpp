#include "../include/Destroyer.hpp"

Destroyer::Destroyer(){
    this->setSize(4);
    this->setType('3');
}

Destroyer::~Destroyer(){

}
void Destroyer::place(Board board){
    // coordenadas[0] -> vertical ou horizontal
    //coordenadas[1] = posx
    //coordenadas[2] = posy
    bool flag = false;
    int i = 0;
    std::vector<int> coords (9, NULL);
    do {
        coords[0] = randOrientation();
        //pega uma coordenada aleatória para ser a posição inicial
        coords[1] = randPosition();
        coords[2] = randPosition();
        if (coords[0] == 1){
            //ship na horizontal X++ e Y=
            coords[3] = (coords[1] + 1);
            coords[5] = (coords[1] + 2);
            coords[7] =(coords[1] + 3);
            coords[4] = coords[2];
            coords[6] = coords[2];
            coords[8] = coords[2];
        } else if (coords[0] == 2){
            //Ship na vertical 
            coords[3] = coords[1];
            coords[5] = coords[1];
            coords[7] = coords[1];
            coords[4] = (coords[2] - 1);
            coords[6] = (coords[2] - 2);
            coords[8] = (coords[2] - 3);

        }
        for (i=0; i < 4; i+2){
            
            if (positionIsValid(coords[i+1], coords[i+2], board)){
                flag = true;
            }else{
                flag = false;
                break;
            }
            
        }

    }while (!flag);
    //quando sair do Do While o vector de coordenadas vai ter coordenadas válidas para inserir o ship por completo
}