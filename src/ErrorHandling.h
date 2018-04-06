#pragma once

#include <string>

class ErrorHandling
{
    public:
        static void ThrowError(int code, std::string name);
};
