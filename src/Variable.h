#pragma once

#include <ostream>
#include "Type.h"
#include "Expression.h"
# include "ControlFlowGraph.h"
#include "Declaration.h"

class Variable : public Expression {
    public:
        virtual void generateIR(ControlFlowGraph * controlFlowGraph);

        void print(std::ostream& stream) const;

        friend std::ostream& operator<< (std::ostream& stream, const Variable& variable);

        TypeVariable getType(){
            return typeVariable;
        }

        std::string getValeur(){
            return valeur;
        }

        Variable &operator=(const Variable &unVariable);

        void resolveScopeVariables(std::vector<Declaration*> declProgramme, std::vector<Declaration*> paramFunction, std::vector<Declaration*> declBloc, std::vector<Function*> functionProgram);

        void resolveTypeExpr();

        Variable(const Variable &unVariable);

        Variable(TypeVariable typeVariable, std::string valeur);

        virtual ~Variable();

    protected:
        TypeVariable typeVariable;
        std::string valeur;
        Declaration * declarationAssociee = nullptr;
};
