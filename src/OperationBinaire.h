#pragma once

#include "Expression.h"
#include "Type.h"

class OperationBinaire : public Expression
{
    public:
        friend std::ostream& operator<< (std::ostream& stream, const OperationBinaire& operationBinaire);

        std::string generateIR(ControlFlowGraph * controlFlowGraph);

        void print(std::ostream& stream) const;

        OperationBinaire &operator=(const OperationBinaire &unOperationBinaire);

        void resolveScopeVariables(std::vector<Declaration*> declProgramme, std::vector<Declaration*> paramFunction, std::vector<Declaration*> declBloc, std::vector<Function*> functionProgram);

        void resolveTypeExpr();

        OperationBinaire(const OperationBinaire &unOperationBinaire);

        OperationBinaire(Expression* expressionL, Expression* expressionR, Operateur operateur);

        virtual ~OperationBinaire();

    private:
        Expression* expressionL;

        Expression* expressionR;

        Operateur operateur;
};
