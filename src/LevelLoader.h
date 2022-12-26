#ifndef _BREAKOUT_LEVELLOADER_H
#define _BREAKOUT_LEVELLOADER_H

#include <string>
#include <vector>

#include "Level.h"

namespace Breakout {

class LevelLoader {
public:
    LevelLoader();
    ~LevelLoader();
    auto load(const std::string &path) const -> std::vector<Level>;
};

} // Breakout

#endif // _BREAKOUT_LEVELLOADER_H