#pragma once

#include "Instruction.h"
#include "Bloc.h"
#include "Expression.h"

class While : public Instruction {
    public:
        void generateIR(ControlFlowGraph * controlFlowGraph){};

        void print(std::ostream& stream) const;

        friend std::ostream& operator<< (std::ostream& stream, const While& aWhile);

        While &operator=(const While &unWhile);

        void resolveScopeVariables(std::vector<Declaration*> declProgramme, std::vector<Declaration*> paramFunction, std::vector<Declaration*> declBloc, std::vector<Function*> functionProgram);

        void resolveTypeExpr();

        While(const While &unWhile);

        While(Bloc* bloc, Expression* condition);

        virtual ~While();

    private:
        Bloc* bloc;
        Expression* condition;
};
