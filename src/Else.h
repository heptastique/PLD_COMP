#pragma once

#include "Instruction.h"
#include "Bloc.h"
#include "ControlFlowGraph.h"
#include "IRInstr.h"

class Else
{
    public:
        std::string generateIR(ControlFlowGraph * controlFlowGraph, int label);

        void print(std::ostream& stream) const;

        friend std::ostream& operator<< (std::ostream& stream, const Else& anElse);

        Else &operator=(const Else &unElse);

        void resolveScopeVariables(std::vector<Declaration*> declProgramme, std::vector<Declaration*> paramFunction, std::vector<Declaration*> declBloc, std::vector<Function*> functionProgram);

        void resolveTypeExpr();
  
        Else(const Else &unElse);

        Else(Bloc* bloc);

        virtual ~Else();

    private:
        Bloc* bloc;
};
