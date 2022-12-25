#include "Ball.h"

#include "Color.h"
#include "Renderer.h"
#include "Vector2D.h"

namespace Breakout {

Ball::Ball(float radius) {
    this->radius = radius;
    this->position = Vector2D{};
    this->velocity = Vector2D{};
}

auto Ball::draw(const Renderer *renderer) -> void {
    renderer->draw_rect(position.x, position.y, radius, radius, Color{255, 0, 0, 255});
}

} // namespace Breakout