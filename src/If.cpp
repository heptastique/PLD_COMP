using namespace std;

#include "If.h"
#include <iostream>

If &If::operator=(const If &unIf) {
}


If::If(const If &unIf) {
#ifdef MAP
    cout << "Appel au constructeur de copie de <If>" << endl;
#endif
}


If::If() {
#ifdef MAP
    cout << "Appel au constructeur de <If>" << endl;
#endif
}


If::~If() {
#ifdef MAP
    cout << "Appel au destructeur de <If>" << endl;
#endif
}