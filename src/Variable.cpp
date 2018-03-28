using namespace std;

#include "Variable.h"
#include <iostream>

//void Variable::generateIR(ControlFlowGraph * controlFlowGraph)
//{
	//cout << "Variable::generateIR" << endl;
//}

void Variable::print(std::ostream &stream) const
{
    stream << " Variable: " << "Type=" << typeVariable << " Valeur=" << valeur << " ";
}

std::ostream& operator<<(std::ostream& stream, const Variable& variable)
{
    stream << " Variable: " << "Type=" << variable.typeVariable << " Valeur=" << variable.valeur << " ";
    return stream;
}


Variable &Variable::operator=(const Variable &unVariable) {
}


Variable::Variable(const Variable &unVariable) {
#ifdef MAP
    cout << "Appel au constructeur de copie de <Variable>" << endl;
#endif
}


Variable::Variable(TypeVariable typeVariable, std::string valeur) {
    this->typeVariable = typeVariable;
    this->valeur = valeur;
#ifdef MAP
    cout << "Appel au constructeur de <Variable>" << endl;
#endif
}


Variable::~Variable() {
#ifdef MAP
    cout << "Appel au destructeur de <Variable>" << endl;
#endif
}
