#pragma once

#include "Variable.h"

class VariableOpe : public Variable
{
    public:
        void print(std::ostream& stream) const;

        std::string generateIR(ControlFlowGraph * controlFlowGraph);

        friend std::ostream& operator<< (std::ostream& stream, const VariableOpe& variableOpe);

        VariableOpe &operator=(const VariableOpe &unVariableOpe);

        void resolveScopeVariables(std::vector<Declaration*> declProgramme, std::vector<Declaration*> paramFunction, std::vector<Declaration*> declBloc, std::vector<Function*> functionProgram);

        void resolveTypeExpr();

        VariableOpe(TypeVariable typeVariable, std::string valeur, PrePos ope);

        virtual ~VariableOpe();

    private:
        PrePos ope;
};
