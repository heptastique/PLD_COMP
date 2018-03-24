#pragma once

#include "Instruction.h"
#include "Bloc.h"
#include "Else.h"
#include "Expression.h"

class If : public Instruction {

public:

    void print(std::ostream& stream) const;

    friend std::ostream& operator<< (std::ostream& stream, const If& anIf);

    void setElse(Else* anElse);

    If &operator=(const If &unIf);

    If(const If &unIf);

    If(Expression* condition, Bloc* bloc);

    virtual ~If();

private:
    Expression* condition;
    Bloc* bloc;
    Else* anElse;
    bool hasElse = false;

};
