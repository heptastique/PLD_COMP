using namespace std;

#include "If.h"
#include <iostream>

string If::generateIR(ControlFlowGraph * controlFlowGraph)
{
    cout << "If::generateIR" << endl;
    // Get label to use for this if-else
    int labelNextBlock = controlFlowGraph->getLastLabel();

    // Add instructions of condition
    string result = condition->generateIR(controlFlowGraph);
    // Add jump (jump if condition is false) to the next label (either else or afterif)
    // ex : .L2
    controlFlowGraph->addIRInstr(IRInstr(COMPJUMP,{to_string(labelNextBlock),result.substr(4)}));
    // Add instructions of the then part
    bloc->generateIR(controlFlowGraph);

    // If there is an else, generate basic block for else
    if(this->hasElse)
    {
        // Else is the next block
        labelNextBlock++; // Increase label
        // Instruction to jump from the then part to afterif
        // ex : .L3
        controlFlowGraph->addIRInstr(IRInstr(RETIF,{to_string(labelNextBlock)}));
        controlFlowGraph->newBasicBlock();
        anElse->generateIR(controlFlowGraph, labelNextBlock-1);
    }

    // After if
    controlFlowGraph->newBasicBlock();
    // ex : .L3 if there is a else, .L2 otherwise
    controlFlowGraph->addIRInstr(IRInstr(LABEL,{to_string(labelNextBlock)}));

    // Prepare label for next if
    // ex : .L4
    controlFlowGraph->setLastLabel(labelNextBlock+1);
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
