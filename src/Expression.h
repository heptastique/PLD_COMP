#pragma once

#include <iostream>
#include "Instruction.h"
# include "ControlFlowGraph.h"

class Expression : public Instruction {
protected:

	virtual void generateIR(ControlFlowGraph * controlFlowGraph) = 0;

	virtual void print(std::ostream& stream) const = 0;

public:

    friend std::ostream& operator<< (std::ostream& stream, Expression const& expression);

    Expression &operator=(const Expression &unExpression);

    Expression(const Expression &unExpression);

    Expression();

    virtual ~Expression();

};
