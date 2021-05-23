#pragma once
#include <string>
#include <iostream>
#include "Player.hpp"
#include "Ranking.hpp"

class UI{
public:
    UI();
    ~UI();

    static void clear();
    static void drawTopUI(Player* player);
    static void drawBottomUI(Player* player);
    static void drawMainMenu();
    static void drawRanking(Ranking* ranking);
    static std::string getInput();
};