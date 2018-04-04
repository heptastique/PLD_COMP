using namespace std;

#include "AppelFunction.h"
#include "DeclarationTab.h"
#include "VariableIndex.h"
#include "VariableOpe.h"
#include "ErrorHandling.h"
#include <iostream>

string AppelFunction::generateIR(ControlFlowGraph * controlFlowGraph)
{
    // Special Case for putchar
    if (name == "putchar")
    {
        switch (variables[0]->getType())
        {
            // Parameter is a Character
            case CARACTERE :
            {
                controlFlowGraph->addIRInstr(IRInstr(PUTCHAR_VALUE, {to_string((int)((variables[0]->getValeur())[1]))}));

                break;
            }
            // Parameter is an Integer
            case ENTIER :
            {
                break;
            }
            // Parameter is a Variable
            case NAME :
            {
                controlFlowGraph->addIRInstr(IRInstr(PUTCHAR_RBP_REL, {to_string(variables[0]->getDeclaration()->getOffset())}));

                break;
            }
        }
    }
    else
    {
        // For each Parameter
        for (auto variable : variables)
        {
            switch (variable->getType())
            {
                // Parameter is a Variable
                case NAME :
                {
                    controlFlowGraph->addIRInstr(IRInstr(PUSH_RBP_REL, {to_string(variable->getDeclaration()->getOffset())}));

                    break;
                }
                // Parameter is an Integer
                case ENTIER :
                // Parameter is a Character
                case CARACTERE :
                {
                    controlFlowGraph->addIRInstr(IRInstr(PUSH_VALUE, {variable->getValeur()}));

                    break;
                }
            }
        }

        // Call Function
        controlFlowGraph->addIRInstr(IRInstr(CALL, {name}));

        // Reset SP after Parameters push
        controlFlowGraph->addIRInstr(IRInstr(ADD_RSP, {to_string(variables.size() * 8)}));
    }

    return "";
}

void AppelFunction::print(std::ostream &stream) const
{
    stream << " AppelFunction: Name=" << name;

    for (auto it : variables)
    {
        if(VariableIndex *varInd = dynamic_cast<VariableIndex*>(it))
        {
            stream << *varInd;
        }
        else
        {
            if(VariableOpe *varOpe = dynamic_cast<VariableOpe*>(it))
            {
                stream << *varOpe;
            }
            else
            {
                stream << *it;
            }
        }
    }
    
    stream << endl;
}

std::ostream& operator<<(std::ostream& stream, const AppelFunction& appelFunction)
{
    stream << " AppelFunction: Name=" << appelFunction.name;
    for (auto it : appelFunction.variables){
        stream << *it;
    }
    stream << endl;
    return stream;
}

AppelFunction &AppelFunction::operator=(const AppelFunction &unAppelFunction) 
{
    //
}

void AppelFunction::resolveScopeVariables(std::vector<Declaration*> declProgramme, std::vector<Declaration*> paramFunction, std::vector<Declaration*> declBloc, std::vector<Function*> functionProgram)
{
    std::vector<Variable *> variables = getVariables();
    
    for (auto variable : variables)
    {
        variable->resolveScopeVariables(declProgramme,paramFunction,declBloc,functionProgram);
    }
    
    for ( auto function : functionProgram)
    {
        if (function->getName().compare(this->name) == 0)
        {
            this->functionAssociee = function;
            return;
        }
    }
    
    if ( this->name.compare("putchar") != 0)
    {
        ErrorHandling::ThrowError(106,0,this->name);
    }
}

void AppelFunction::resolveTypeExpr()
{
    if ( this->functionAssociee != nullptr)
    {
        this->setType(this->functionAssociee->getTypeRetour());
    }
    else
    {
        cout << "error function does not exist" << endl;
    }
}

vector <Variable *> AppelFunction::getVariables()
{
    return this->variables;
}

AppelFunction::AppelFunction(const AppelFunction &unAppelFunction)
{
    #ifdef MAP
        cout << "Appel au constructeur de copie de <AppelFunction>" << endl;
    #endif
}

AppelFunction::AppelFunction(std::string name, std::vector<Variable *> variables)
{
    #ifdef MAP
        cout << "Appel au constructeur de <AppelFunction>" << endl;
    #endif

    this->name = name;
    this->variables = variables;
}

AppelFunction::~AppelFunction()
{
    #ifdef MAP
        cout << "Appel au destructeur de <AppelFunction>" << endl;
    #endif
}
