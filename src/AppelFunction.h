#pragma once

#include "Instruction.h"
#include "Variable.h"
#include "Function.h"
#include <vector>

class AppelFunction : public Expression {
    public:
        void generateIR(ControlFlowGraph * controlFlowGraph);

        friend std::ostream& operator<< (std::ostream& stream, const AppelFunction& appelFunction);

        void print(std::ostream& stream) const;

        AppelFunction &operator=(const AppelFunction &unAppelFunction);

        void resolveScopeVariables(std::vector<Declaration*> declProgramme, std::vector<Declaration*> paramFunction, std::vector<Declaration*> declBloc, std::vector<Function*> functionProgram);

        void resolveTypeExpr();

        vector <Variable *> getVariables();

        AppelFunction(const AppelFunction &unAppelFunction);

        AppelFunction(std::string name, std::vector<Variable *> variables);

        virtual ~AppelFunction();

    private:
        std::string name;
        std::vector<Variable *> variables;
        Function* functionAssociee = nullptr;
};
