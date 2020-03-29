#include "Debug.hpp"

void Debug::consoleMessage(std::string message)
{
    if(DEBUG)
    {
        std::cout << message << std::endl;
    }
}
