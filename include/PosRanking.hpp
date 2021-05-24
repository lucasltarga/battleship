#pragma once
#include <string>
class PosRanking{
private:
    std::string name;
    int points;

public:
    PosRanking();
    PosRanking(std::string name, int points);
    ~PosRanking();

    std::string getName();
    int getPoints();
    void setName(std::string name);
    void setPoints(int points);
};