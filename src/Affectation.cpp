using namespace std;

#include "Affectation.h"
#include "VariableIndex.h"
#include "OperationBinaire.h"
#include "AppelFunction.h"
#include <iostream>
#include <typeinfo>

string Affectation::generateIR(ControlFlowGraph * controlFlowGraph)
{
    string right = expression->generateIR(controlFlowGraph);
    string left = variable->generateIR(controlFlowGraph);
    string temp;
    switch ( this->operateur)
    {
        case EQUAL :
            controlFlowGraph->addIRInstr(IRInstr(MOV_RBP_REL_RBP_REl, {right.substr(4), left.substr(4)}));
            break;
        case PLUSEQUAL :
            temp = controlFlowGraph->createNewTemp(expression->getType());
            controlFlowGraph->addIRInstr(IRInstr(BINARYOPERATION, {to_string(PLUS), temp.substr(4), left.substr(4), right.substr(4)}));
            controlFlowGraph->addIRInstr(IRInstr(MOV_RBP_REL_RBP_REl, {temp.substr(4), left.substr(4)}));
            break;
        case MINUSEQUAL :
            temp = controlFlowGraph->createNewTemp(expression->getType());
            controlFlowGraph->addIRInstr(IRInstr(BINARYOPERATION, {to_string(MINUS), temp.substr(4), left.substr(4), right.substr(4)}));
            controlFlowGraph->addIRInstr(IRInstr(MOV_RBP_REL_RBP_REl, {temp.substr(4), left.substr(4)}));
            break;
        case MULTEQUAL :
            temp = controlFlowGraph->createNewTemp(expression->getType());
            controlFlowGraph->addIRInstr(IRInstr(BINARYOPERATION, {to_string(MULT), temp.substr(4), left.substr(4), right.substr(4)}));
            controlFlowGraph->addIRInstr(IRInstr(MOV_RBP_REL_RBP_REl, {temp.substr(4), left.substr(4)}));
            break;
        case DIVEQUAL :
            temp = controlFlowGraph->createNewTemp(expression->getType());
            controlFlowGraph->addIRInstr(IRInstr(BINARYOPERATION, {to_string(DIV), temp.substr(4), left.substr(4), right.substr(4)}));
            controlFlowGraph->addIRInstr(IRInstr(MOV_RBP_REL_RBP_REl, {temp.substr(4), left.substr(4)}));
            break;
        case MODEQUAL :
            temp = controlFlowGraph->createNewTemp(expression->getType());
            controlFlowGraph->addIRInstr(IRInstr(BINARYOPERATION, {to_string(MOD), temp.substr(4), left.substr(4), right.substr(4)}));
            controlFlowGraph->addIRInstr(IRInstr(MOV_RBP_REL_RBP_REl, {temp.substr(4), left.substr(4)}));
            break;
    }

    return right;
}

void Affectation::print(std::ostream &stream) const
{
    if(VariableIndex *var= dynamic_cast<VariableIndex*>(variable))
    {
        stream << " Affectation: " << *var << " Operateur=" << operateur << " " << *expression << endl;
    }
    else
    {
        stream << " Affectation: " << *variable << " Operateur=" << operateur << " " << *expression << endl;
    }
}

std::ostream& operator<<(std::ostream& stream, const Affectation& affectation)
{
    stream << " Affectation: " << *affectation.variable << " Operateur=" << affectation.operateur;
    stream << " " << *affectation.expression<< endl;
    return stream;
}

Affectation &Affectation::operator=(const Affectation &unAffectation)
{
    //
}

void Affectation::resolveScopeVariables(std::vector<Declaration *> declProgramme, std::vector<Declaration *> paramFunction, std::vector<Declaration *> declBloc, std::vector<Function*> functionProgram)
{
    this->variable->resolveScopeVariables(declProgramme,paramFunction,declBloc, functionProgram);
    this->expression->resolveScopeVariables(declProgramme,paramFunction,declBloc, functionProgram);
}

void Affectation::resolveTypeExpr()
{
    this->expression->resolveTypeExpr();
    cout << this->expression->getType() << endl;
}

void Affectation::resolvedUnUsedFonctAndDecl(std::vector<std::string>* remainingFunctions, std::vector<std::string>* remainingDeclPrograme, std::vector<std::string>* remainingParam, std::vector<std::string>* remainingDeclBloc)
{
    this->expression->resolvedUnUsedFonctAndDecl(remainingFunctions,remainingDeclPrograme,remainingParam,remainingDeclBloc);
    this->variable->resolvedUnUsedFonctAndDecl(remainingFunctions,remainingDeclPrograme,remainingParam,remainingDeclBloc);
}

Affectation::Affectation(const Affectation &unAffectation)
{
    #ifdef MAP
        cout << "Appel au constructeur de copie de <Affectation>" << endl;
    #endif
}

Affectation::Affectation(Variable *variable, Operateur operateur, Expression *expression)
{
    #ifdef MAP
        cout << "Appel au constructeur de <Affectation>" << endl;
    #endif

    this->variable = variable;
    this->operateur = operateur;
    this->expression = expression;
}

Affectation::~Affectation()
{
    #ifdef MAP
        cout << "Appel au destructeur de <Affectation>" << endl;
    #endif
}
