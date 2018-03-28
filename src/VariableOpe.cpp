using namespace std;

#include "VariableOpe.h"
#include <iostream>

void VariableOpe::print(std::ostream &stream) const
{
    stream << " VariableOpe: " << "Type=" << typeVariable << " Valeur=" << valeur << " " << " Ope=" << ope << endl;
}

std::ostream& operator<<(std::ostream& stream, const VariableOpe& variableOpe)
{
    stream << " VariableOpe: " << "Type=" << variableOpe.typeVariable << " Valeur=" << variableOpe.valeur << " Ope=" << variableOpe.ope << endl;
    return stream;
}

VariableOpe &VariableOpe::operator=(const VariableOpe &unVariableOpe) {
}


VariableOpe::VariableOpe(TypeVariable typeVariable, std::string valeur, PrePos ope): Variable(typeVariable, valeur) {
    this->ope = ope;
#ifdef MAP
    cout << "Appel au constructeur de <VariableDecPos>" << endl;
#endif
}


VariableOpe::~VariableOpe() {
#ifdef MAP
    cout << "Appel au destructeur de <VariableDecPos>" << endl;
#endif
}