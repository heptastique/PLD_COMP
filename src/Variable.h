#pragma once

#include <ostream>
#include "Type.h"
#include "Expression.h"

class Variable : public Expression {
public:
    void print(std::ostream& stream) const;

    friend std::ostream& operator<< (std::ostream& stream, const Variable& variable);

    Variable &operator=(const Variable &unVariable);

    Variable(const Variable &unVariable);

    Variable(TypeVariable typeVariable, std::string valeur);

    virtual ~Variable();

private:
    TypeVariable typeVariable;
    std::string valeur;
};
