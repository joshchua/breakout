#include "Exception.h"

namespace Breakout {
    Exception::Exception(std::string message) {
        message_ = message;
    }

    auto Exception::what() -> const char * {
        return message_.c_str();
    }
}