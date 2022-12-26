#ifndef _BREAKOUT_PADDLE_H
#define _BREAKOUT_PADDLE_H

#include "Renderer.h"
#include "Vector2D.h"

namespace Breakout {

class Paddle {
public:
    Paddle();
    auto draw(const Renderer &renderer) const noexcept -> void;
    Vector2D position;
    Vector2D velocity;
    float height;
    float width;
};

} // namespace Breakout

#endif // _BREAKOUT_PADDLE_H