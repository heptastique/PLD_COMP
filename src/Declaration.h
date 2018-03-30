#pragma once

#include "Type.h"
//# include "ControlFlowGraph.h"

#include <string>
#include "Instruction.h"

//class ControlFlowGraph;

class Declaration : public Instruction {

public:

	void generateIR(ControlFlowGraph * controlFlowGraph);

    void print(std::ostream& stream) const;

    friend std::ostream& operator<< (std::ostream& stream, const Declaration& declaration);

    Declaration &operator=(const Declaration &unDeclaration);

    void resolveScopeVariables(std::list<Declaration*> declProgramme, std::list<Declaration*> paramFunction, std::list<Declaration*> declBloc, std::list<Function*> functionProgram);

    void resolveTypeExpr();

    void setType(Type type);

    Type getType();

    std::string getName();

    Declaration(const Declaration &unDeclaration);

    Declaration(std::string name, Type type);

    virtual ~Declaration();

protected:
    Type type;
    std::string name;
};
