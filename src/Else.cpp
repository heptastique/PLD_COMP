using namespace std;

#include "Else.h"
#include <iostream>

Else &Else::operator=(const Else &unElse) {
}


Else::Else(const Else &unElse) {
#ifdef MAP
    cout << "Appel au constructeur de copie de <Else>" << endl;
#endif
}


Else::Else() {
#ifdef MAP
    cout << "Appel au constructeur de <Else>" << endl;
#endif
}


Else::~Else() {
#ifdef MAP
    cout << "Appel au destructeur de <Else>" << endl;
#endif
}