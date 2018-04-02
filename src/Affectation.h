#pragma once

#include "Instruction.h"
#include "Variable.h"
#include "Expression.h"

class Affectation : public Instruction
{
    public:

        void print(std::ostream& stream) const;

	std::string generateIR(ControlFlowGraph * controlFlowGraph);

        friend std::ostream& operator<< (std::ostream& stream, const Affectation& affectation);

        Affectation &operator=(const Affectation &unAffectation);

        void resolveScopeVariables(std::vector<Declaration*> declProgramme, std::vector<Declaration*> paramFunction, std::vector<Declaration*> declBloc, std::vector<Function*> functionProgram);

        void resolveTypeExpr();

        Affectation(const Affectation &unAffectation);

        Affectation(Variable* variable, Operateur operateur, Expression* expression);

        virtual ~Affectation();

    private:

        Variable* variable;

        Operateur operateur;

        Expression* expression;
};
