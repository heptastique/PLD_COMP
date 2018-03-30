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

void InitialisationTab::resolveScopeVariables(std::list<Declaration*> declProgramme, std::list<Declaration*> paramFunction, std::list<Declaration*> declBloc, std::list<Function*> functionProgram){
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

InitialisationTab::InitialisationTab(Type type,std::string name, std::list<Variable*> variables) {
    this->name = name;
    this->type = type;
    this->variables = variables;
    this->size = to_string(variables.size());
#ifdef MAP
    cout << "Appel au constructeur de <InitialisationTab>" << endl;
#endif
}


InitialisationTab::~InitialisationTab() {
#ifdef MAP
    cout << "Appel au destructeur de <InitialisationTab>" << endl;
#endif
}