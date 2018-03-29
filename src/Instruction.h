#pragma once

#include "ostream"
# include "ControlFlowGraph.h"
#include <list>

class Declaration;
class Function;

class Instruction {

protected:

	virtual void print(std::ostream& stream) const = 0;

public:

    virtual void generateIR(ControlFlowGraph * controlFlowGraph) = 0;

    friend std::ostream& operator<< (std::ostream& stream, Instruction const& instruction);

    virtual void resolveScopeVariables(std::list<Declaration*> declProgramme, std::list<Declaration*> paramFunction, std::list<Declaration*> declBloc, std::list<Function*> functionProgram) = 0;

    virtual void resolveTypeExpr() = 0;

    Instruction &operator=(const Instruction &unInstruction);

    Instruction(const Instruction &unInstruction);

    Instruction();

    virtual ~Instruction();

};
