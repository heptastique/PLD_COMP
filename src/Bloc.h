#pragma once

#include <string>
#include <list>
#include "Instruction.h"

class Bloc {

public:

    void addInstruction(Instruction * instruction);

    Bloc &operator=(const Bloc &unBloc);

    Bloc(const Bloc &unBloc);

    Bloc();

    virtual ~Bloc();

private:
    std::list<Instruction*> instructions;

};
