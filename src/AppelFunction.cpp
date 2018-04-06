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
        switch (expressions[0]->getType())
        {
            // Parameter is a Character
            case CHAR :
            {
                string var = expressions[0]->generateIR(controlFlowGraph);
                cout<< var << "carac" <<endl;
                controlFlowGraph->addIRInstr(IRInstr(PUTCHAR_VALUE, {var.substr(4)}));
                break;
            }
            // Parameter is an Integer
            case INT32_T :
            {
                string var = expressions[0]->generateIR(controlFlowGraph);
                cout<< var << "entier" <<endl;
                controlFlowGraph->addIRInstr(IRInstr(PUTCHAR_VALUE, {var.substr(4)}));
                break;
            }
            case INT64_T :
            {
                string var = expressions[0]->generateIR(controlFlowGraph);
                cout<< var << "entier" <<endl;
                controlFlowGraph->addIRInstr(IRInstr(PUTCHAR_VALUE, {var.substr(4)}));
                break;
            }
        }
    }
    else
    {
        int safetyOffset = -(controlFlowGraph->getLastOffset() + 8);

        controlFlowGraph->addIRInstr(IRInstr(SUB_RSP, {to_string(safetyOffset)}));

        // For each Parameter
        for (auto variable : expressions)
        {
            switch (variable->getType())
            {
                // Parameter is a Character
                case CHAR :
                {
                    string var = variable->generateIR(controlFlowGraph);
                    controlFlowGraph->addIRInstr(IRInstr(PUSH_RBP_REL, {var.substr(4)}));
                    break;
                }
                    // Parameter is an Integer
                case INT32_T :
                {
                    string var = variable->generateIR(controlFlowGraph);
                    controlFlowGraph->addIRInstr(IRInstr(PUSH_RBP_REL, {var.substr(4)}));
                    break;
                }
                    // Parameter is a Variable
                case INT64_T :
                {
                    string var = variable->generateIR(controlFlowGraph);
                    controlFlowGraph->addIRInstr(IRInstr(PUSH_RBP_REL, {var.substr(4)}));
                    break;
                }
            }
        }

        // Call Function
        controlFlowGraph->addIRInstr(IRInstr(CALL, {name}));

        // Reset SP after Parameters push
        controlFlowGraph->addIRInstr(IRInstr(ADD_RSP, {to_string(expressions.size() * 8 + safetyOffset)}));

        string tmp = controlFlowGraph->createNewTemp(this->getType());
        controlFlowGraph->addIRInstr(IRInstr(MOV_REG_RBP_REL,{"rax", tmp.substr(4)}));

        return tmp;
    }

    // For the moment
    return "VAR.9999";
}

void AppelFunction::print(std::ostream &stream) const
{
    stream << " AppelFunction: Name=" << name << " ";

    for (auto it : expressions)
    {
        stream << *it;
    }
    
    stream << endl;
}

std::ostream& operator<<(std::ostream& stream, const AppelFunction& appelFunction)
{
    stream << " AppelFunction: Name=" << appelFunction.name;
    for (auto it : appelFunction.expressions){
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
    std::vector<Expression *> expressions = getExpressions();
    
    for (auto expression : expressions)
    {
        expression->resolveScopeVariables(declProgramme,paramFunction,declBloc,functionProgram);
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
    for (auto expression : expressions)
    {
        expression->resolveTypeExpr();
    }
    if ( this->functionAssociee != nullptr)
    {
        this->setType(this->functionAssociee->getTypeRetour());
    }
    else
    {
        if ( this->name.compare("putchar") != 0)
        {
            ErrorHandling::ThrowError(106,0,this->name);
        }
    }
}

vector <Expression *> AppelFunction::getExpressions()
{
    return this->expressions;
}

AppelFunction::AppelFunction(const AppelFunction &unAppelFunction)
{
    #ifdef MAP
        cout << "Appel au constructeur de copie de <AppelFunction>" << endl;
    #endif
}

AppelFunction::AppelFunction(std::string name, std::vector<Expression *> expressions)
{
    #ifdef MAP
        cout << "Appel au constructeur de <AppelFunction>" << endl;
    #endif

    this->name = name;
    this->expressions = expressions;
}

AppelFunction::~AppelFunction()
{
    #ifdef MAP
        cout << "Appel au destructeur de <AppelFunction>" << endl;
    #endif
}
