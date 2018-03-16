using namespace std;

#include "Instruction.h"
#include <iostream>

Instruction &Instruction::operator=(const Instruction &unInstruction) {
}


Instruction::Instruction(const Instruction &unInstruction) {
#ifdef MAP
    cout << "Appel au constructeur de copie de <Instruction>" << endl;
#endif
}


Instruction::Instruction() {
#ifdef MAP
    cout << "Appel au constructeur de <Instruction>" << endl;
#endif
}


Instruction::~Instruction() {
#ifdef MAP
    cout << "Appel au destructeur de <Instruction>" << endl;
#endif
}