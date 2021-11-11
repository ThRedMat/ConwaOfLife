#pragma once

class GameLogic;
class FrameBuffer;

// Classe fort mal nomm�e !
class GameView
{
public:
    GameView(GameLogic* gameLogic);

    void processInputs();

    void display(FrameBuffer* frameBuffer);

private:
    GameLogic* m_gameLogic;
    int m_offsetI;
    int m_offsetJ;
};
