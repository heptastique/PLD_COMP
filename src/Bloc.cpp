using namespace std;

#include "Bloc.h"
#include <iostream>

// Generate IR
void Bloc::generateIR(ControlFlowGraph * controlFlowGraph)
{
	// For each Instruction of Bloc
	for (auto instruction : instructions)
	{
		// Generate IR for Instruction
		instruction->generateIR(controlFlowGraph);
	}
}

ostream& operator<<(ostream& stream, const Bloc& bloc)
{
    stream << "     Bloc:" << endl;
    for (auto it :  bloc.instructions){
        stream << "      " << *it;
    }
    stream << endl;
    return stream;
}

void Bloc::addInstruction(Instruction *instruction)
{
    this->instructions.emplace_back(instruction);
    if(Declaration* declaration = dynamic_cast<Declaration*>(instruction))
    {
        addDeclaration(declaration);
    }
}

void Bloc::addDeclaration(Declaration *declaration)
{
    this->declarations.emplace_back(declaration);
}

void Bloc::resolveScopeVariables(std::list<Declaration*> declProgramme, std::list<Declaration*> paramFunction){

}

Bloc &Bloc::operator=(const Bloc &unBloc) {
}

std::list<Instruction*> Bloc::getInstructions()
{
    return this->instructions;
}

std::list<Declaration*> Bloc::getDeclarations()
{
    return this->declarations;
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
