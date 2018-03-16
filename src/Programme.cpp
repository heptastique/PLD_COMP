using namespace std;

#include <iostream>
#include "Programme.h"

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
