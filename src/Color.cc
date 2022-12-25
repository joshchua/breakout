#include "Color.h"

#include <cinttypes>

namespace Breakout {

Color::Color(std::uint8_t red, std::uint8_t green, std::uint8_t blue, std::uint8_t alpha) {
    this->red = red;
    this->green = green;
    this->blue = blue;
    this->alpha = alpha;
}

auto Color::cornflower_blue() noexcept -> Color {
    return Color{100, 149, 237, 255};
}

} // namespace Breakout