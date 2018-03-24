#pragma once

#include "Instruction.h"
#include "Type.h"
#include "Expression.h"
#include <string>

class Initialisation : public Instruction {

public:

    void print(std::ostream& stream) const;

    friend std::ostream& operator<< (std::ostream& stream, const Initialisation& initialisation);

    Initialisation &operator=(const Initialisation &unInitialisation);

    Initialisation(const Initialisation &unInitialisation);

    Initialisation(Type type, Expression* expression, std::string name);

    virtual ~Initialisation();

private:
    Type type;
    Expression* expression;
    std::string name;

};
