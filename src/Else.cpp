using namespace std;

#include "Else.h"
#include <iostream>

string Else::generateIR(ControlFlowGraph * controlFlowGraph, int label)
{
    // Generate else basic block
    controlFlowGraph->newBasicBlock();
    controlFlowGraph->addIRInstr(IRInstr(LABEL,{to_string(label)}));
    bloc->generateIR(controlFlowGraph);

    return "";
}

void Else::print(std::ostream &stream) const
{
    stream << "     Else: " << endl << *bloc << endl;
}

std::ostream& operator<<(std::ostream& stream, const Else& anElse)
{
    stream << "     Else: " << endl <<  *anElse.bloc << endl;
}

Else &Else::operator=(const Else &unElse)
{
    //
}

void Else::resolveScopeVariables(std::vector<Declaration*> declProgramme, std::vector<Declaration*> paramFunction, std::vector<Declaration*> declBloc, std::vector<Function*> functionProgram)
{
    this->bloc->resolveScopeVariables(declProgramme, paramFunction, declBloc, functionProgram);
}

void Else::resolveTypeExpr()
{
    this->bloc->resolveTypeExpr();
}

Else::Else(const Else &unElse)
{
    #ifdef MAP
        cout << "Appel au constructeur de copie de <Else>" << endl;
    #endif
}

Else::Else(Bloc* bloc)
{
    #ifdef MAP
        cout << "Appel au constructeur de <Else>" << endl;
    #endif

    this->bloc = bloc;
}

Else::~Else()
{
    #ifdef MAP
        cout << "Appel au destructeur de <Else>" << endl;
    #endif
}
