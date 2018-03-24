using namespace std;

#include "While.h"
#include <iostream>

While &While::operator=(const While &unWhile) {
}


While::While(const While &unWhile) {
#ifdef MAP
    cout << "Appel au constructeur de copie de <While>" << endl;
#endif
}


While::While() {
#ifdef MAP
    cout << "Appel au constructeur de <While>" << endl;
#endif
}


While::~While() {
#ifdef MAP
    cout << "Appel au destructeur de <While>" << endl;
#endif
}