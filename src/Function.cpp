using namespace std;

#include "Function.h"
#include <iostream>

std::ostream& operator<<(std::ostream& stream, const Function& function)
{
    stream << " Fonction: Name=" << function.name << " TypeRetour=" << function.typeRetour << endl;
    if(!function.declarations.empty()){
        stream << "     Param:" << endl;
        for (auto it : function.declarations){
            stream << "     " << *it;
        }
    }
    stream << *function.bloc;
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


Function::Function(string name, Bloc * bloc, Type typeRetour)
{
#ifdef MAP
    cout << "Appel au constructeur de <Function>" << endl;
#endif
    this->name = name;
    this->bloc = bloc;
    this->typeRetour = typeRetour;
}


Function::~Function()
{
#ifdef MAP
    cout << "Appel au destructeur de <Function>" << endl;
#endif
}
