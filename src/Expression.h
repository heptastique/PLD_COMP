#pragma once

#include <iostream>
#include "Instruction.h"
// # include "ControlFlowGraph.h"
#include "Type.h"

class Expression : public Instruction {

protected:

	//virtual void generateIR(ControlFlowGraph * controlFlowGraph) = 0;

	virtual void print(std::ostream& stream) const = 0;

public:

    friend std::ostream& operator<< (std::ostream& stream, Expression const& expression);

    Expression &operator=(const Expression &unExpression);

    void resolveScopeVariables(std::list<Declaration*> declProgramme, std::list<Declaration*> paramFunction, std::list<Declaration*> declBloc, std::list<Function*> functionProgram);

    Type getType();

    void setType(Type type);

    virtual void resolveTypeExpr() = 0;

    Expression(const Expression &unExpression);

    Expression();

    virtual ~Expression();

private:
    Type type;

};
