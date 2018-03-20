using namespace std;

# include "CFG.h"
# include <iostream>

CFG::CFG(const CFG &cFG)
{
	#ifdef MAP
		cout << "Appel au constructeur de copie de <CFG>" << endl;
	#endif
}

CFG::CFG()
{
	#ifdef MAP
		cout << "Appel au constructeur de <CFG>" << endl;
	#endif
}

CFG::~CFG()
{
	#ifdef MAP
		cout << "Appel au destructeur de <CFG>" << endl;
	#endif
}
