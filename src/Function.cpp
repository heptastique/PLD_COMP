using namespace std;

#include "Function.h"
#include <iostream>

std::ostream& operator<<(std::ostream& stream, const Function& function)
{
    stream << " Fonction: Name=" << function.name <<  endl;
    stream << "     Bloc=" << *function.bloc;
    return stream;
}

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
