using namespace std;

#include "Variable.h"
#include "VariableIndex.h"
#include "ErrorHandling.h"
#include <iostream>

void Variable::generateIR(ControlFlowGraph * controlFlowGraph)
{
    cout << "Variable::generateIR" << endl;

    /*
    string reg = createNewReg();
    
    list <string> params;
    
    params.push_back(reg);
    params.push_back(valeur);
    
    controlFlowGraph->addInstruction(IRInstr(REG_STORE), params);
    
    return reg;
    */
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

void Variable::resolveScopeVariables(std::vector<Declaration*> declProgramme, std::vector<Declaration*> paramFunction, std::vector<Declaration*> declBloc, std::vector<Function*> functionProgram){
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
            ErrorHandling::ThrowError(104, 0, this->valeur);
        }
    }
}

void Variable::resolveTypeExpr() {
    cout << declarationAssociee << endl;
    if ( this->typeVariable == NAME) {
        if (this->declarationAssociee != nullptr) {
            this->setType(this->declarationAssociee->getType());
        } else {
            ErrorHandling::ThrowError(104, 0, this->valeur);
        }
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
