using namespace std;

# include "IRInstr.h"
# include <iostream>

string IRInstr::getParam(int index)
{
	list <string> :: iterator it = params.begin();

	for (int i = 0; i < index; i = i + 1)
	{
		++ it;
	}

	return *it;
}

list <string> IRInstr::getParams() const
{
	list <string> ret;

	list <string> :: const_iterator it = params.begin();

	while (it != params.end())
	{
		ret.push_back(*it);

		++ it;
	}

	return ret;
}

IRInstr::IRInstr(const IRInstr &iRInstr)
{
	#ifdef MAP
		cout << "Appel au constructeur de copie de <IRInstr>" << endl;
	#endif

	mnemo = iRInstr.mnemo;
	params = iRInstr.getParams();
}

IRInstr::IRInstr(Mnemo mnemo, list <string> params)
{
	#ifdef MAP
		cout << "Appel au constructeur de <IRInstr>" << endl;
	#endif

	this->mnemo = mnemo;

	list <string> :: iterator it = params.begin();

	while (it != params.end())
	{
		this->params.push_back(*it);
		++ it;
	}
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
