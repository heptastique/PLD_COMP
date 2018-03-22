#pragma once

class Expression {

public:

    Expression &operator=(const Expression &unExpression);

    Expression(const Expression &unExpression);

    Expression();

    virtual ~Expression();

};
