#pragma once

#include <string>
#include <vector>
#include "Instruction.h"
#include "Declaration.h"

class ControlFlowGraph;
class Function;

class Bloc {
    public:
        void generateIR(ControlFlowGraph * controlFlowGraph);

        friend std::ostream& operator<< (std::ostream& stream, const Bloc& bloc);

        void addInstructions(std::vector<Instruction*> instructions);

        void addDeclarations(std::vector<Declaration*> declarations);

        std::vector<Instruction*> getInstructions();

        std::vector<Declaration*> getDeclarations();

        void resolveScopeVariables(std::vector<Declaration*> declProgramme, std::vector<Declaration*> paramFunction, std::vector<Function*> functionProgram);

        void resolveScopeVariables(std::vector<Declaration*> declProgramme, std::vector<Declaration*> paramFunction, std::vector<Declaration*> declBloc, std::vector<Function*> functionProgram);

        void resolveTypeExpr();

        Bloc &operator=(const Bloc &unBloc);

        Bloc(const Bloc &unBloc);

        Bloc();

        virtual ~Bloc();

    private:
        std::vector<Instruction*> instructions;
        std::vector<Declaration*> declarations;
};
