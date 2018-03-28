#pragma once

#include <ostream>
#include "Type.h"
#include "Expression.h"

class Variable : public Expression {
public:
    void print(std::ostream& stream) const;

    friend std::ostream& operator<< (std::ostream& stream, const Variable& variable);

    TypeVariable getType(){
        return typeVariable;
    }

    std::string getValeur(){
        return valeur;
    }

    Variable &operator=(const Variable &unVariable);

    Variable(const Variable &unVariable);

    Variable(TypeVariable typeVariable, std::string valeur);

    virtual ~Variable();

protected:
    TypeVariable typeVariable;
    std::string valeur;
};
