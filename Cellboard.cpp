#include "Cellboard.h"

#include <iostream>
#include <string>

Cellboard::Cellboard(int sizeI, int sizeJ)
    : m_sizeI(sizeI), m_sizeJ(sizeJ), m_data(new bool[m_sizeI * m_sizeJ])
{
    for (int i = 0; i < m_sizeI; ++i)
        for (int j = 0; j < m_sizeJ; ++j)
            setAlive(i, j, false);
}

Cellboard::~Cellboard()
{
    delete[] m_data;
}

bool Cellboard::isAlive(int i, int j)
{
    return m_data[m_sizeI * j + i];
}

void Cellboard::setAlive(int i, int j, bool alive)
{
    m_data[m_sizeI * j + i] = alive;
}

int Cellboard::getSizeI()
{
    return m_sizeI;
}

int Cellboard::getSizeJ()
{
    return m_sizeJ;
}

int Cellboard::getNbNeighboors(int i, int j)
{
    int count = 0;
    if ((i > 1) && (j > 1)) count += isAlive(i - 1, j - 1) ? 1 : 0;
    if ((i > 1)) count += isAlive(i - 1, j) ? 1 : 0;
    if ((i > 1) && (j < m_sizeJ - 1)) count += isAlive(i - 1, j + 1) ? 1 : 0;

    if ((i < m_sizeI - 1) && (j > 1)) count += isAlive(i + 1, j - 1) ? 1 : 0;
    if ((i < m_sizeI - 1)) count += isAlive(i + 1, j) ? 1 : 0;
    if ((i < m_sizeI - 1) && (j < m_sizeJ - 1)) count += isAlive(i + 1, j + 1) ? 1 : 0;

    if (j > 1) count += isAlive(i, j - 1) ? 1 : 0;
    if (j < m_sizeJ) count += isAlive(i, j + 1) ? 1 : 0;

    return count;
}

void showErrorMessage(std::string msg)
{
    std::cerr << msg << "\n";
}

void copyCellboard(Cellboard* src, Cellboard* dest)
{
    if (((src->getSizeI() != dest->getSizeI()) || (src->getSizeJ() != dest->getSizeJ())))
        return showErrorMessage("Cellboard size mismatch.");

    for (int i = 0; i < src->getSizeI(); ++i)
        for (int j = 0; j < src->getSizeJ(); ++j)
            dest->setAlive(i, j, src->isAlive(i, j));
}
