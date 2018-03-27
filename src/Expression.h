#pragma once

#include <iostream>
#include "Instruction.h"

class Expression : public Instruction {
protected:
    virtual void print(std::ostream& stream) const = 0;
public:

    friend std::ostream& operator<< (std::ostream& stream, Expression const& expression);

    Expression &operator=(const Expression &unExpression);

    void resolveScopeVariables(std::list<Declaration*> declProgramme, std::list<Declaration*> paramFunction, std::list<Declaration*> declBloc);

    Expression(const Expression &unExpression);

    Expression();

    virtual ~Expression();

};
