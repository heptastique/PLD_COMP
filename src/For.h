#pragma once

#include "Instruction.h"
#include "Bloc.h"
#include "Expression.h"

class For : public Instruction {

public:

    void generateIR(ControlFlowGraph * controlFlowGraph){};

    void print(std::ostream& stream) const;

    friend std::ostream& operator<< (std::ostream& stream, const For& aFor);

    For &operator=(const For &unFor);

    void resolveScopeVariables(std::vector<Declaration*> declProgramme, std::vector<Declaration*> paramFunction, std::vector<Declaration*> declBloc, std::vector<Function*> functionProgram);

    void resolveTypeExpr();

    For(const For &unFor);

    For(Bloc* bloc, Expression* condition);

    virtual ~For();

private:
    Instruction * PartOne; // declaration or initialisation or affectation or expression or nothing
    Expression* condition;
    Instruction * PartThree; // affectation or expression or nothing
    Bloc* bloc;



};
