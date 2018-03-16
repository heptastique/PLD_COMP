using namespace std;

#include <iostream>
#include "Programme.h"

ostream& operator<<(ostream& stream, const Programme& programme)
{
    stream << "Programme :" << endl;
    for (auto it :  programme.declarions){
        stream << *it;
    }
    for (auto it :  programme.functions){
        stream << *it;
    }
    stream<<endl;
    return stream;
}

void Programme::addFunction(Function *function)
{
    this->functions.emplace_back(function);
}

void Programme::addDeclaration(Declaration *declaration)
{
    this->declarions.emplace_back(declaration);
}

Programme &Programme::operator=(const Programme &unProgramme)
{
}

Programme::Programme(const Programme &unProgramme)
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Programme>" << endl;
#endif
}


Programme::Programme()
{
#ifdef MAP
    cout << "Appel au constructeur de <Programme>" << endl;
#endif
}


Programme::~Programme()
{
#ifdef MAP
    cout << "Appel au destructeur de <Programme>" << endl;
#endif
}
