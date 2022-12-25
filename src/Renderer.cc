#include "Renderer.h"

#include <SDL2/SDL.h>

#include "Color.h"

namespace Breakout {

Renderer::Renderer(SDL_Renderer *renderer) {
    renderer_ = renderer;
}

Renderer::~Renderer() {

}

auto Renderer::draw_rect(float x, float y, float w, float h, const Color &color) const noexcept -> void {
    set_render_color(color);
    auto rect = SDL_FRect{x, y, w, h};
    SDL_RenderFillRectF(renderer_, &rect);
}

auto Renderer::clear() const noexcept -> void {
    set_render_color(Color::cornflower_blue());
    SDL_RenderClear(renderer_);
}

inline auto Renderer::set_render_color(const Color &color) const noexcept -> void {
    SDL_SetRenderDrawColor(renderer_, color.red, color.green, color.blue, color.alpha);
}

} // namespace Breakout