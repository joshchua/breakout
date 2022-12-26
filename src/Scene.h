#ifndef _BREAKOUT_SCENE_H
#define _BREAKOUT_SCENE_H

#include <chrono>
#include <memory>
#include <vector>

#include "Ball.h"
#include "Brick.h"
#include "Level.h"
#include "Paddle.h"
#include "Renderer.h"

namespace Breakout {

class Scene {
public:
    Scene(std::shared_ptr<Renderer> renderer, std::vector<Level> &levels);
    ~Scene();
    auto update(const std::chrono::nanoseconds &delta_time) -> void;
    auto render(const std::chrono::nanoseconds &delta_time) -> void;
private:
    std::vector<Level>::size_type current_level_;
    std::vector<Level> levels_;
    std::shared_ptr<Renderer> renderer_;
    Ball ball_;
    Paddle paddle_;
    std::vector<Brick> bricks_;
};

} // namespace Breakout

#endif // _BREAKOUT_SCENE_H