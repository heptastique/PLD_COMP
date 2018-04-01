using namespace std;

# include "IRInstr.h"
# include <iostream>

Mnemonique IRInstr::getMnemonique() const
{
    return mnemonique;
}

string IRInstr::getParam(int index) const
{
    vector <string> :: const_iterator param = params.begin();

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

vector <string> IRInstr::getParams() const
{
    return params;
}

IRInstr::IRInstr()
{
    #ifdef MAP
        cout << "Appel au constructeur de <IRInstr>" << endl;
    #endif
}

IRInstr::IRInstr(const IRInstr &iRInstr)
{
    #ifdef MAP
        cout << "Appel au constructeur de copie de <IRInstr>" << endl;
    #endif

    mnemonique = iRInstr.mnemonique;
    params = iRInstr.params;
}

IRInstr::IRInstr(Mnemonique mnemonique, vector <string> params)
{
    #ifdef MAP
        cout << "Appel au constructeur de <IRInstr>" << endl;
    #endif

    this->mnemonique = mnemonique;
    this->params = params;
}

IRInstr::~IRInstr()
{
    #ifdef MAP
        cout << "Appel au destructeur de <IRInstr>" << endl;
    #endif
}
