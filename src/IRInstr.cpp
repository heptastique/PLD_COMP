using namespace std;

# include "IRInstr.h"
# include <iostream>

Mnemonique IRInstr::getMnemonique() const
{
	return mnemonique;
}

string IRInstr::getParam(int index) const
{
	list <string> :: const_iterator param = params.begin();

	int i = 0;

	while (param != params.end() && i < index)
	{
		param ++;;
		i = i + 1;
	}

	if (i == index)
	{
		return *param;
	}

	return "";
}

list <string> IRInstr::getParams() const
{
	list <string> paramsCopy;

	list <string> :: const_iterator it = params.begin();

	while (it != params.end())
	{
		paramsCopy.push_back(*it);

		++ it;
	}

	return paramsCopy;
}

IRInstr::IRInstr(const IRInstr &iRInstr)
{
	#ifdef MAP
		cout << "Appel au constructeur de copie de <IRInstr>" << endl;
	#endif

	mnemonique = iRInstr.mnemonique;
	params = iRInstr.getParams();
}

IRInstr::IRInstr(Mnemonique mnemonique, list <string> params)
{
	#ifdef MAP
		cout << "Appel au constructeur de <IRInstr>" << endl;
	#endif

	this->mnemonique = mnemonique;

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
