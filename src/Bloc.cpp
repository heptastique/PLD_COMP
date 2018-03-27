using namespace std;

#include "Bloc.h"
#include <iostream>


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