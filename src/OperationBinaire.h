#pragma once

#include "Expression.h"
#include "Type.h"

class OperationBinaire : public Expression {

public:
    friend std::ostream& operator<< (std::ostream& stream, const OperationBinaire& operationBinaire);

    void print(std::ostream& stream) const;

    OperationBinaire &operator=(const OperationBinaire &unOperationBinaire);

    OperationBinaire(const OperationBinaire &unOperationBinaire);

    OperationBinaire(Expression* expressionL, Expression* expressionR, Operateur operateur);

    virtual ~OperationBinaire();

private:
    Expression* expressionL;
    Expression* expressionR;
    Operateur operateur;
};
