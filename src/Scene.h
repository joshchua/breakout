#ifndef _BREAKOUT_SCENE_H
#define _BREAKOUT_SCENE_H

#include <chrono>
#include <memory>

#include "Ball.h"
#include "Renderer.h"

namespace Breakout {

class Scene {
public:
    Scene(std::shared_ptr<Renderer> renderer);
    ~Scene();
    auto update(const std::chrono::nanoseconds &delta_time) -> void;
    auto render(const std::chrono::nanoseconds &delta_time) -> void;
private:
    std::shared_ptr<Renderer> renderer_;
    std::unique_ptr<Ball> ball_;
};

} // namespace Breakout

#endif // _BREAKOUT_SCENE_H