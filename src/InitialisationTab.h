#pragma once


#include "Initialisation.h"
#include "Variable.h"
#include <vector>

class InitialisationTab : public Instruction {

public:

    void generateIR(ControlFlowGraph * controlFlowGraph);

    void print(std::ostream& stream) const;

    friend std::ostream& operator<< (std::ostream& stream, const InitialisationTab& initialisationTab);

    void setSize(std::string size){
        this->size = size;
    }

    void resolveScopeVariables(std::vector<Declaration*> declProgramme, std::vector<Declaration*> paramFunction, std::vector<Declaration*> declBloc, std::vector<Function*> functionProgram);

    void resolveTypeExpr();

    void setType(Type type){
        this->type = type;
    }

    InitialisationTab &operator=(const InitialisationTab &unInitialisationTab);

    InitialisationTab(Type type, std::string name, std::vector<Variable*> variables);

    virtual ~InitialisationTab();

private:

    // There could be no size
    std::string size;
    std::vector<Variable*> variables;
    std::string name;
    Type type;
};
