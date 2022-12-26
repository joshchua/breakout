#include "Scene.h"

#include <chrono>
#include <memory>
#include <utility>
#include <vector>

#include "Renderer.h"
#include "Level.h"

namespace Breakout {

Scene::Scene(std::shared_ptr<Renderer> renderer, std::vector<Level> &levels) 
 : renderer_{renderer}
 , levels_{std::move(levels)}
 , ball_{10}
 , paddle_{} {
}

Scene::~Scene() {

}

auto Scene::update(const std::chrono::nanoseconds &delta_time) -> void {
    ball_.velocity.y += 0.00001;
    ball_.position.y += ball_.velocity.y * (delta_time.count() / 1000000);
}

auto Scene::render(const std::chrono::nanoseconds &delta_time) -> void {
    renderer_->clear();

    ball_.draw(*renderer_);
    paddle_.draw(*renderer_);

    for (const auto &brick : bricks_) {
        brick.draw(*renderer_);
    }
}

} // namespace Breakout