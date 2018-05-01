#pragma once

#include "Type.h"
#include "Instruction.h"
#include "IRVariable.h"

#include <string>

class IRVariable;

class Declaration : public Instruction
{
    public:
        void print(std::ostream& stream) const;

        std::string generateIR(ControlFlowGraph * controlFlowGraph);

        friend std::ostream& operator<< (std::ostream& stream, const Declaration& declaration);

        Declaration &operator=(const Declaration &unDeclaration);

        void resolveScopeVariables(std::vector<Declaration*> declProgramme, std::vector<Declaration*> paramFunction, std::vector<Declaration*> declBloc, std::vector<Function*> functionProgram);

        void resolveTypeExpr();

        virtual void resolvedUnUsedFonctAndDecl(std::vector<std::string>* remainingFunctions, std::vector<std::string>* remainingDeclPrograme, std::vector<std::string>* remainingParam, std::vector<std::string>* remainingDeclBloc);

        void setType(Type type);

        Type getType();

        void setOffset(int offset);

        int getOffset();

        //void setIRVariable(IRVariable);

        //IRVariable getIRVariable();

        void setName(std::string name)
        {
            this->name = name;
        };

        std::string getName();

        Declaration();

        Declaration(const Declaration &unDeclaration);

        Declaration(std::string name, Type type);

        virtual ~Declaration();

    protected:
        Type type;

        std::string name;

        //IRVariable iRVariable;
        int offset = 999;
};
