using namespace std;

#include "Function.h"
#include <iostream>


Function &Function::operator=(const Function &unFunction)
{
}


Function::Function(const Function &unFunction)
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Function>" << endl;
#endif
}


Function::Function(string name, Bloc *bloc)
{
#ifdef MAP
    cout << "Appel au constructeur de <Function>" << endl;
#endif
    this->name = name;
    this->bloc = bloc;
}


Function::~Function()
{
#ifdef MAP
    cout << "Appel au destructeur de <Function>" << endl;
#endif
}
