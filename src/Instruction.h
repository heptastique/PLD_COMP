#pragma once

#include "ostream"
//# include "ControlFlowGraph.h"
#include <list>

class Declaration;
class Function;
//class ControlFlowGraph;

class Instruction {

protected:

	//void generateIR(ControlFlowGraph * controlFlowGraph);

	virtual void print(std::ostream& stream) const = 0;

public:

    friend std::ostream& operator<< (std::ostream& stream, Instruction const& instruction);

    virtual void resolveScopeVariables(std::list<Declaration*> declProgramme, std::list<Declaration*> paramFunction, std::list<Declaration*> declBloc, std::list<Function*> functionProgram) = 0;

    virtual void resolveTypeExpr() = 0;

    Instruction &operator=(const Instruction &unInstruction);

    Instruction(const Instruction &unInstruction);

    Instruction();

    virtual ~Instruction();

};
