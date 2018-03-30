using namespace std;

#include "RetourFonction.h"
#include <iostream>



void RetourFonction::generateIR(ControlFlowGraph * controlFlowGraph){
	cout << "RetouFonction::generateIR" << endl;
	string retValue = createNewReg();
	list <string> params;
	
	params.push_back(retValue);
	params.push_back(expr);
	controlFlowGraph->addInstruction(IRInstr(FUNCTION_RETURN), params);
	
	return retValue;
	
	
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

RetourFonction &RetourFonction::operator=(const RetourFonction &unRetourFonction) {
}

void RetourFonction::resolveScopeVariables(std::list<Declaration*> declProgramme, std::list<Declaration*> paramFunction, std::list<Declaration*> declBloc, std::list<Function*> functionProgram){
    this->expression->resolveScopeVariables(declProgramme, paramFunction, declBloc, functionProgram);
}

void RetourFonction::resolveTypeExpr(){
    this->expression->resolveTypeExpr();
}

RetourFonction::RetourFonction(const RetourFonction &unRetourFonction) {
#ifdef MAP
    cout << "Appel au constructeur de copie de <RetourFonction>" << endl;
#endif
}


RetourFonction::RetourFonction(Expression* expression) {
    this->expression = expression;
#ifdef MAP
    cout << "Appel au constructeur de <RetourFonction>" << endl;
#endif
}


RetourFonction::~RetourFonction() {
#ifdef MAP
    cout << "Appel au destructeur de <RetourFonction>" << endl;
#endif
}
