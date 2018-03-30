#pragma once

#include "Expression.h"
#include "Type.h"

class OperationBinaire : public Expression {

public:

    void generateIR(ControlFlowGraph * controlFlowGraph){};

    friend std::ostream& operator<< (std::ostream& stream, const OperationBinaire& operationBinaire);

    void print(std::ostream& stream) const;

    OperationBinaire &operator=(const OperationBinaire &unOperationBinaire);

    void resolveScopeVariables(std::list<Declaration*> declProgramme, std::list<Declaration*> paramFunction, std::list<Declaration*> declBloc, std::list<Function*> functionProgram);

    void resolveTypeExpr();

    OperationBinaire(const OperationBinaire &unOperationBinaire);

    OperationBinaire(Expression* expressionL, Expression* expressionR, Operateur operateur);

    virtual ~OperationBinaire();

private:
    Expression* expressionL;
    Expression* expressionR;
    Operateur operateur;
};
