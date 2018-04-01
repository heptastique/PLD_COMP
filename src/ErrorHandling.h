# pragma once

#include <string>

class ErrorHandling
{
    public:
        static void ThrowError(int code, int line, std::string name);
};
