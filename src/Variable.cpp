using namespace std;

#include "Variable.h"
#include "VariableIndex.h"
#include "ErrorHandling.h"
#include <iostream>

string Variable::generateIR(ControlFlowGraph * controlFlowGraph)
{
    cout << "Variable::generateIR" << endl;

    if(this->typeVariable == ENTIER)
    {
        string var = "tmp1";
        //string var = controlFlowGraph-->createNewVar();
        controlFlowGraph->addIRInstr(IRInstr(REG_STORE, {var, valeur}));
        return var;
    }

    /*
    string reg = createNewReg();

    list <string> params;

    params.push_back(reg);
    params.push_back(valeur);

    controlFlowGraph->addInstruction(IRInstr(REG_STORE), params);
    return reg;
    */

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

<<<<<<< HEAD
Declaration * Variable::getDeclaration()
{
        return declarationAssociee;
}

Variable & Variable::operator=(const Variable & variable)
{
        typeVariable = variable.typeVariable;
        valeur = variable.valeur;
       declarationAssociee = variable.declarationAssociee;
=======
Variable &Variable::operator=(const Variable &unVariable)
{
    //
>>>>>>> Formatting_End
}

void Variable::resolveScopeVariables(std::vector<Declaration*> declProgramme, std::vector<Declaration*> paramFunction, std::vector<Declaration*> declBloc, std::vector<Function*> functionProgram)
{
    if (this->typeVariable == NAME)
    {
        bool notfound = true;
<<<<<<< HEAD

=======
        
>>>>>>> Formatting_End
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
<<<<<<< HEAD

=======
        
>>>>>>> Formatting_End
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
