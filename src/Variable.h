#pragma once

#include <ostream>
#include "Type.h"
#include "Expression.h"
#include "Declaration.h"

class Variable : public Expression {
public:
    void print(std::ostream& stream) const;

    friend std::ostream& operator<< (std::ostream& stream, const Variable& variable);

    Variable &operator=(const Variable &unVariable);

    void resolveScopeVariables(std::list<Declaration*> declProgramme, std::list<Declaration*> paramFunction, std::list<Declaration*> declBloc, std::list<Function*> functionProgram);

    void resolveTypeExpr();

    Variable(const Variable &unVariable);

    Variable(TypeVariable typeVariable, std::string valeur);

    virtual ~Variable();

private:
    TypeVariable typeVariable;
    std::string valeur;
    Declaration * declarationAssociee;
};
