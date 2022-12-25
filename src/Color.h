#ifndef _BREAKOUT_COLOR_H
#define _BREAKOUT_COLOR_H

#include <cinttypes>

namespace Breakout {

class Color {
public:
    Color(std::uint8_t red, std::uint8_t green, std::uint8_t blue, std::uint8_t alpha);
    std::uint8_t red;
    std::uint8_t green;
    std::uint8_t blue;
    std::uint8_t alpha;
    static auto cornflower_blue() noexcept -> Color;
};

} // namespace Breakout

#endif // _BREAKOUT_COLOR_H