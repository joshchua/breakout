#ifndef _BREAKOUT_EXCEPTION_H
#define _BREAKOUT_EXCEPTION_H

#include <exception>
#include <string>

namespace Breakout {
    class Exception : public std::exception {
    public:
        Exception(std::string message);
        auto what() -> const char *;
    private:
        std::string message_;
    };
}

#endif // _BREAKOUT_EXCEPTION_H