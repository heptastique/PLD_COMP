using namespace std;

#include "Instruction.h"
#include <iostream>

std::ostream& operator<<(std::ostream& stream, const Instruction& instruction)
{
    return stream;
}

Instruction &Instruction::operator=(const Instruction &unInstruction)
{
}


Instruction::Instruction(const Instruction &unInstruction)
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Instruction>" << endl;
#endif
}


Instruction::Instruction()
{
#ifdef MAP
    cout << "Appel au constructeur de <Instruction>" << endl;
#endif
}


Instruction::~Instruction()
{
#ifdef MAP
    cout << "Appel au destructeur de <Instruction>" << endl;
#endif
}