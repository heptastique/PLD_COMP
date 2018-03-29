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

void Expression::resolveScopeVariables(std::list<Declaration*> declProgramme, std::list<Declaration*> paramFunction, std::list<Declaration*> declBloc, std::list<Function*> functionProgram){

}

Type Expression::getType() {
    return this->type;
}

void Expression::setType(Type type) {
    this->type = type;
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