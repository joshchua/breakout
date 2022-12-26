#include "Game.h"

#include <chrono>
#include <memory>

#include <SDL2/SDL.h>

#include "Exception.h"
#include "Level.h"
#include "LevelLoader.h"
#include "Renderer.h"
#include "Scene.h"

using namespace std::literals::chrono_literals;

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
        constexpr auto timestep = std::chrono::nanoseconds{16ms};

        auto level_loader = LevelLoader{};
        auto levels = level_loader.load("");

        auto renderer = std::make_shared<Renderer>(renderer_);
        auto scene = Scene{renderer, levels};

        auto previous_time = std::chrono::steady_clock::now();
        auto lag = std::chrono::nanoseconds{0ns};
        while (is_running_) {
            auto current_time = std::chrono::steady_clock::now();
            auto delta_time = current_time - previous_time;
            previous_time = current_time;
            lag += delta_time;

            poll_events();

            while (lag > timestep) {
                scene.update(lag);
                lag -= timestep;
            }

            scene.render(lag);
            SDL_RenderPresent(renderer_);
        }
    }

    auto Game::poll_events() -> void {
        auto event = SDL_Event{};
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                is_running_ = false;
            }
        }
    }

} // namespace Breakout