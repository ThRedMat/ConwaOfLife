#pragma once

#include <string>

// TODO : virer ce header un jour !
#include <Windows.h>

enum Color
{
    Black = 0
  , Blue = 1
  , Green = 2
  , Cyan = 3
  , Red = 4
  , Magenta = 5
  , Yellow = 6
  , White = 7
  , Gray = 8
  , LightBlue = 9
  , LightGreen = 10
  , LightCyan = 11
  , LightRed = 12
  , LightMagenta = 13
  , LightYellow = 14
  , BrightWhite = 15
};

class FrameBuffer
{
public:
    FrameBuffer();

    void start();

    void stop();

    void putChar(int i, int j, char car, Color foregroundColor, Color backgroundColor);

    void putString(int i, int j, std::string str, Color foregroundColor, Color backgroundColor);

    short getSizeI();

    short getSizeJ();

private:
    short m_sizeI;
    short m_sizeJ;
    CHAR_INFO* m_buffer;
};
