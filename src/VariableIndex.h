#pragma once

#include "Variable.h"

class VariableIndex : public Variable{

public:

    void generateIR(ControlFlowGraph * controlFlowGraph);

    void print(std::ostream& stream) const;

    friend std::ostream& operator<< (std::ostream& stream, const VariableIndex& variableIndex);

    VariableIndex &operator=(const VariableIndex &unVariableIndex);

    VariableIndex(TypeVariable typeVariable, std::string valeur, Expression* index);

    virtual ~VariableIndex();

private:
    Expression* index;

};
