using namespace std;

#include "Else.h"
#include <iostream>

void Else::print(std::ostream &stream) const
{
    stream << "     Else: " << endl << *bloc << endl;
}

std::ostream& operator<<(std::ostream& stream, const Else& anElse)
{
    stream << "     Else: " << endl <<  *anElse.bloc << endl;
}

Else &Else::operator=(const Else &unElse) {
}

void Else::resolveScopeVariables(std::list<Declaration*> declProgramme, std::list<Declaration*> paramFunction, std::list<Declaration*> declBloc, std::list<Function*> functionProgram){
    this->bloc->resolveScopeVariables(declProgramme, paramFunction, declBloc, functionProgram);
}

void Else::resolveTypeExpr(){
    this->bloc->resolveTypeExpr();
}

Else::Else(const Else &unElse) {
#ifdef MAP
    cout << "Appel au constructeur de copie de <Else>" << endl;
#endif
}

Else::Else(Bloc* bloc) {
    this->bloc = bloc;
#ifdef MAP
    cout << "Appel au constructeur de <Else>" << endl;
#endif
}


Else::~Else() {
#ifdef MAP
    cout << "Appel au destructeur de <Else>" << endl;
#endif
}