using namespace std;

#include "RetourFonction.h"
#include <iostream>

void RetourFonction::print(std::ostream &stream) const
{
    stream << " RetourFonction:" << *variable;
    stream << endl;
}

std::ostream& operator<<(std::ostream& stream, const RetourFonction& retourFonction)
{
    stream << " RetourFonction:" << *retourFonction.variable;
    stream << endl;
    return stream;
}

RetourFonction &RetourFonction::operator=(const RetourFonction &unRetourFonction) {
}


RetourFonction::RetourFonction(const RetourFonction &unRetourFonction) {
#ifdef MAP
    cout << "Appel au constructeur de copie de <RetourFonction>" << endl;
#endif
}


RetourFonction::RetourFonction(Variable* variable) {
    this->variable = variable;
#ifdef MAP
    cout << "Appel au constructeur de <RetourFonction>" << endl;
#endif
}


RetourFonction::~RetourFonction() {
#ifdef MAP
    cout << "Appel au destructeur de <RetourFonction>" << endl;
#endif
}