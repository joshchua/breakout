#include "Game.h"

#include <SDL2/SDL.h>

#include "Exception.h"

namespace Breakout {
    Game::Game() {
        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
            throw Exception("Failed to initialize SDL2.");
        }

        window_ = SDL_CreateWindow("Breakout", SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED, 300, 500, 0);
        if (window_ == nullptr) {
            throw Exception("Failed to create window");
        }

        renderer_ = SDL_CreateRenderer(window_, -1, 0);
        if (renderer_ == nullptr) {
            throw Exception("Failed to create renderer");
        }

        is_running_ = false;
    }

    Game::~Game() {
        SDL_DestroyRenderer(renderer_);
        SDL_DestroyWindow(window_);
    }

    auto Game::run() -> void {
        is_running_ = true;
        while (is_running_) {
            poll_events();
        }
    }

    auto Game::window() const noexcept -> SDL_Window * {
        return window_;
    }

    auto Game::renderer() const noexcept -> SDL_Renderer * {
        return renderer_;
    }

    auto Game::poll_events() -> void {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                is_running_ = false;
            }
        }
    }

} // namespace Breakout