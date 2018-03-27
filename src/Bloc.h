#pragma once

#include <string>
#include <list>
#include "Instruction.h"
#include "Declaration.h"

class Bloc {

public:

    friend std::ostream& operator<< (std::ostream& stream, const Bloc& bloc);

    void addInstructions(std::list<Instruction*> instructions);

    void addDeclarations(std::list<Declaration*> declarations);

    std::list<Instruction*> getInstructions();

    std::list<Declaration*> getDeclarations();

    void resolveScopeVariables(std::list<Declaration*> declProgramme, std::list<Declaration*> paramFunction);

    Bloc &operator=(const Bloc &unBloc);

    Bloc(const Bloc &unBloc);

    Bloc();

    virtual ~Bloc();

private:
    std::list<Instruction*> instructions;
    std::list<Declaration*> declarations;
};
