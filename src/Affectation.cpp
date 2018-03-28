using namespace std;

#include "Affectation.h"
#include <iostream>

void Affectation::generateIR(ControlFlowGraph * controlFlowGraph)
{
	//
}

void Affectation::print(std::ostream &stream) const
{
    stream << " Affectation: " << *variable << " Operateur=" << operateur << " " << *expression << endl;
}

std::ostream& operator<<(std::ostream& stream, const Affectation& affectation)
{
    stream << " Affectation: " << *affectation.variable << " Operateur=" << affectation.operateur;
    stream << " " << *affectation.expression<< endl;
    return stream;
}


Affectation &Affectation::operator=(const Affectation &unAffectation) {
}


Affectation::Affectation(const Affectation &unAffectation) {
#ifdef MAP
    cout << "Appel au constructeur de copie de <Affectation>" << endl;
#endif
}


Affectation::Affectation(Variable *variable, Operateur operateur, Expression *expression) {
    this->variable = variable;
    this->operateur = operateur;
    this->expression = expression;
#ifdef MAP
    cout << "Appel au constructeur de <Affectation>" << endl;
#endif
}


Affectation::~Affectation() {
#ifdef MAP
    cout << "Appel au destructeur de <Affectation>" << endl;
#endif
}
