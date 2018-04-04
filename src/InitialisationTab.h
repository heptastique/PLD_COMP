# pragma once

#include "DeclarationTab.h"
#include "Variable.h"
#include <vector>
#include <iostream>

using namespace std;

class InitialisationTab : public DeclarationTab
{
    public:
        string generateIR(ControlFlowGraph * controlFlowGraph);

        void print(ostream & stream) const;

        friend ostream& operator<< (std::ostream& stream, const InitialisationTab& initialisationTab);

        void resolveScopeVariables(std::vector<Declaration*> declProgramme, std::vector<Declaration*> paramFunction, std::vector<Declaration*> declBloc, std::vector<Function*> functionProgram);

        void resolveTypeExpr();

        InitialisationTab &operator=(const InitialisationTab &unInitialisationTab);

        InitialisationTab(Type type, string name, vector <Variable*> variables);

        virtual ~InitialisationTab();

    private:
        // There could be no size
        vector <Variable*> variables;
};
