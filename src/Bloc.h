#pragma once

#include <string>
#include <list>
#include "Instruction.h"
#include "Declaration.h"

class Function;
class Bloc {

public:

    friend std::ostream& operator<< (std::ostream& stream, const Bloc& bloc);

    void addInstruction(Instruction * instruction);

    void addDeclaration(Declaration * declaration);

    std::list<Instruction*> getInstructions();

    std::list<Declaration*> getDeclarations();

    void resolveScopeVariables(std::list<Declaration*> declProgramme, std::list<Declaration*> paramFunction, std::list<Function*> functionProgram);

    void resolveScopeVariables(std::list<Declaration*> declProgramme, std::list<Declaration*> paramFunction, std::list<Declaration*> declBloc, std::list<Function*> functionProgram);

    Bloc &operator=(const Bloc &unBloc);

    Bloc(const Bloc &unBloc);

    Bloc();

    virtual ~Bloc();

private:
    std::list<Instruction*> instructions;
    std::list<Declaration*> declarations;
};
