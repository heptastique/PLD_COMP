#pragma once

#include "DeclarationTab.h"
#include "Variable.h"
#include <vector>

class InitialisationTab : public DeclarationTab {
    public:
        void generateIR(ControlFlowGraph * controlFlowGraph);

        void print(std::ostream& stream) const;

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
