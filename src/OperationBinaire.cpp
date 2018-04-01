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

void OperationBinaire::resolveScopeVariables(std::vector<Declaration*> declProgramme, std::vector<Declaration*> paramFunction, std::vector<Declaration*> declBloc, std::vector<Function*> functionProgram){
    this->expressionL->resolveScopeVariables(declProgramme, paramFunction, declBloc, functionProgram);
    this->expressionR->resolveScopeVariables(declProgramme, paramFunction, declBloc, functionProgram);
}

void OperationBinaire::resolveTypeExpr() {
    this->expressionL->resolveTypeExpr();
    this->expressionR->resolveTypeExpr();
    Type typeExprL = expressionL->getType();
    Type typeExprR = expressionL->getType();
    if ( typeExprL == INT64_T || typeExprR == INT64_T) {
        this->setType( INT64_T);
    } else {
        if ( typeExprL == INT32_T || typeExprL == CHAR){
            this->setType( INT32_T);
        }
        else
        {
            cout << "error attributing type" << endl;
        }
    }
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
