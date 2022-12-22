#ifndef _BREAKOUT_GAME_H

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
        SDL_Window *window_;
        SDL_Renderer *renderer_;
        bool is_running_;
    };
}

#endif // _BREAKOUT_GAME_H