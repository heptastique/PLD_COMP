#pragma once

#include "Type.h"
#include <string>
#include "Instruction.h"
# include "IRVariable.h"

class IRVariable;

class Declaration : public Instruction {

public:

	void generateIR(ControlFlowGraph * controlFlowGraph);

    void print(std::ostream& stream) const;

    friend std::ostream& operator<< (std::ostream& stream, const Declaration& declaration);

    Declaration &operator=(const Declaration &unDeclaration);

    void resolveScopeVariables(std::vector<Declaration*> declProgramme, std::vector<Declaration*> paramFunction, std::vector<Declaration*> declBloc, std::vector<Function*> functionProgram);

    void resolveTypeExpr();

	void setIRVariable(IRVariable);

	IRVariable getIRVariable();

    void setType(Type type);

    Type getType();

    std::string getName();

    Declaration();

    Declaration(const Declaration &unDeclaration);

    Declaration(std::string name, Type type);

    virtual ~Declaration();

protected:
    Type type;
    std::string name;
	IRVariable iRVariable;
};
