using namespace std;

#include "For.h"
#include <iostream>

void For::print(std::ostream &stream) const
{
    stream << " For: Condition=" << *condition << *bloc << endl;
}

std::ostream& operator<<(std::ostream& stream, const For& aFor)
{
    stream << " For: Condition=" << *aFor.condition << *aFor.bloc << endl;
    return stream;
}

For &For::operator=(const For &unFor)
{
}

void For::resolveScopeVariables(std::vector<Declaration*> declProgramme, std::vector<Declaration*> paramFunction, std::vector<Declaration*> declBloc, std::vector<Function*> functionProgram)
{
    this->PartOne->resolveScopeVariables(declProgramme, paramFunction, declBloc, functionProgram);
    this->condition->resolveScopeVariables(declProgramme, paramFunction, declBloc, functionProgram);
    this->PartThree->resolveScopeVariables(declProgramme, paramFunction, declBloc, functionProgram);
    this->bloc->resolveScopeVariables(declProgramme, paramFunction, declBloc, functionProgram);
}

void For::resolveTypeExpr()
{
    this->bloc->resolveTypeExpr();
    this->PartOne->resolveTypeExpr();
    this->condition->resolveTypeExpr();
    this->PartThree->resolveTypeExpr();
}

For::For(const For &unFor)
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <For>" << endl;
#endif
}

For::For(Bloc* bloc, Expression* condition)
{
    this->bloc = bloc;
    this->condition = condition;
#ifdef MAP
    cout << "Appel au constructeur de <For>" << endl;
#endif
}

For::~For()
{
#ifdef MAP
    cout << "Appel au destructeur de <For>" << endl;
#endif
}