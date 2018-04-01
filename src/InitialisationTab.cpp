using namespace std;

#include "InitialisationTab.h"
#include <iostream>

void InitialisationTab::generateIR(ControlFlowGraph * controlFlowGraph)
{
}

void InitialisationTab::print(std::ostream &stream) const
{
    stream << " InitialisationTab: Type=" << type << " Name=" << name << " Size=" << size;
    for(auto var : variables){
        stream << *var;
    }
}

std::ostream& operator<<(std::ostream& stream, const InitialisationTab& initialisationTab)
{
    stream << " InitialisationTab: Type=" << initialisationTab.type << " Name=" << initialisationTab.name;
    stream << " Size=" << initialisationTab.size;
    for(auto var : initialisationTab.variables){
        stream << *var;
    }
    return stream;
}

void InitialisationTab::resolveScopeVariables(std::vector<Declaration*> declProgramme, std::vector<Declaration*> paramFunction, std::vector<Declaration*> declBloc, std::vector<Function*> functionProgram){
    for(auto var : this->variables){
        var->resolveScopeVariables(declProgramme, paramFunction, declBloc, functionProgram);
    }
}

void InitialisationTab::resolveTypeExpr(){
    for(auto var : this->variables) {
        var->resolveTypeExpr();
    }
}

InitialisationTab &InitialisationTab::operator=(const InitialisationTab &unInitialisationTab) {
}

InitialisationTab::InitialisationTab(Type type,std::string name, std::vector<Variable*> variables) : DeclarationTab(name,type,to_string(variables.size())) {
    this->variables = variables;
#ifdef MAP
    cout << "Appel au constructeur de <InitialisationTab>" << endl;
#endif
}

InitialisationTab::~InitialisationTab() {
#ifdef MAP
    cout << "Appel au destructeur de <InitialisationTab>" << endl;
#endif
}
