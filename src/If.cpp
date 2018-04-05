using namespace std;

#include "If.h"
#include <iostream>

string If::generateIR(ControlFlowGraph * controlFlowGraph)
{
    string labelThen = to_string(controlFlowGraph->getLastLabel());
    controlFlowGraph->increaseLastLabel();
    string labelAfter = to_string(controlFlowGraph->getLastLabel());
    controlFlowGraph->increaseLastLabel();

    // Generation basic bloc for condition
    condition->generateIR(controlFlowGraph);
    controlFlowGraph->addIRInstr(IRInstr(COMPJUMP,{labelThen}));
    
    // If there is an else, generate basic block for else
    if(this->hasElse)
    {
        anElse->getBloc()->generateIR(controlFlowGraph);
    }
    controlFlowGraph->addIRInstr(IRInstr(RETIF,{labelAfter}));
    

    // Generate basic block for then
    controlFlowGraph->addIRInstr(IRInstr(LABEL,{labelThen}));
    controlFlowGraph->newBasicBlock();
    bloc->generateIR(controlFlowGraph);

    // After if
    controlFlowGraph->newBasicBlock();
    controlFlowGraph->addIRInstr(IRInstr(LABEL,{labelAfter}));
}

void If::print(std::ostream &stream) const
{
    stream << " If: Condition=" << *condition << *bloc;
    if(hasElse)
    {
        stream << *anElse << endl;
    }
}

std::ostream& operator<<(std::ostream& stream, const If& anIf)
{
    stream << " If: Condition=" << *anIf.condition << *anIf.bloc << endl;
    if(anIf.hasElse)
    {
        stream << *anIf.anElse << endl;
    }
    
    return stream;
}

void If::resolveScopeVariables(std::vector<Declaration*> declProgramme, std::vector<Declaration*> paramFunction, std::vector<Declaration*> declBloc, std::vector<Function*> functionProgram)
{
    this->condition->resolveScopeVariables(declProgramme, paramFunction, declBloc, functionProgram);
    this->bloc->resolveScopeVariables(declProgramme, paramFunction, declBloc, functionProgram);
    if(this->hasElse)
    {
        this->anElse->resolveScopeVariables(declProgramme, paramFunction, declBloc, functionProgram);
    }
}

void If::resolveTypeExpr()
{
    this->bloc->resolveTypeExpr();
    this->condition->resolveTypeExpr();
    if(this->hasElse)
    {
        this->anElse->resolveTypeExpr();
    }
}

void If::setElse(Else *anElse)
{
    this->anElse = anElse;
    this->hasElse = true;
}

If &If::operator=(const If &unIf)
{
}


If::If(const If &unIf)
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <If>" << endl;
#endif
}


If::If(Expression* condition, Bloc* bloc)
{
    this->condition = condition;
    this->bloc = bloc;
}

If::~If()
{
    #ifdef MAP
        cout << "Appel au destructeur de <If>" << endl;
    #endif
}
