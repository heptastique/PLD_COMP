using namespace std;

#include <iostream>

Declaration &Declaration::operator=(const Declaration &unDeclaration) {
}


Declaration::Declaration(const Declaration &unDeclaration) {
#ifdef MAP
    cout << "Appel au constructeur de copie de <Declaration>" << endl;
#endif
}


Declaration::Declaration() {
#ifdef MAP
    cout << "Appel au constructeur de <Declaration>" << endl;
#endif
}


Declaration::~Declaration() {
#ifdef MAP
    cout << "Appel au destructeur de <Declaration>" << endl;
#endif
}