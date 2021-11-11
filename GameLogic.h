#pragma once

#include "Cellboard.h"

class GameLogic
{
public:
    GameLogic(int sizeI, int sizeJ);

    Cellboard* getCellboard();

    bool applyGameRuleOnCell(bool isAlive, int nbNeighboors);

    void update();

private:
    int m_sizeI;
    int m_sizeJ;
    Cellboard m_currentGenCellboard;
    Cellboard m_nextGenCellboard;
};
