#ifndef _BREAKOUT_LEVEL_H
#define _BREAKOUT_LEVEL_H

#include <string>
#include <vector>

#include "Brick.h"

namespace Breakout {

class Level {
public:
    std::string name;
    std::vector<Brick> bricks;
};

} // namespace Breakout

#endif // _BREAKOUT_LEVEL_H