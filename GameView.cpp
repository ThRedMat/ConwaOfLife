#include "GameView.h"

#include "GameLogic.h"
#include "FrameBuffer.h"

GameView::GameView(GameLogic* gameLogic) : m_gameLogic(gameLogic), m_offsetI(0), m_offsetJ(0)
{}

void GameView::processInputs()
{
    if (::GetAsyncKeyState('Z') != 0) m_offsetJ += 1;
    if (::GetAsyncKeyState('S') != 0) m_offsetJ -= 1;
    if (::GetAsyncKeyState('Q') != 0) m_offsetI += 1;
    if (::GetAsyncKeyState('D') != 0) m_offsetI -= 1;
    if (::GetAsyncKeyState(VK_ESCAPE) != 0) m_offsetI += 1;
}

void GameView::display(FrameBuffer* frameBusffer)
{
    frameBuffer->start();

    Cellboard* cb = m_gameLogic->getCellboard();

    for (int j = 0; j < frameBuffer->getSizeJ(); ++j)
    {
        for (int i = 0; i < frameBuffer->getSizeI(); ++i)
        {
            int coordI = i - m_offsetI;
            int coordJ = j - m_offsetJ;

            bool isValid = ((coordI >= 0) && (coordI < cb->getSizeI()))
                        && ((coordJ >= 0) && (coordJ < cb->getSizeJ()));

            if (isValid)
                frameBuffer->putChar(i, j, cb->isAlive(coordI, coordJ) ? 'O' : '.', Black, BrightWhite);
            else
                frameBuffer->putChar(i, j, '~', Black, BrightWhite);
        }
    }

    frameBuffer->stop();
}
