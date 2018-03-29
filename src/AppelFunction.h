#pragma once

#include "Instruction.h"
#include "Variable.h"
#include "Function.h"
#include <list>

class AppelFunction : public Expression {
public:

    void generateIR(ControlFlowGraph * controlFlowGraph);

    friend std::ostream& operator<< (std::ostream& stream, const AppelFunction& appelFunction);

    void print(std::ostream& stream) const;

    AppelFunction &operator=(const AppelFunction &unAppelFunction);

    void resolveScopeVariables(std::list<Declaration*> declProgramme, std::list<Declaration*> paramFunction, std::list<Declaration*> declBloc, std::list<Function*> functionProgram);

    void resolveTypeExpr();

    list <Variable *> getVariables();

    AppelFunction(const AppelFunction &unAppelFunction);

    AppelFunction(std::string name, std::list<Variable *> variables);

    virtual ~AppelFunction();

private:
    std::string name;
    std::list<Variable *> variables;
    Function* functionAssociee;
};
