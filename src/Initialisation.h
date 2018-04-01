#pragma once

#include "Declaration.h"
#include "Type.h"
#include "Expression.h"
#include <string>

class Initialisation : public Declaration {
    public:
        void generateIR(ControlFlowGraph * controlFlowGraph);

        void print(std::ostream& stream) const;

        friend std::ostream& operator<< (std::ostream& stream, const Initialisation& initialisation);

        Initialisation &operator=(const Initialisation &unInitialisation);

        void resolveScopeVariables(std::vector<Declaration*> declProgramme, std::vector<Declaration*> paramFunction, std::vector<Declaration*> declBloc, std::vector<Function*> functionProgram);

        void resolveTypeExpr();

        Initialisation(const Initialisation &unInitialisation);

        Initialisation(Type type, Expression* expression, std::string name);

        virtual ~Initialisation();

    protected:
        Expression* expression;
};
