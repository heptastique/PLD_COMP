#pragma once

#include <ostream>
#include "Type.h"
#include "Expression.h"
#include "ControlFlowGraph.h"
#include "Declaration.h"

class Variable : public Expression 
{
    public:
        virtual std::string generateIR(ControlFlowGraph * controlFlowGraph);

        void print(std::ostream& stream) const;

        friend std::ostream& operator<< (std::ostream& stream, const Variable& variable);

        Declaration * getDeclaration();

        TypeVariable getType()
        {
            return typeVariable;
        }

        std::string getValeur()
        {
            return valeur;
        }

        Variable &operator=(const Variable &unVariable);

        void resolveScopeVariables(std::vector<Declaration*> declProgramme, std::vector<Declaration*> paramFunction, std::vector<Declaration*> declBloc, std::vector<Function*> functionProgram);

        void resolveTypeExpr();

        virtual void resolvedUnUsedFonctAndDecl(std::vector<std::string>* remainingFunctions, std::vector<std::string>* remainingDeclPrograme, std::vector<std::string>* remainingParam, std::vector<std::string>* remainingDeclBloc);

        Variable(const Variable &unVariable);

        Variable(TypeVariable typeVariable, std::string valeur);

        virtual ~Variable();

    protected:
        TypeVariable typeVariable;
        std::string valeur;
        Declaration * declarationAssociee = nullptr;
};
