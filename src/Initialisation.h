#pragma once

#include "Instruction.h"
#include "Type.h"
#include "Expression.h"
#include <string>

class Initialisation : public Instruction {

public:

    void generateIR(ControlFlowGraph * controlFlowGraph);

    void print(std::ostream& stream) const;

    friend std::ostream& operator<< (std::ostream& stream, const Initialisation& initialisation);

    void setType(Type type){
        this->type = type;
    }

    Initialisation &operator=(const Initialisation &unInitialisation);

    void resolveScopeVariables(std::list<Declaration*> declProgramme, std::list<Declaration*> paramFunction, std::list<Declaration*> declBloc, std::list<Function*> functionProgram);

    void resolveTypeExpr();

    Initialisation(const Initialisation &unInitialisation);

    Initialisation(Type type, Expression* expression, std::string name);

    virtual ~Initialisation();

protected:
    Type type;
    Expression* expression;
    std::string name;

};
