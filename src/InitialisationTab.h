#pragma once

#include "DeclarationTab.h"
#include "Variable.h"
#include <vector>

class InitialisationTab : public DeclarationTab
{
    public:

        std::string generateIR(ControlFlowGraph * controlFlowGraph);

        friend std::ostream& operator<< (std::ostream& stream, const InitialisationTab& initialisationTab);

        void resolveScopeVariables(std::vector<Declaration*> declProgramme, std::vector<Declaration*> paramFunction, std::vector<Declaration*> declBloc, std::vector<Function*> functionProgram);

        void resolveTypeExpr();

        InitialisationTab &operator=(const InitialisationTab &unInitialisationTab);

        InitialisationTab(Type type, std::string name, std::vector<Variable*> variables);

        virtual ~InitialisationTab();

    private:

        // There could be no size
        std::vector<Variable*> variables;
};
