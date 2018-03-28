#pragma once

#include <string>
#include <list>
#include "Instruction.h"
#include "Declaration.h"
# include "ControlFlowGraph.h"

class Instruction;
class ControlFlowGraph;

class Bloc {

public:

	void generateIR(ControlFlowGraph * controlFlowGraph);

    friend std::ostream& operator<< (std::ostream& stream, const Bloc& bloc);

    void addInstruction(Instruction * instruction);

    void addDeclaration(Declaration * declaration);

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
