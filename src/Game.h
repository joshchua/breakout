#ifndef _BREAKOUT_GAME_H
#define _BREAKOUT_GAME_H

#include <chrono>

#include <SDL2/SDL.h>

namespace Breakout {
    class Game {
    public:
        Game();
        ~Game();
        auto run() -> void;
    private:
        auto poll_events() -> void;
        bool is_running_;
        SDL_Window *window_;
        SDL_Renderer *renderer_;
    };
}

#endif // _BREAKOUT_GAME_H