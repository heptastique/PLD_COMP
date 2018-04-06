using namespace std;

#include "WarningHandling.h"
#include <iostream>

void WarningHandling::ThrowWarning(int code, string name)
{
    cout  << " Attention " << code << " : ";

    switch(code)
    {
        // Semantic warning
        case 110 :
            cout << "La fonction " << name << " n'est pas utilisé" << endl;
            break;
        case 111 :
            cout << "La variable locale " << name << " n'est pas utilisée " << endl;
            break;
        case 112 :
            cout << "Le paramètre " << name << " n'est pas utilisée " << endl;
            break;
        case 113 :
            cout << "La variable globale " << name << " n'est pas utilisée " << endl;
            break;

    }

    cout << "\n" << endl;

    //exit(code); useless because already added inside the switch
}
