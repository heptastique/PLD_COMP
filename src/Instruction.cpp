using namespace std;

#include "Instruction.h"
#include <iostream>

std::ostream& operator<<(std::ostream& stream, const Instruction& instruction)
{
    stream << "Instruction:";
    instruction.print(stream);
    return stream;
}

Instruction &Instruction::operator=(const Instruction &unInstruction)
{
    //
}

void Instruction::resolvedUnUsedFonctAndDecl(std::vector<std::string>* remainingFunctions std::vector<std::string>* remainingDeclPrograme, std::vector<std::string>* remainingParam, vector<string>* remainingDeclBloc)
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
