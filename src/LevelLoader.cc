#include "LevelLoader.h"

#include <string>
#include <vector>

#include "Level.h"

namespace Breakout {

LevelLoader::LevelLoader() {

}

LevelLoader::~LevelLoader() {

}

auto LevelLoader::load(const std::string &path) const -> std::vector<Level> {
    return std::vector<Level>{};
}

} // namespace Breakout