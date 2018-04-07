using namespace std;

#include "RetourFonction.h"
#include <iostream>

std::string RetourFonction::generateIR(ControlFlowGraph * controlFlowGraph)
{
    string var = expression->generateIR(controlFlowGraph);

    controlFlowGraph->addIRInstr(IRInstr(MOV_RBP_REL_REG, {var.substr(4), "rax"}));

    controlFlowGraph->addIRInstr(IRInstr(RET, {to_string(controlFlowGraph->getAddressRangeSize())}));

    return "RetourFonction";
}

void RetourFonction::print(std::ostream &stream) const
{
    stream << " RetourFonction: " << *expression;
    stream << endl;
}

std::ostream& operator<<(std::ostream& stream, const RetourFonction& retourFonction)
{
    stream << " RetourFonction: " << *retourFonction.expression;
    stream << endl;
    
    return stream;
}

RetourFonction &RetourFonction::operator=(const RetourFonction &unRetourFonction)
{
}

void RetourFonction::resolveScopeVariables(std::vector<Declaration*> declProgramme, std::vector<Declaration*> paramFunction, std::vector<Declaration*> declBloc, std::vector<Function*> functionProgram)
{
    this->expression->resolveScopeVariables(declProgramme, paramFunction, declBloc, functionProgram);
}

void RetourFonction::resolveTypeExpr()
{
    this->expression->resolveTypeExpr();
}

RetourFonction::RetourFonction(const RetourFonction &unRetourFonction)
{
    #ifdef MAP
        cout << "Appel au constructeur de copie de <RetourFonction>" << endl;
    #endif
}

RetourFonction::RetourFonction(Expression* expression)
{
    #ifdef MAP
        cout << "Appel au constructeur de <RetourFonction>" << endl;
    #endif

    this->expression = expression;
}

RetourFonction::~RetourFonction()
{
    #ifdef MAP
        cout << "Appel au destructeur de <RetourFonction>" << endl;
    #endif
}
