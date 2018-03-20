using namespace std;

#include "AppelFunction.h"
#include <iostream>

AppelFunction &AppelFunction::operator=(const AppelFunction &unAppelFunction) {
}


AppelFunction::AppelFunction(const AppelFunction &unAppelFunction) {
#ifdef MAP
    cout << "Appel au constructeur de copie de <AppelFunction>" << endl;
#endif
}


AppelFunction::AppelFunction() {
#ifdef MAP
    cout << "Appel au constructeur de <AppelFunction>" << endl;
#endif
}


AppelFunction::~AppelFunction() {
#ifdef MAP
    cout << "Appel au destructeur de <AppelFunction>" << endl;
#endif
}