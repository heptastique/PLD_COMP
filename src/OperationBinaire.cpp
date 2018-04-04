using namespace std;

#include "OperationBinaire.h"
#include "IRInstr.h"
#include "Variable.h"
#include <iostream>

string OperationBinaire::generateIR(ControlFlowGraph *controlFlowGraph)
{
    if(Variable* variable1 = dynamic_cast<Variable*>(expressionL))
    {
        if(Variable* variable2 = dynamic_cast<Variable*>(expressionR))
        {
            if (variable1->getType() == ENTIER && variable2->getType() == ENTIER);
            string var1 = variable1->getValeur();
            string var2 = variable2->getValeur();

            string var3 = controlFlowGraph->createNewTemp();
            controlFlowGraph->addIRInstr(IRInstr(ADD, { var3, var1, var2}));
        }
    }


    //string var1 = expressionL->generateIR(controlFlowGraph);
    //string var2 = expressionR->generateIR(controlFlowGraph);



    return "nop";
}

void OperationBinaire::print(std::ostream &stream) const
{
    stream << " OperationBinaire: " << *expressionL << " Operateur=" << operateur << " " << *expressionR;
    stream << endl;
}

std::ostream& operator<<(std::ostream& stream, const OperationBinaire& operationBinaire)
{
    stream << " OperationBinaire: " << *operationBinaire.expressionL << " Operateur=" << operationBinaire.operateur;
    stream << " " << *operationBinaire.expressionR;
    stream << endl;
    
    return stream;
}

OperationBinaire &OperationBinaire::operator=(const OperationBinaire &unOperationBinaire)
{
    //
}

void OperationBinaire::resolveScopeVariables(std::vector<Declaration*> declProgramme, std::vector<Declaration*> paramFunction, std::vector<Declaration*> declBloc, std::vector<Function*> functionProgram)
{
    this->expressionL->resolveScopeVariables(declProgramme, paramFunction, declBloc, functionProgram);
    this->expressionR->resolveScopeVariables(declProgramme, paramFunction, declBloc, functionProgram);
}

void OperationBinaire::resolveTypeExpr()
{
    this->expressionL->resolveTypeExpr();
    this->expressionR->resolveTypeExpr();
    Type typeExprL = expressionL->getType();
    Type typeExprR = expressionL->getType();
    
    if ( typeExprL == INT64_T || typeExprR == INT64_T)
    {
        this->setType( INT64_T);
    }
    else
    {
        if ( typeExprL == INT32_T || typeExprL == CHAR)
        {
            this->setType( INT32_T);
        }
        else
        {
            cout << "error attributing type" << endl;
        }
    }
}

OperationBinaire::OperationBinaire(const OperationBinaire &unOperationBinaire)
{
    #ifdef MAP
        cout << "Appel au constructeur de copie de <OperationBinaire>" << endl;
    #endif
}

OperationBinaire::OperationBinaire(Expression* expressionL, Expression* expressionR, Operateur operateur)
{
    #ifdef MAP
        cout << "Appel au constructeur de <OperationBinaire>" << endl;
    #endif

    this->expressionL = expressionL;
    this->expressionR = expressionR;
    this->operateur = operateur;
}

OperationBinaire::~OperationBinaire()
{
    #ifdef MAP
        cout << "Appel au destructeur de <OperationBinaire>" << endl;
    #endif
}
