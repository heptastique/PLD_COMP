using namespace std;

#include "VariableIndex.h"
#include <iostream>

void VariableIndex::generateIR(ControlFlowGraph * controlFlowGraph)
{
}

void VariableIndex::print(std::ostream &stream) const
{
    stream << " VariableIndex: " << "Type=" << typeVariable << " Valeur=" << valeur << " " << " Tab=" << *index ;
}

std::ostream& operator<<(std::ostream& stream, const VariableIndex& variableIndex)
{
    stream << " VariableIndex: " << "Type=" << variableIndex.typeVariable << " Valeur=" << variableIndex.valeur << " Tab=" << *variableIndex.index ;
    return stream;
}

void VariableIndex::resolveScopeVariables(std::vector<Declaration*> declProgramme, std::vector<Declaration*> paramFunction, std::vector<Declaration*> declBloc, std::vector<Function*> functionProgram)
{
    Variable::resolveScopeVariables(declProgramme, paramFunction, declBloc, functionProgram);
    this->index->resolveScopeVariables(declProgramme, paramFunction, declBloc, functionProgram);
}

void VariableIndex::resolveTypeExpr(){
    Variable::resolveTypeExpr();
    this->index->resolveTypeExpr();
}

VariableIndex &VariableIndex::operator=(const VariableIndex &unVariableIndex) {
}

VariableIndex::VariableIndex(TypeVariable typeVariable, std::string valeur, Expression* index): Variable(typeVariable, valeur) {
    this->index = index;
#ifdef MAP
    cout << "Appel au constructeur de <VariableIndex>" << endl;
#endif
}

VariableIndex::~VariableIndex() {
#ifdef MAP
    cout << "Appel au destructeur de <VariableIndex>" << endl;
#endif
}
