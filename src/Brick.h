#ifndef _BREAKOUT_BRICK_H
#define _BREAKOUT_BRICK_H

#include "Vector2D.h"
#include "Renderer.h"

namespace Breakout {
class Brick {
public:
    Brick();
    auto draw(const Renderer &renderer) const noexcept -> void;
    Vector2D position;
    float width;
    float height;
    int hitpoints;
};
} // namespace Breakout

#endif // _BREAKOUT_BRICK_H