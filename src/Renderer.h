#ifndef _BREAKOUT_RENDERER_H
#define _BREAKOUT_RENDERER_H

#include <SDL2/SDL.h>

#include "Color.h"

namespace Breakout {

class Renderer {
public:
    Renderer(SDL_Renderer *renderer);
    ~Renderer();
    auto draw_rect(float x, float y, float w, float h, const Color &color) const noexcept -> void;
    auto draw_circle(float x, float y, float r, const Color &color) const noexcept -> void;
    auto clear() const noexcept -> void;

private:
    inline auto set_render_color(const Color &color) const noexcept -> void;
    SDL_Renderer *renderer_;
};

} // namespace Breakout

#endif // _BREAKOUT_RENDERER_H