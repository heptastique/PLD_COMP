#pragma once

#include "Bloc.h"

class Function {


public:

    Function &operator=(const Function &unFunction);

    Function(const Function &unFunction);

    Function(const std::string &name,const Bloc &Bloc);

    virtual ~Function();

private:
    std::string name;
    Bloc bloc;
};