using namespace std;

#include "While.h"
#include <iostream>

void While::print(std::ostream &stream) const
{
    stream << " While: Condition=" << *condition << *bloc << endl;
}

std::ostream& operator<<(std::ostream& stream, const While& aWhile)
{
    stream << " While: Condition=" << *aWhile.condition << *aWhile.bloc << endl;
    return stream;
}

While &While::operator=(const While &unWhile) {
}

void While::resolveScopeVariables(std::list<Declaration*> declProgramme, std::list<Declaration*> paramFunction, std::list<Declaration*> declBloc){
    this->condition->resolveScopeVariables(declProgramme, paramFunction, declBloc);
    this->bloc->resolveScopeVariables(declProgramme, paramFunction, declBloc);
}

While::While(const While &unWhile) {
#ifdef MAP
    cout << "Appel au constructeur de copie de <While>" << endl;
#endif
}


While::While(Bloc* bloc, Expression* condition) {
    this->bloc = bloc;
    this->condition = condition;
#ifdef MAP
    cout << "Appel au constructeur de <While>" << endl;
#endif
}


While::~While() {
#ifdef MAP
    cout << "Appel au destructeur de <While>" << endl;
#endif
}