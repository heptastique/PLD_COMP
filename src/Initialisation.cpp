using namespace std;

#include "Initialisation.h"
#include <iostream>

Initialisation &Initialisation::operator=(const Initialisation &unInitialisation)
{
}


Initialisation::Initialisation(const Initialisation &unInitialisation)
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Initialisation>" << endl;
#endif
}


Initialisation::Initialisation(): Instruction()
{
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