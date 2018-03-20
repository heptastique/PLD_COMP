using namespace std;

#include "Variable.h"
#include <iostream>

std::ostream& operator<<(std::ostream& stream, const Variable& variable)
{
    stream << " Variable";
    return stream;
}


Variable &Variable::operator=(const Variable &unVariable) {
}


Variable::Variable(const Variable &unVariable) {
#ifdef MAP
    cout << "Appel au constructeur de copie de <Variable>" << endl;
#endif
}


Variable::Variable() {
#ifdef MAP
    cout << "Appel au constructeur de <Variable>" << endl;
#endif
}


Variable::~Variable() {
#ifdef MAP
    cout << "Appel au destructeur de <Variable>" << endl;
#endif
}