#include "Paddle.h"

#include "Color.h"

namespace Breakout {

Paddle::Paddle() {
    width = 100;
    height = 20;
}

auto Paddle::draw(const Renderer &renderer) const noexcept -> void {
    renderer.draw_rect(position.x, position.y, width, height, Color{0, 255, 0, 255});
}

} // namespace Breakout