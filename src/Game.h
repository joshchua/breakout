#ifndef _BREAKOUT_GAME_H

#include <chrono>

#include <SDL2/SDL.h>

namespace Breakout {
    class Game {
    public:
        Game();
        ~Game();
        auto run() -> void;
        auto window() const noexcept -> SDL_Window *;
        auto renderer() const noexcept -> SDL_Renderer *;
    private:
        auto poll_events() -> void;
        auto update(const std::chrono::nanoseconds &delta_time) -> void;
        auto render(const std::chrono::nanoseconds &delta_time) -> void;
        bool is_running_;
    };
}

#endif // _BREAKOUT_GAME_H