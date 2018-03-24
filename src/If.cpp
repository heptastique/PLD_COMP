using namespace std;

#include "If.h"
#include <iostream>

void If::print(std::ostream &stream) const
{
    stream << " If: Condition=" << *condition << *bloc;
    if(hasElse){
        stream << *anElse << endl;
    }
}

std::ostream& operator<<(std::ostream& stream, const If& anIf)
{
    stream << " If: Condition=" << *anIf.condition << *anIf.bloc << endl;
    if(anIf.hasElse){
        stream << *anIf.anElse << endl;
    }
    return stream;
}

void If::setElse(Else *anElse) {
    this->anElse = anElse;
    this->hasElse = true;
}

If &If::operator=(const If &unIf) {
}


If::If(const If &unIf) {
#ifdef MAP
    cout << "Appel au constructeur de copie de <If>" << endl;
#endif
}


If::If(Expression* condition, Bloc* bloc) {
    this->condition = condition;
    this->bloc = bloc;
#ifdef MAP
    cout << "Appel au constructeur de <If>" << endl;
#endif
}


If::~If() {
#ifdef MAP
    cout << "Appel au destructeur de <If>" << endl;
#endif
}