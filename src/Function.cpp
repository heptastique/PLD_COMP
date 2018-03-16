using namespace std;

#include <iostream>
#include "Function.h"


Function &Function::operator=(const Function &unFunction)
{
}


Function::Function(const Function &unFunction)
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Function>" << endl;
#endif
}


Function::Function()
{
#ifdef MAP
    cout << "Appel au constructeur de <Function>" << endl;
#endif
}


Function::~Function()
{
#ifdef MAP
    cout << "Appel au destructeur de <Function>" << endl;
#endif
}
