#pragma once

#include <ostream>
#include "Instruction.h"
#include "Variable.h"

class RetourFonction : public Instruction
{
    public:
        std::string generateIR(ControlFlowGraph * controlFlowGraph);

        friend std::ostream& operator<< (std::ostream& stream, const RetourFonction& retourFonction);

        void print(std::ostream& stream) const;

        RetourFonction &operator=(const RetourFonction &unRetourFonction);

        void resolveScopeVariables(std::vector<Declaration*> declProgramme, std::vector<Declaration*> paramFunction, std::vector<Declaration*> declBloc, std::vector<Function*> functionProgram);

        void resolveTypeExpr();

        virtual void resolvedUnUsedFonctAndDecl(std::vector<std::string>* remainingFunctions, std::vector<std::string>* remainingDeclPrograme, std::vector<std::string>* remainingParam, std::vector<std::string>* remainingDeclBloc);

        RetourFonction(const RetourFonction &unRetourFonction);

        RetourFonction(Expression* expression);

        virtual ~RetourFonction();

    private:
        Expression* expression;
};
