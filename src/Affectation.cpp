using namespace std;

#include "Affectation.h"
#include "VariableIndex.h"
#include <iostream>

string Affectation::generateIR(ControlFlowGraph * controlFlowGraph)
{
    string right;

    // string left = controlFlowGraph->createNewVar();
    string left = "tmp";
    //int offset = controlFlowGraph->getOffsetFromSymbolTable(varName);
    int offset = 1;
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
	controlFlowGraph->addIRInstr(IRInstr(MEM_STORE, {var->getValeur(), to_string(variable->getDeclaration()->getIRVariable().getOffset())}));

	//cout << "MEM STORE " << to_string(variable->getDeclaration()->getIRVariable().getOffset()) << " " << var->getValeur() << endl;
    }
    else
    {
        //right = variable->generateIR(controlFlowGraph);
    }

	return right;
}

void Affectation::print(std::ostream &stream) const
{
    if(VariableIndex *var= dynamic_cast<VariableIndex*>(variable))
    {
        stream << " Affectation: " << *var << " Operateur=" << operateur << " " << *expression << endl;
    }else{
        stream << " Affectation: " << *variable << " Operateur=" << operateur << " " << *expression << endl;
    }
}

std::ostream& operator<<(std::ostream& stream, const Affectation& affectation)
{
    stream << " Affectation: " << *affectation.variable << " Operateur=" << affectation.operateur;
    stream << " " << *affectation.expression<< endl;
    return stream;
}

Affectation &Affectation::operator=(const Affectation &unAffectation) {
}

void Affectation::resolveScopeVariables(std::vector<Declaration *> declProgramme, std::vector<Declaration *> paramFunction, std::vector<Declaration *> declBloc, std::vector<Function*> functionProgram) {
    this->variable->resolveScopeVariables(declProgramme,paramFunction,declBloc, functionProgram);
    this->expression->resolveScopeVariables(declProgramme,paramFunction,declBloc, functionProgram);
}

void Affectation::resolveTypeExpr(){
    this->expression->resolveTypeExpr();
}

Affectation::Affectation(const Affectation &unAffectation) {
#ifdef MAP
    cout << "Appel au constructeur de copie de <Affectation>" << endl;
#endif
}

Affectation::Affectation(Variable *variable, Operateur operateur, Expression *expression) {
    this->variable = variable;
    this->operateur = operateur;
    this->expression = expression;
#ifdef MAP
    cout << "Appel au constructeur de <Affectation>" << endl;
#endif
}

Affectation::~Affectation() {
#ifdef MAP
    cout << "Appel au destructeur de <Affectation>" << endl;
#endif
}
