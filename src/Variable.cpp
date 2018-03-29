using namespace std;

#include "Variable.h"
#include "VariableIndex.h"
#include <iostream>

void Variable::generateIR(ControlFlowGraph * controlFlowGraph)
{
	cout << "Variable::generateIR" << endl;
}

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

void Variable::resolveScopeVariables(std::list<Declaration*> declProgramme, std::list<Declaration*> paramFunction, std::list<Declaration*> declBloc, std::list<Function*> functionProgram){
    if (this->typeVariable == NAME) {
        bool notfound = true;
        for (auto decl : declBloc) {
            if (decl->getName().compare(this->valeur) == 0) {
                notfound = false;
                this->declarationAssociee = decl;
                cout << decl->getName() << " from bloc assigned to " << this->valeur << endl;
                break;
            }
        }
        if (notfound) {
            for (auto decl : paramFunction) {
                if (decl->getName().compare(this->valeur) == 0) {
                    notfound = false;
                    this->declarationAssociee = decl;
                    cout << decl->getName() << " from function parameters assigned to " << this->valeur << endl;
                    break;
                }
            }
        }
        if (notfound) {
            for (auto decl : declProgramme) {
                cout << decl <<endl;
                if (decl->getName().compare(this->valeur) == 0) {
                    notfound = false;
                    this->declarationAssociee = decl;
                    cout << decl->getName() << " from global variables assigned to " << this->valeur << endl;
                    break;
                }
            }
        }
        if (notfound) {
            cout << "variable " << this->valeur << " is not instantiated" << endl;
        }
    }
}

void Variable::resolveTypeExpr() {
    cout << declarationAssociee << endl;
    if (this->declarationAssociee != nullptr){
        this->setType(this->declarationAssociee->getType());
    }
    else
    {
        cout << "np" << endl;
    }
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
