#include <iostream>

#include "Exception.h"
#include "Game.h"

auto main() -> int {
    try {
        auto game = Breakout::Game{};
        game.run();
    } catch (Breakout::Exception ex) {
        std::cout << "Caught exception with message: " << ex.what() << '\n';
    }
    return 0;
}
