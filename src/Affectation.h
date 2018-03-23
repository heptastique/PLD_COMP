#pragma once

#include "Variable.h"
#include "Instruction.h"
#include "Expression.h"

class Affectation : public Instruction{

public:

    void print(std::ostream& stream) const;

    friend std::ostream& operator<< (std::ostream& stream, const Affectation& affectation);

    Affectation &operator=(const Affectation &unAffectation);

    Affectation(const Affectation &unAffectation);

    Affectation(Variable* variable, Operateur operateur, Expression* expression);

    virtual ~Affectation();

private:
    Variable* variable;
    Operateur operateur;
    Expression* expression;
};