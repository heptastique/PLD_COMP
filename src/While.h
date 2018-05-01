#pragma once

#include "Instruction.h"
#include "Bloc.h"
#include "Expression.h"

class While : public Instruction
{
    public:
        void print(std::ostream& stream) const;

        std::string generateIR(ControlFlowGraph * controlFlowGraph);

        friend std::ostream& operator<< (std::ostream& stream, const While& aWhile);

        While &operator=(const While &unWhile);

        void resolveScopeVariables(std::vector<Declaration*> declProgramme, std::vector<Declaration*> paramFunction, std::vector<Declaration*> declBloc, std::vector<Function*> functionProgram);

        virtual void resolvedUnUsedFonctAndDecl(std::vector<std::string>* remainingFunctions, std::vector<std::string>* remainingDeclPrograme, std::vector<std::string>* remainingParam, std::vector<std::string>* remainingDeclBloc);

        void resolveTypeExpr();

        While(const While &unWhile);

        While(Bloc* bloc, Expression* condition);

        virtual ~While();

    private:
        Bloc* bloc;

        Expression* condition;
};
