#pragma once

#include <iostream>
#include "Instruction.h"
//#include "ControlFlowGraph.h"
#include "Type.h"

class ControlFlowGraph;

class Expression : public Instruction
{
    protected:


        virtual void print(std::ostream& stream) const = 0;

    public:
        virtual std::string generateIR(ControlFlowGraph * controlFlowGraph) = 0;

        friend std::ostream& operator<< (std::ostream& stream, Expression const& expression);

        Expression &operator=(const Expression &unExpression);

        virtual void resolveScopeVariables(std::vector<Declaration*> declProgramme, std::vector<Declaration*> paramFunction, std::vector<Declaration*> declBloc, std::vector<Function*> functionProgram);

        Type getType();

        void setType(Type type);

        virtual void resolveTypeExpr() = 0;

        Expression(const Expression &unExpression);

        Expression();

        virtual ~Expression();

    private:
        Type type;
};
