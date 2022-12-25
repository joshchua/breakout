#include "Scene.h"

#include <chrono>
#include <memory>

#include "Ball.h"
#include "Renderer.h"

namespace Breakout {

Scene::Scene(std::shared_ptr<Renderer> renderer) {
    renderer_ = renderer;
    ball_ = std::make_unique<Ball>(10);
}

Scene::~Scene() {

}

auto Scene::update(const std::chrono::nanoseconds &delta_time) -> void {
}

auto Scene::render(const std::chrono::nanoseconds &delta_time) -> void {
    renderer_->clear();
    ball_->draw(renderer_.get());
}

} // namespace Breakout