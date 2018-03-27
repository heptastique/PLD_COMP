using namespace std;

#include "OperationBinaire.h"
#include <iostream>

void OperationBinaire::print(std::ostream &stream) const
{
    stream << " OperationBinaire: " << *expressionL << " Operateur=" << operateur << " " << *expressionR;
    stream << endl;
}

std::ostream& operator<<(std::ostream& stream, const OperationBinaire& operationBinaire)
{
    stream << " OperationBinaire: " << *operationBinaire.expressionL << " Operateur=" << operationBinaire.operateur;
    stream << " " << *operationBinaire.expressionR;
    stream << endl;
    return stream;
}

OperationBinaire &OperationBinaire::operator=(const OperationBinaire &unOperationBinaire) {
}

void OperationBinaire::resolveScopeVariables(std::list<Declaration*> declProgramme, std::list<Declaration*> paramFunction, std::list<Declaration*> declBloc){
    this->expressionL->resolveScopeVariables(declProgramme, paramFunction, declBloc);
    this->expressionR->resolveScopeVariables(declProgramme, paramFunction, declBloc);
}

OperationBinaire::OperationBinaire(const OperationBinaire &unOperationBinaire) {
#ifdef MAP
    cout << "Appel au constructeur de copie de <OperationBinaire>" << endl;
#endif
}


OperationBinaire::OperationBinaire(Expression* expressionL, Expression* expressionR, Operateur operateur) {
    this->expressionL = expressionL;
    this->expressionR = expressionR;
    this->operateur = operateur;
#ifdef MAP
    cout << "Appel au constructeur de <OperationBinaire>" << endl;
#endif
}


OperationBinaire::~OperationBinaire() {
#ifdef MAP
    cout << "Appel au destructeur de <OperationBinaire>" << endl;
#endif
}