#pragma once

#include "Instruction.h"
#include "Variable.h"
#include "Function.h"
#include <vector>

class AppelFunction : public Expression
{
    public:
        std::string generateIR(ControlFlowGraph * controlFlowGraph);

        friend std::ostream& operator<< (std::ostream& stream, const AppelFunction& appelFunction);

        void print(std::ostream& stream) const;

        AppelFunction &operator=(const AppelFunction &unAppelFunction);

        void resolveScopeVariables(std::vector<Declaration*> declProgramme, std::vector<Declaration*> paramFunction, std::vector<Declaration*> declBloc, std::vector<Function*> functionProgram);

        void resolveTypeExpr();

        virtual void resolvedUnUsedFonctAndDecl(std::vector<std::string>* remainingFunctions, std::vector<std::string>* remainingDeclPrograme, std::vector<std::string>* remainingParam, std::vector<std::string>* remainingDeclBloc);

        vector <Expression *> getExpressions();

        AppelFunction(const AppelFunction &unAppelFunction);

        AppelFunction(std::string name, std::vector<Expression *> expressions);

        virtual ~AppelFunction();

    private:
        std::string name;
        std::vector<Expression *> expressions;
        Function * functionAssociee = nullptr;
};
