using namespace std;

#include "OperationUnaire.h"
#include <iostream>

void OperationUnaire::print(std::ostream &stream) const
{
    stream << " OperationUnaire: Operateur=" << operateur << " " << *expression;
    stream << endl;
}

std::ostream& operator<<(std::ostream& stream, const OperationUnaire& operationUnaire)
{
    stream << " OperationUnaire:  Operateur=" << operationUnaire.operateur << " " << *operationUnaire.expression;
    stream << endl;
    return stream;
}


OperationUnaire &OperationUnaire::operator=(const OperationUnaire &unOperationUnaire) {
}

void OperationUnaire::resolveScopeVariables(std::list<Declaration*> declProgramme, std::list<Declaration*> paramFunction, std::list<Declaration*> declBloc){
    this->expression->resolveScopeVariables(declProgramme, paramFunction, declBloc);
}

OperationUnaire::OperationUnaire(const OperationUnaire &unOperationUnaire) {
#ifdef MAP
    cout << "Appel au constructeur de copie de <OperationUnaire>" << endl;
#endif
}


OperationUnaire::OperationUnaire(Operateur operateur, Expression* expression) {
    this->operateur = operateur;
    this->expression = expression;
#ifdef MAP
    cout << "Appel au constructeur de <OperationUnaire>" << endl;
#endif
}


OperationUnaire::~OperationUnaire() {
#ifdef MAP
    cout << "Appel au destructeur de <OperationUnaire>" << endl;
#endif
}