#pragma once

#include <ostream>
#include "Instruction.h"
#include "Variable.h"

class RetourFonction : public Instruction{
    public:
        void generateIR(ControlFlowGraph * controlFlowGraph){};

        friend std::ostream& operator<< (std::ostream& stream, const RetourFonction& retourFonction);

        void print(std::ostream& stream) const;

        RetourFonction &operator=(const RetourFonction &unRetourFonction);

        void resolveScopeVariables(std::vector<Declaration*> declProgramme, std::vector<Declaration*> paramFunction, std::vector<Declaration*> declBloc, std::vector<Function*> functionProgram);

        void resolveTypeExpr();

        RetourFonction(const RetourFonction &unRetourFonction);

        RetourFonction(Expression* expression);

        virtual ~RetourFonction();

    private:
        Expression* expression;
};
