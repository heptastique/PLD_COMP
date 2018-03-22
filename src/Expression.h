#pragma once

#include <iostream>

class Expression {
protected:
    virtual void print(std::ostream& stream) const = 0;
public:

    friend std::ostream& operator<< (std::ostream& stream, Expression const& expression);

    Expression &operator=(const Expression &unExpression);

    Expression(const Expression &unExpression);

    Expression();

    virtual ~Expression();

};
