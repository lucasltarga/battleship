#pragma once
#include "BoardBuilder.hpp"
#include "UI.hpp"
#include "Human.hpp"
#include "AI.hpp"
#include "GameSaver.hpp"
#include "Ranking.hpp"

enum class States{
    MainMenu = 0,
    GameLoop,
    GameOver,
    Ranking
};

class Game{
private:
    Player* player1;
    Player* player2;
    int currentState;
    bool hAI;
    Ranking* ranking;

public:
    Game();
    ~Game();

    void setSingleplayer();
    void setMultiplayer();
    void MainMenu();
    void GameLoop();
    void GameOver();
    void RankingState();
    void changeState(int newState);
    void createDefaultBoard();
    void createIslesBoard();
    void createSingleShipBoard();
    void run();
    void initGame();
    void turn(Player* player, Board* board);
    bool hasAI();
    void saveGame();
    void loadGame();
}; 