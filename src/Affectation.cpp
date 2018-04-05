using namespace std;

#include "Affectation.h"
#include "VariableIndex.h"
#include "OperationBinaire.h"
#include "AppelFunction.h"
#include <iostream>
#include <typeinfo>

string Affectation::generateIR(ControlFlowGraph * controlFlowGraph)
{
    string right = "";
    
    if (AppelFunction * appelFunction = dynamic_cast <AppelFunction *> (expression))
    {
        appelFunction->generateIR(controlFlowGraph);
        string left = variable->generateIR(controlFlowGraph);
        controlFlowGraph->addIRInstr(IRInstr(MOV_REG_RBP_REL, {"rax", left.substr(4)}));
    }
    else
    {
        right = expression->generateIR(controlFlowGraph);
        string left = variable->generateIR(controlFlowGraph);
        controlFlowGraph->addIRInstr(IRInstr(AFFECTATION, {right.substr(4), left.substr(4)}));
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
