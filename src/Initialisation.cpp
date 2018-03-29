using namespace std;

#include "Initialisation.h"
#include <iostream>

void Initialisation::print(std::ostream &stream) const
{
    stream << " Initialisation: Type=" << type << " Name=" << name << " ";
    stream << *expression << endl;
}

std::ostream& operator<<(std::ostream& stream, const Initialisation& initialisation)
{
    stream << " Initialisation: Type=" << initialisation.type << " Name=" << initialisation.name << " ";
    stream << *initialisation.expression << endl;
    return stream;
}

Initialisation &Initialisation::operator=(const Initialisation &unInitialisation)
{
}

void Initialisation::resolveScopeVariables(std::list<Declaration*> declProgramme, std::list<Declaration*> paramFunction, std::list<Declaration*> declBloc, std::list<Function*> functionProgram){
    this->expression->resolveScopeVariables(declProgramme, paramFunction, declBloc, functionProgram);
}

void Initialisation::resolveTypeExpr(){
    this->expression->resolveTypeExpr();
}

Initialisation::Initialisation(const Initialisation &unInitialisation)
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Initialisation>" << endl;
#endif
}

Initialisation::Initialisation(Type type, Expression* expression, std::string name)
{
    this->type = type;
    this->expression = expression;
    this->name = name;
#ifdef MAP
    cout << "Appel au constructeur de <Initialisation>" << endl;
#endif
}

Initialisation::~Initialisation()
{
#ifdef MAP
    cout << "Appel au destructeur de <Initialisation>" << endl;
#endif
}