#include "MainBaseAnimation.hpp"

MainBaseAnimation::MainBaseAnimation()
{
    const std::string pathToAsset = "assets/game/animation/character/base/";
    
    for(int i = 1; i <= 10; i++)
    {
        this->addFrame(pathToAsset + std::to_string(i) + ".png");
    }
}