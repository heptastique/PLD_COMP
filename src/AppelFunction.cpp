using namespace std;

#include "AppelFunction.h"
#include "DeclarationTab.h"
#include "VariableIndex.h"
#include "VariableOpe.h"
#include "ErrorHandling.h"
#include <iostream>

void AppelFunction::generateIR(ControlFlowGraph * controlFlowGraph)
{
    // Special Case for putchar
    if (name == "putchar")
    {
        controlFlowGraph->addIRInstr(IRInstr(PUTCHAR, {to_string((int)((variables[0]->getValeur())[1]))}));
    }

    // Generate IR for Parameters

    /*for (auto variable : variables)
    {
        //variable->generateIR();
    }*/

    // add IRInstr call

    /*vector <string> params;

    params.push_back(name);
    params.push_back("r0");

    IRInstr iRInstr(FUNCTION_CALL, params);*/
}

void AppelFunction::print(std::ostream &stream) const
{
    stream << " AppelFunction: Name=" << name;
    for (auto it : variables){
        if(VariableIndex *varInd = dynamic_cast<VariableIndex*>(it))
        {
            stream << *varInd;
        } else
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

AppelFunction &AppelFunction::operator=(const AppelFunction &unAppelFunction) {
}

void AppelFunction::resolveScopeVariables(std::vector<Declaration*> declProgramme, std::vector<Declaration*> paramFunction, std::vector<Declaration*> declBloc, std::vector<Function*> functionProgram){
    std::vector<Variable *> variables = getVariables();
    for (auto variable : variables){
        variable->resolveScopeVariables(declProgramme,paramFunction,declBloc,functionProgram);
    }
    for ( auto function : functionProgram){
        if (function->getName().compare(this->name) == 0){
            this->functionAssociee = function;
            return;
        }
    }
    if ( this->name.compare("putchar") != 0){
        ErrorHandling::ThrowError(106,0,this->name);
    }
}

void AppelFunction::resolveTypeExpr(){
    if ( this->functionAssociee != nullptr){
        this->setType(this->functionAssociee->getTypeRetour());
    }
    else
    {
        cout << "error function does not exist" << endl;
    }
}

vector <Variable *> AppelFunction::getVariables(){
    return this->variables;
}

AppelFunction::AppelFunction(const AppelFunction &unAppelFunction) {
#ifdef MAP
    cout << "Appel au constructeur de copie de <AppelFunction>" << endl;
#endif
}

AppelFunction::AppelFunction(std::string name, std::vector<Variable *> variables) {
    this->name = name;
    this->variables = variables;
#ifdef MAP
    cout << "Appel au constructeur de <AppelFunction>" << endl;
#endif
}

AppelFunction::~AppelFunction() {
#ifdef MAP
    cout << "Appel au destructeur de <AppelFunction>" << endl;
#endif
}
