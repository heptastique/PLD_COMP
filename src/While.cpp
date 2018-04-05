using namespace std;

#include <iostream>
#include "While.h"
#include "ControlFlowGraph.h"
#include "IRInstr.h"

string While::generateIR(ControlFlowGraph *controlFlowGraph)
{
    // Get label to use for this while
    int labelNextBlock = controlFlowGraph->getLastLabel();
    // Add instructions of condition
    condition->generateIR(controlFlowGraph);
    
    // Add instructions of block
    bloc->generateIR(controlFlowGraph);

    // Prepare label for next block
    controlFlowGraph->setLastLabel(labelNextBlock+1);
}

void While::print(std::ostream &stream) const
{
    stream << " While: Condition=" << *condition << *bloc << endl;
}

std::ostream& operator<<(std::ostream& stream, const While& aWhile)
{
    stream << " While: Condition=" << *aWhile.condition << *aWhile.bloc << endl;

    return stream;
}

While &While::operator=(const While &unWhile)
{
}

void While::resolveScopeVariables(std::vector<Declaration*> declProgramme, std::vector<Declaration*> paramFunction, std::vector<Declaration*> declBloc, std::vector<Function*> functionProgram)
{
    this->condition->resolveScopeVariables(declProgramme, paramFunction, declBloc, functionProgram);
    this->bloc->resolveScopeVariables(declProgramme, paramFunction, declBloc, functionProgram);
}

void While::resolveTypeExpr()
{
    this->bloc->resolveTypeExpr();
    this->condition->resolveTypeExpr();
}

While::While(const While &unWhile)
{
    #ifdef MAP
        cout << "Appel au constructeur de copie de <While>" << endl;
    #endif
}

While::While(Bloc* bloc, Expression* condition)
{
    #ifdef MAP
        cout << "Appel au constructeur de <While>" << endl;
    #endif
    this->bloc = bloc;
    this->condition = condition;
}

While::~While()
{
    #ifdef MAP
        cout << "Appel au destructeur de <While>" << endl;
    #endif
}
