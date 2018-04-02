#pragma once

#include "Variable.h"

class VariableIndex : public Variable
{
    public:

        void print(std::ostream& stream) const;

        std::string generateIR(ControlFlowGraph * controlFlowGraph);

        friend std::ostream& operator<< (std::ostream& stream, const VariableIndex& variableIndex);

        void resolveScopeVariables(std::vector<Declaration*> declProgramme, std::vector<Declaration*> paramFunction, std::vector<Declaration*> declBloc, std::vector<Function*> functionProgram);

        void resolveTypeExpr();

        VariableIndex &operator=(const VariableIndex &unVariableIndex);

        VariableIndex(TypeVariable typeVariable, std::string valeur, Expression* index);

        virtual ~VariableIndex();

    private:

        Expression* index;
};
