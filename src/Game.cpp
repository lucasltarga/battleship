#include "../include/Game.hpp"

Game::Game(){
    run();
}

Game::~Game(){
    delete this->player1;
    delete this->player2;
}

void Game::setSingleplayer(){
    this->hAI = true;
}

void Game::setMultiplayer(){
    this->hAI = false;
}

void Game::MainMenu(){
    UI::drawMainMenu();
    std::string rawinput;
    int op = 1;
    std::cin >> op;
    std::cin.ignore(10, '\n');

    if(op == 1){
        //New game - Singleplayer
        this->setSingleplayer();
        this->changeState(static_cast<int>(States::GameLoop));
    }
    else if(op == 2){
        //New game - Multiplayer
        this->setMultiplayer();
        this->changeState(static_cast<int>(States::GameLoop));
    }
    else if(op == 3){
        //Load saved game
        this->loadGame();
    }
    else if(op == 4){
        //Ranking
        this->changeState(static_cast<int>(States::Ranking));
    }
}

void Game::GameLoop(){
    this->initGame();

    //testing
    //UI::drawTopUI(this->player1);
    //UI::drawTopUI(this->player2);

    while(this->currentState != static_cast<int>(States::GameOver)){ 
        //Player1 turn
        this->turn(this->player1, this->player2->getBoard());

        //Player2 turn
        this->turn(this->player2, this->player1->getBoard());
    }
}

void Game::GameOver(){
    //UI
}

void Game::Ranking(){
    UI::drawRanking();
}

void Game::changeState(int newState){
    this->currentState = newState;
}

void Game::createDefaultBoard(){
    BoardBuilder* builder = new BoardBuilder(); 
    //builder->setCarrier(1);
    builder->setBattleship(1);
    builder->setDestroyer(1);
    builder->setSubmarine(1);
    builder->setCruiser(1);
    this->player1->setBoard(builder->getResult());

    builder->reset();
    //builder->setCarrier(1);
    builder->setBattleship(1);
    builder->setDestroyer(1);
    builder->setSubmarine(1);
    builder->setCruiser(1);
    this->player2->setBoard(builder->getResult());
    
    delete builder;
}

void Game::createIslesBoard(){
    BoardBuilder* builder = new BoardBuilder; 
    //builder->setCarrier(1);
    builder->setBattleship(1);
    builder->setDestroyer(1);
    builder->setSubmarine(1);
    builder->setCruiser(1);
    builder->setIsles(8);
    this->player1->setBoard(builder->getResult());

    builder->reset();
    //builder->setCarrier(1);
    builder->setBattleship(1);
    builder->setDestroyer(1);
    builder->setSubmarine(1);
    builder->setCruiser(1);
    builder->setIsles(8);
    this->player2->setBoard(builder->getResult());
    
    delete builder;
}

void Game::createSingleShipBoard(){
    BoardBuilder* builder = new BoardBuilder; 
    builder->setCarrier(1);
    this->player1->setBoard(builder->getResult());

    builder->reset();
    builder->setCarrier(1);
    this->player2->setBoard(builder->getResult());
    
    delete builder;
}

void Game::run(){
    this->currentState = static_cast<int>(States::MainMenu);
    this->hAI = true;

    while(this->currentState != -1){
        if(this->currentState == static_cast<int>(States::MainMenu)){
            this->MainMenu();
        }
        if(this->currentState == static_cast<int>(States::GameLoop)){
            this->GameLoop();
        }
        if(this->currentState == static_cast<int>(States::GameOver)){
            this->GameOver();
        }
        if(this->currentState == static_cast<int>(States::Ranking)){
            this->Ranking();
        }
    }
}

void Game::initGame(){
    this->player1 = new Human();
    std::cout << "Player1 name: " << std::endl;
    this->player1->setName(UI::getInput());

    if(this->hasAI()){
        this->player2 = new AI();
        this->player2->setName("FooBOT");
    }
    else{
        this->player2 = new Human();
        std::cout << "Player2 name: " << std::endl;
        this->player2->setName(UI::getInput());
    }

    std::cout << "Select board type: " << std::endl;
    std::cout << "(1) - Classic Board" << std::endl;
    std::cout << "(2) - Isles Board" << std::endl;
    std::cout << "(3) - Single Ship Board" << std::endl;
    int op;
    std::cin >> op;

    if(op == 1){
        this->createDefaultBoard();
        std::cout << "Default Board created!" << std::endl;
    }
    else if(op == 2){
        this->createIslesBoard();
        std::cout << "Isles Board created!" << std::endl;
    }
    else if(op == 3){
        this->createSingleShipBoard();
                std::cout << "Single Ship Board created!" << std::endl;
    }
}

void Game::turn(Player* player, Board* board){
    UI::clear();
    //always prints both boards
    UI::drawTopUI(this->player1);
    UI::drawTopUI(this->player2);

    UI::drawBottomUI(player);
    player->shoot(board);
    if(board->getShips().empty())
        this->changeState(static_cast<int>(States::GameOver));
}

bool Game::hasAI(){
    return this->hAI;
}

void Game::saveGame(){

}

void Game::loadGame(){

}