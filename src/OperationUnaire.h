#pragma once

#include "Expression.h"
#include "Type.h"

class OperationUnaire : public Expression{

public:

    void generateIR(ControlFlowGraph * controlFlowGraph){};

    friend std::ostream& operator<< (std::ostream& stream, const OperationUnaire& operationUnaire);

    void print(std::ostream& stream) const;

    OperationUnaire &operator=(const OperationUnaire &unOperationUnaire);

    void resolveScopeVariables(std::list<Declaration*> declProgramme, std::list<Declaration*> paramFunction, std::list<Declaration*> declBloc, std::list<Function*> functionProgram);

    void resolveTypeExpr();

    OperationUnaire(const OperationUnaire &unOperationUnaire);

    OperationUnaire(Operateur operateur, Expression* expression);

    virtual ~OperationUnaire();

private:
    Operateur operateur;
    Expression* expression;
};
