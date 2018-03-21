#pragma once

#include <ostream>
#include "Type.h"

class Variable {
public:
    friend std::ostream& operator<< (std::ostream& stream, const Variable& appelFunction);

    Variable &operator=(const Variable &unVariable);

    Variable(const Variable &unVariable);

    Variable(TypeVariable typeVariable, std::string valeur);

    virtual ~Variable();

private:
    TypeVariable typeVariable;
    std::string valeur;
};
