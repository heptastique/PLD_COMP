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

void Bloc::addInstructions(std::list<Instruction*> instructions)
{
    for(auto inst : instructions){
        this->instructions.emplace_back(inst);
        if(Declaration* declaration = dynamic_cast<Declaration*>(inst))
        {
            this->declarations.emplace_back(declaration);
        }
    }
}

void Bloc::addDeclarations(std::list<Declaration*> declarations)
{
    for(auto decl : declarations)
    {
        this->declarations.emplace_back(decl);
    }
}

void Bloc::resolveScopeVariables(std::list<Declaration*> declProgramme, std::list<Declaration*> paramFunction, std::list<Function*> functionProgram){
    list<Declaration*>::iterator it;
    for(it = this->declarations.begin(); it!=this->declarations.end(); ++it){
        auto it2 = it;
        ++it2;
        while(it2!= this->declarations.end()){
            Declaration * declaration = *it;
            Declaration * declaration2 = *it2;
            if ( declaration->getName().compare(declaration2->getName()) == 0)
            {
                cout << "variable " << declaration2->getName() << " already exist inside this bloc" << endl;
            }
            ++it2;
        }
    }

    for ( auto instruction : this->instructions){
        instruction->resolveScopeVariables(declProgramme,paramFunction,this->declarations, functionProgram);
    }
}
void Bloc::resolveScopeVariables(std::list<Declaration*> declProgramme, std::list<Declaration*> paramFunction, std::list<Declaration*> declBloc, std::list<Function*> functionProgram){
    for ( auto instruction : this->instructions){
        instruction->resolveScopeVariables(declProgramme,paramFunction,declBloc, functionProgram);
    }
}

void Bloc::resolveTypeExpr(){
    for ( auto instruction : this->instructions){
        instruction->resolveTypeExpr();
    }
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
