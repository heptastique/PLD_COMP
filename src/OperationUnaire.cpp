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

void OperationUnaire::resolveScopeVariables(std::vector<Declaration*> declProgramme, std::vector<Declaration*> paramFunction, std::vector<Declaration*> declBloc, std::vector<Function*> functionProgram){
    this->expression->resolveScopeVariables(declProgramme, paramFunction, declBloc, functionProgram);
}

void OperationUnaire::resolveTypeExpr() {
    this->expression->resolveTypeExpr();
    Type typeExpr = expression->getType();
    switch ( typeExpr){
        case CHAR :
            this->setType( INT32_T);
            break;
        case INT32_T:
            this->setType( INT32_T);
            break;
        case INT64_T:
            this->setType( INT64_T);
            break;
        default :
            cout << "error attributing type" << endl;
    }
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
