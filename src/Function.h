#pragma once

#include <string>
#include "Bloc.h"

class Function {


public:

    Function &operator=(const Function &unFunction);

    Function(const Function &unFunction);

    Function(std::string &name, Bloc &Bloc);

    virtual ~Function();

private:
    std::string name;
    Bloc bloc;
};