using namespace std;

#include "Affectation.h"
#include "VariableIndex.h"
#include "OperationBinaire.h"
#include <iostream>
#include <typeinfo>

string Affectation::generateIR(ControlFlowGraph * controlFlowGraph)
{
    string right = "ok";

    // string left = controlFlowGraph->createNewVar();
    string left = "tmp";
    //int offset = controlFlowGraph->getOffsetFromSymbolTable(varName);
    //int offset = 1;
    //controlFlowGraph->addIRInstr(IRInstr(REG_STORE, { left, to_string(offset)}));
    //controlFlowGraph->addIRInstr(IRInstr(ADD, { left, !bp, left}));

    // If the expression is a Rvalue

    if(Variable* var = dynamic_cast<Variable*>(expression))
    {
        /*
        if(var->getType() == NAME)
        {
            right = var->getValeur();
        }
        else
        {
            right = var->generateIR(controlFlowGraph);
        }
        */
        if (VariableIndex * varIndex = dynamic_cast<VariableIndex*>(variable))
        {
            return "nop";
        }

        // IRVariable iRVariable = controlFlowGraph->getVariable("VAR." + variable->getValeur());

        switch (var->getType())
        {
            case ENTIER :
            {
                controlFlowGraph->addIRInstr(IRInstr(STORE_RBP_REL, {var->getValeur(), to_string(variable->getDeclaration()->getOffset())}));

                break;
            }
            case CARACTERE :
            {
                controlFlowGraph->addIRInstr(IRInstr(STORE_RBP_REL, {to_string((int)(var->getValeur())[1]), to_string(variable->getDeclaration()->getOffset())}));

                break;
            }
            case NAME :
            {
                break;
            }
        }
    }
    else
    {
        if(OperationBinaire* operationBinaire = dynamic_cast<OperationBinaire*> (expression))
        {
            right = operationBinaire->generateIR(controlFlowGraph);
            controlFlowGraph->addIRInstr(IRInstr(AFFECTATION, {controlFlowGraph->getOffset(right), to_string(variable->getDeclaration()->getOffset())}));
        }
    }

    return "";
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
