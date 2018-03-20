using namespace std;

#include "IRInstr.h"
#include <iostream>

IRInstr::IRInstr(const IRInstr &iRInstr)
{
	#ifdef MAP
		cout << "Appel au constructeur de copie de <IRInstr>" << endl;
	#endif
}

IRInstr::IRInstr()
{
	#ifdef MAP
		cout << "Appel au constructeur de <IRInstr>" << endl;
	#endif
}

IRInstr::~IRInstr()
{
	#ifdef MAP
		cout << "Appel au destructeur de <IRInstr>" << endl;
	#endif
}
