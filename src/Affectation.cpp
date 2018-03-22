using namespace std;

#include "Affectation.h"
#include <iostream>

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