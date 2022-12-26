#ifndef _BREAKOUT_BALL_H
#define _BREAKOUT_BALL_H

#include "Renderer.h"
#include "Vector2D.h"

namespace Breakout {

class Ball {
public:
    Ball(float radius);
    float radius;
    Vector2D position;
    Vector2D velocity;
    auto draw(const Renderer &renderer) const noexcept -> void;
};

} // namespace Breakout

#endif // _BREAKOUT_BALL_H