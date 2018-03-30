#pragma once

#include <ostream>
#include "Instruction.h"
#include "Variable.h"

class RetourFonction : public Instruction{
public:

    void generateIR(ControlFlowGraph * controlFlowGraph){};

    friend std::ostream& operator<< (std::ostream& stream, const RetourFonction& retourFonction);

    void print(std::ostream& stream) const;

    RetourFonction &operator=(const RetourFonction &unRetourFonction);

    void resolveScopeVariables(std::list<Declaration*> declProgramme, std::list<Declaration*> paramFunction, std::list<Declaration*> declBloc, std::list<Function*> functionProgram);

    void resolveTypeExpr();

    RetourFonction(const RetourFonction &unRetourFonction);

    RetourFonction(Expression* expression);

    virtual ~RetourFonction();

private:
    Expression* expression;
};
