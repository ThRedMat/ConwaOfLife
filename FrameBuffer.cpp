#include "FrameBuffer.h"

FrameBuffer::FrameBuffer() : m_sizeI(-1), m_sizeJ(-1), m_buffer(nullptr)
{
}

void FrameBuffer::start()
{
    HANDLE hOutputConsole = ::GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleScreenBufferInfo;
    ::GetConsoleScreenBufferInfo(hOutputConsole, &consoleScreenBufferInfo);

    m_sizeI = consoleScreenBufferInfo.dwMaximumWindowSize.X;
    m_sizeJ = consoleScreenBufferInfo.dwMaximumWindowSize.Y;

    m_buffer = new CHAR_INFO[m_sizeI * m_sizeJ];

    for (int k = 0; k < m_sizeI * m_sizeJ; ++k)
    {
        m_buffer[k].Char.AsciiChar = 0;
        m_buffer[k].Attributes = 0;
    }
}

short FrameBuffer::getSizeI() { return m_sizeI; }
short FrameBuffer::getSizeJ() { return m_sizeJ; }


void FrameBuffer::stop()
{
    COORD bufferSize{ m_sizeI, m_sizeJ };
    COORD bufferCoord{ 0, 0 };
    SMALL_RECT writeRegion{ 0, 0, m_sizeI, m_sizeJ };
    HANDLE hOutputConsole = ::GetStdHandle(STD_OUTPUT_HANDLE);

    WriteConsoleOutputA(hOutputConsole, m_buffer, bufferSize, bufferCoord, &writeRegion);

    delete[] m_buffer;
    m_buffer = nullptr;
}

void FrameBuffer::putChar(int i, int j, char car, Color foregroundColor, Color backgroundColor)
{
    CHAR_INFO* dest = &m_buffer[j * m_sizeI + i];
    dest->Char.AsciiChar = car;
    dest->Attributes = foregroundColor + (backgroundColor << 4);
}

void putString(int i, int j, std::string str, Color foregroundColor, Color backgroundColor)
{}
