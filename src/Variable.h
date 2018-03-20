#pragma once

#include <ostream>

class Variable {

public:

    friend std::ostream& operator<< (std::ostream& stream, const Variable& appelFunction);

    Variable &operator=(const Variable &unVariable);

    Variable(const Variable &unVariable);

    Variable();

    virtual ~Variable();

};
