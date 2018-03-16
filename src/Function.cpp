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


Function::Function(const string &name,const Bloc &bloc)
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
