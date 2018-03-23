using namespace std;

#include "Expression.h"
#include <iostream>

std::ostream& operator<<(std::ostream& stream, const Expression& expression)
{
    stream << "Expression:";
    expression.print(stream);
    return stream;
}

Expression &Expression::operator=(const Expression &unExpression) {
}


Expression::Expression(const Expression &unExpression) {
#ifdef MAP
    cout << "Appel au constructeur de copie de <Expression>" << endl;
#endif
}


Expression::Expression() {
#ifdef MAP
    cout << "Appel au constructeur de <Expression>" << endl;
#endif
}


Expression::~Expression() {
#ifdef MAP
    cout << "Appel au destructeur de <Expression>" << endl;
#endif
}