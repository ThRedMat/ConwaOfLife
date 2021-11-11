#include "GameLogic.h"

#include <string>
#include <iostream>

GameLogic::GameLogic(int sizeI, int sizeJ) :
    m_sizeI(sizeI), m_sizeJ(sizeJ)
    , m_currentGenCellboard(sizeI, sizeJ), m_nextGenCellboard(sizeI, sizeJ)
{}

Cellboard* GameLogic::getCellboard()
{
    return &m_currentGenCellboard;
}

bool GameLogic::applyGameRuleOnCell(bool isAlive, int nbNeighboors)
{
    if (isAlive)
        return (nbNeighboors == 2) || (nbNeighboors == 3);

    return nbNeighboors == 3;
}

void GameLogic::update()
{
    for (int i = 0; i < m_sizeI; ++i)
    {
        for (int j = 0; j < m_sizeJ; ++j)
        {
            bool isAlive = m_currentGenCellboard.isAlive(i, j);
            int nbNeighboors = m_currentGenCellboard.getNbNeighboors(i, j);
            m_nextGenCellboard.setAlive(i, j, applyGameRuleOnCell(isAlive, nbNeighboors));
        }
    }

    copyCellboard(&m_nextGenCellboard, &m_currentGenCellboard);
}