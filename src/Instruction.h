#pragma once

#include "ostream"
#include <vector>

class Declaration;
class Function;
class ControlFlowGraph;

class Instruction
{
    protected:
        virtual void print(std::ostream& stream) const = 0;

    public:
        virtual std::string generateIR(ControlFlowGraph * controlFlowGraph) = 0;

        friend std::ostream& operator<< (std::ostream& stream, Instruction const& instruction);

        virtual void resolveScopeVariables(std::vector<Declaration*> declProgramme, std::vector<Declaration*> paramFunction, std::vector<Declaration*> declBloc, std::vector<Function*> functionProgram) = 0;

        virtual void resolveTypeExpr() = 0;

        virtual void resolvedUnUsedFonctAndDecl(std::vector<std::string>* remainingFunctions, std::vector<std::string>* remainingDeclPrograme, std::vector<std::string>* remainingParam, vector<string>* remainingDeclBloc);

        Instruction &operator=(const Instruction &unInstruction);

        Instruction(const Instruction &unInstruction);

        Instruction();

        virtual ~Instruction();
};
