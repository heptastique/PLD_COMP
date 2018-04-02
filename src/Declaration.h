#pragma once

# include "Type.h"
# include "Instruction.h"
# include "IRVariable.h"

# include <string>

class IRVariable;

class Declaration : public Instruction 
{
    public:

        void generateIR(ControlFlowGraph * controlFlowGraph);

        void print(std::ostream& stream) const;

	std::string generateIR(ControlFlowGraph * controlFlowGraph);

        friend std::ostream& operator<< (std::ostream& stream, const Declaration& declaration);

        Declaration &operator=(const Declaration &unDeclaration);

        void resolveScopeVariables(std::vector<Declaration*> declProgramme, std::vector<Declaration*> paramFunction, std::vector<Declaration*> declBloc, std::vector<Function*> functionProgram);

        void resolveTypeExpr();

        void setType(Type type);

        Type getType();

        void setIRVariable(IRVariable);

        IRVariable getIRVariable();

        void setType(Type type);

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
