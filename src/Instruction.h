#pragma once

#include "ostream"
# include "ControlFlowGraph.h"

//class ControlFlowGraph;

class Instruction {

protected:

	virtual void generateIR(ControlFlowGraph * controlFlowGraph) = 0;

	virtual void print(std::ostream& stream) const = 0;

public:

    friend std::ostream& operator<< (std::ostream& stream, Instruction const& instruction);

    Instruction &operator=(const Instruction &unInstruction);

    Instruction(const Instruction &unInstruction);

    Instruction();

    virtual ~Instruction();

};
