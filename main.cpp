#include <iostream>
#include <string>
#include <conio.h>

#include "GameLogic.h"
#include "GameView.h"
#include "FrameBuffer.h"

int main()
{
    int sizeI, sizeJ;
    std::cout << "Enter sizeI : ";
    std::cin >> sizeI;
    std::cout << "Enter sizeJ : ";
    std::cin >> sizeJ;

    GameLogic game(sizeI, sizeJ);
    game.getCellboard()->setAlive(10, 11, true);
    game.getCellboard()->setAlive(11, 11, true);
    game.getCellboard()->setAlive(12, 11, true);
    game.getCellboard()->setAlive(11, 10, true);
    game.getCellboard()->setAlive(11, 12, true);

    GameView gameView(&game);
    FrameBuffer frameBuffer;

    bool bContinue = true;
    while (bContinue)
    {
        gameView.display(&frameBuffer);
        //game.update();
        gameView.processInputs();
        Sleep(10);
    }
}

