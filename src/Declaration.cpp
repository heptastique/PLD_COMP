using namespace std;

#include "Declaration.h"
#include <iostream>


std::ostream& operator<<(std::ostream& stream, const Declaration& declaration)
{
    stream << " Declaration: Name=" << declaration.name << " Type=" << declaration.type << endl;
    return stream;
}


Declaration &Declaration::operator=(const Declaration &unDeclaration)
{
}


Declaration::Declaration(const Declaration &unDeclaration)
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Declaration>" << endl;
#endif
}


Declaration::Declaration(string name, Type type)
{
    this->name = name;
    this->type = type;
#ifdef MAP
    cout << "Appel au constructeur de <Declaration>" << endl;
#endif
}


Declaration::~Declaration()
{
#ifdef MAP
    cout << "Appel au destructeur de <Declaration>" << endl;
#endif
}