#include "../include/Carrier.hpp"

Carrier::Carrier(){
    this->setSize(10);
    this->setType(CARRIER);
}

Carrier::~Carrier(){

}
void Carrier::place(Board board){
    // coordenadas[0] -> vertical ou horizontal
    //coordenadas[1] = posx
    //coordenadas[2] = posy
    bool flag = false;
    int i = 0;
    std::vector<int> coords1 (11, 0);
    std::vector<int> coords2 (11, 0);

    do {
        coords1[0] = randOrientation();
        coords2[0] = coords2[0];
        //pega uma coordenada aleatória para ser a posição inicial
        coords1[1] = randPosition();
        coords1[2] = randPosition();
        if (coords1[0] == 1){
            //ship na horizontal X++ e Y=
            for (i=1; i < 11; i++){
                if (i%2 == 0){
                    coords1[i]= coords1[2];
                    coords1[i]= coords1[2];
                } else {
                    coords1[i] = coords1[1];
                    coords2[i] = (coords2[1]+i);
                }
            }
        } else if (coords1[0] == 2){
            //Ship na vertical 
            for (i=1; i < 11; i++){
                if (i%2 != 0){
                    coords1[i] = coords1[1];
                    coords1[i] = coords1[1];
                } else {
                    coords1[i] = coords1[2];
                    coords2[i] = (coords2[2]-i);
                }
            }

        }
        for (i=0; i < 5; i+=2){
            
            if (positionIsValid(coords1[i+1], coords1[i+2], board)){
                flag = true;
            }else{
                flag = false;
                break;
            }
            if (positionIsValid(coords2[i+1], coords1[i+2], board)){
                flag = true;
            }else{
                flag = false;
                break;
            }
            
        }

    }while (!flag);
    //quando sair do Do While o vector de coordenadas vai ter coordenadas válidas para inserir o ship por completo
    if (coords1[0] == 1){
        setOrientation(true);
    }else{
        setOrientation(false);
    }
    for (i=0; i<9; i+=2){
        board.placeParts(coords1[i+1],coords1[i+2], CARRIER);
        board.placeParts(coords2[i+1],coords2[i+2], CARRIER);
        
    }
}