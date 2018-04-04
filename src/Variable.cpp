using namespace std;

#include "Variable.h"
#include "VariableIndex.h"
#include "ErrorHandling.h"
#include <iostream>

string Variable::generateIR(ControlFlowGraph * controlFlowGraph)
{
    cout << "Variable::generateIR" << endl;

    switch (this->getType())
    {
        case ENTIER :
        {
            string var = controlFlowGraph->createNewTemp();
            controlFlowGraph->addIRInstr(IRInstr(REG_STORE, {valeur, var}));
            return var;
        }
        case CARACTERE :
        {
            //controlFlowGraph->addIRInstr(IRInstr(STORE_RBP_REL, {to_string((int)(var->getValeur())[1]), to_string(variable->getDeclaration()->getOffset())}));
            string var = controlFlowGraph->createNewTemp();
            controlFlowGraph->addIRInstr(IRInstr(REG_STORE, {to_string((int)valeur[1]), var}));
            return var;
        }
        case NAME :
        {
            return this->getDeclaration()->getName();
        }
    }

    return "";
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

Declaration * Variable::getDeclaration()
{
    return declarationAssociee;
}

Variable & Variable::operator=(const Variable & variable)
{
    typeVariable = variable.typeVariable;
    valeur = variable.valeur;
    declarationAssociee = variable.declarationAssociee;
}

void Variable::resolveScopeVariables(std::vector<Declaration*> declProgramme, std::vector<Declaration*> paramFunction, std::vector<Declaration*> declBloc, std::vector<Function*> functionProgram)
{
    if (this->typeVariable == NAME)
    {
        bool notfound = true;

        for (auto decl : declBloc)
        {
            if (decl->getName().compare(this->valeur) == 0)
            {
                notfound = false;
                this->declarationAssociee = decl;
                cout << decl->getName() << " from bloc assigned to " << this->valeur << endl;
                break;
            }
        }

        if (notfound)
        {
            for (auto decl : paramFunction)
            {
                if (decl->getName().compare(this->valeur) == 0)
                {
                    notfound = false;
                    this->declarationAssociee = decl;
                    cout << decl->getName() << " from function parameters assigned to " << this->valeur << endl;
                    break;
                }
            }
        }
        
        if (notfound)
        {
            for (auto decl : declProgramme)
            {
                cout << decl <<endl;
                if (decl->getName().compare(this->valeur) == 0)
                {
                    notfound = false;
                    this->declarationAssociee = decl;
                    cout << decl->getName() << " from global variables assigned to " << this->valeur << endl;
                    break;
                }
            }
        }

        if (notfound)
        {
            ErrorHandling::ThrowError(104, 0, this->valeur);
        }
    }
}

void Variable::resolveTypeExpr()
{
    cout << declarationAssociee << endl;

    if ( this->typeVariable == NAME)
    {
        if (this->declarationAssociee != nullptr)
        {
            this->setType(this->declarationAssociee->getType());
        }
        else
        {
            ErrorHandling::ThrowError(104, 0, this->valeur);
        }
    }
}

Variable::Variable(const Variable &unVariable)
{
    #ifdef MAP
        cout << "Appel au constructeur de copie de <Variable>" << endl;
    #endif
}

Variable::Variable(TypeVariable typeVariable, std::string valeur)
{
    #ifdef MAP
        cout << "Appel au constructeur de <Variable>" << endl;
    #endif

    this->typeVariable = typeVariable;
    this->valeur = valeur;
}

Variable::~Variable()
{
    #ifdef MAP
        cout << "Appel au destructeur de <Variable>" << endl;
    #endif
}
