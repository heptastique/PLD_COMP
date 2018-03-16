#pragma once

#include <string>
#include <list>
#include "Instruction.h"

class Bloc {

public:

    friend std::ostream& operator<< (std::ostream& stream, const Bloc& bloc);

    void addInstruction(Instruction * instruction);

    Bloc &operator=(const Bloc &unBloc);

    Bloc(const Bloc &unBloc);

    Bloc();

    virtual ~Bloc();

private:
    std::list<Instruction*> instructions;

};
