#pragma once

#include "Variable.h"

class VariableOpe : public Variable {

public:

    void print(std::ostream& stream) const;

    friend std::ostream& operator<< (std::ostream& stream, const VariableOpe& variableOpe);

    VariableOpe &operator=(const VariableOpe &unVariableOpe);

    VariableOpe(TypeVariable typeVariable, std::string valeur, PrePos ope);

    virtual ~VariableOpe();

private:
    PrePos ope;

};
