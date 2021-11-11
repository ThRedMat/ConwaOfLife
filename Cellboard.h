#pragma once

class Cellboard
{
public:
    Cellboard(int sizeI, int sizeJ);
    ~Cellboard();

    bool isAlive(int i, int j);
    void setAlive(int i, int j, bool alive);
    int getNbNeighboors(int i, int j);

    int getSizeI();
    int getSizeJ();

private:
    int m_sizeI;
    int m_sizeJ;
    bool* m_data;
};

void copyCellboard(Cellboard* src, Cellboard* dest);
