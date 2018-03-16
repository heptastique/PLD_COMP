using namespace std;

#include "Bloc.h"
#include <iostream>

ostream& operator<<(ostream& stream, const Bloc& bloc)
{
    for (auto it :  bloc.instructions){
        stream << *it;
    }
    stream << endl;
    return stream;
}

void Bloc::addInstruction(Instruction *instruction)
{
    this->instructions.emplace_back(instruction);
}

Bloc &Bloc::operator=(const Bloc &unBloc) {
}


Bloc::Bloc(const Bloc &unBloc) {
#ifdef MAP
    cout << "Appel au constructeur de copie de <Bloc>" << endl;
#endif
}


Bloc::Bloc() {
#ifdef MAP
    cout << "Appel au constructeur de <Bloc>" << endl;
#endif
}


Bloc::~Bloc() {
#ifdef MAP
    cout << "Appel au destructeur de <Bloc>" << endl;
#endif
}