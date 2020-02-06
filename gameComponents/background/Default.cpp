#include "Default.hpp"

Default::Default()
{
    std::vector<std::string> paths = {
        "assets/game/background.png"
    };

    for(const auto& path : paths) this->addLayer(path);
}