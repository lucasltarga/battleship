#include "../include/Board.hpp"
#include "../include/BoardBuilder.hpp"

int main(){
    BoardBuilder BoardBuilder;

    BoardBuilder.setCarrier(1);
    BoardBuilder.setBattleship(1);
    BoardBuilder.setDestroyer(1);
    BoardBuilder.setSubmarine(1);
    BoardBuilder.setCruiser(1);
    BoardBuilder.setIsles(8);

    BoardBuilder.getResult()->draw();
    return 0;
}