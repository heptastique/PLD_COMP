#pragma once

#include <string>
#include "Bloc.h"

class Function {


public:

    friend std::ostream& operator<< (std::ostream& stream, const Function& function);

    Function &operator=(const Function &unFunction);

    std::string getName();

    Bloc* getBloc();

    Function(const Function &unFunction);

    Function(std::string name, Bloc *Bloc);

    virtual ~Function();

private:
    std::string name;
    Bloc* bloc;
};