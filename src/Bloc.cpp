using namespace std;

#include "Bloc.h"
#include "ErrorHandling.h"
#include "WarningHandling.h"
#include "RetourFonction.h"
#include <iostream>

// Generate IR
void Bloc::generateIR(ControlFlowGraph * controlFlowGraph)
{
    // For each Declaration of Bloc
    for (auto instruction : instructions)
    {
        if (Declaration * declaration = dynamic_cast <Declaration *> (instruction))
        {
            declaration->generateIR(controlFlowGraph);
        }
    }

    // For each Instruction (non Declaration) of Bloc
    for (auto instruction : instructions)
    {
        if (Declaration * declaration = dynamic_cast <Declaration *> (instruction))
        {
            //
        }
        else
        {
            instruction->generateIR(controlFlowGraph);
        }
    }
}

ostream& operator<<(ostream& stream, const Bloc& bloc)
{
    stream << "     Bloc:" << endl;
    
    for (auto it :  bloc.instructions)
    {
        stream << "      " << *it;
    }
    
    stream << endl;
    
    return stream;
}

void Bloc::addInstructions(std::vector<Instruction*> instructions)
{
    for(auto inst : instructions)
    {
        this->instructions.emplace_back(inst);
        
        if(Declaration* declaration = dynamic_cast<Declaration*>(inst))
        {
            this->declarations.emplace_back(declaration);
        }
    }
}

void Bloc::addDeclarations(std::vector<Declaration*> declarations)
{
    for(auto decl : declarations)
    {
        this->declarations.emplace_back(decl);
    }
}

void Bloc::resolveScopeVariables(std::vector<Declaration*> declProgramme, std::vector<Declaration*> paramFunction, std::vector<Function*> functionProgram)
{
    vector<Declaration*>::iterator it;
    
    for(it = this->declarations.begin(); it!=this->declarations.end(); ++it)
    {
        auto it2 = it;
        ++it2;
        
        while(it2!= this->declarations.end())
        {
            Declaration * declaration = *it;
            Declaration * declaration2 = *it2;
            
            if ( declaration->getName().compare(declaration2->getName()) == 0)
            {
                ErrorHandling::ThrowError(101, declaration2->getName());
            }
            
            ++it2;
        }
    }

    for ( auto instruction : this->instructions)
    {
        instruction->resolveScopeVariables(declProgramme,paramFunction,this->declarations, functionProgram);
    }
}

void Bloc::resolveScopeVariables(std::vector<Declaration*> declProgramme, std::vector<Declaration*> paramFunction, std::vector<Declaration*> declBloc, std::vector<Function*> functionProgram)
{
    for ( auto instruction : this->instructions)
    {
        instruction->resolveScopeVariables(declProgramme,paramFunction,declBloc, functionProgram);
    }
}

void Bloc::resolveTypeExpr()
{
    for ( auto instruction : this->instructions)
    {
        instruction->resolveTypeExpr();
    }
}

void Bloc::resolvedUnUsedFonctAndDecl(std::vector<std::string>* remainingFunctions, std::vector<std::string>* remainingDeclPrograme, std::vector<std::string>* remainingParam)
{
    vector<string> remainingDeclBloc;
    vector<string> removeDeclParam;
    vector<string> removegDeclPrograme;
    for ( auto declaration : this->declarations)
    {
        remainingDeclBloc.push_back(declaration->getName());
    }
    // remove from param and global decl sharing the same name with local decl
    for ( auto declaration : remainingDeclBloc)
    {
        auto itparamfunction = remainingParam->begin();
        for (itparamfunction; itparamfunction != remainingParam->end(); itparamfunction++)
        {
            auto param = *itparamfunction;
            if(declaration.compare(param) == 0)
            {
                removeDeclParam.push_back(param);
                remainingParam->erase(itparamfunction);
                break;
            }
        }
        auto itdeclProg = remainingDeclPrograme->begin();
        for (itdeclProg; itdeclProg != remainingDeclPrograme->end(); itdeclProg++)
        {
            auto declProg = *itdeclProg;
            if(declaration.compare(declProg) == 0)
            {
                removegDeclPrograme.push_back(declProg);
                remainingDeclPrograme->erase(itdeclProg);
                break;
            }
        }
    }
    //same between param and global decl
    for ( auto declaration : *remainingParam)
    {
        auto itdeclProg = remainingDeclPrograme->begin();
        for (itdeclProg; itdeclProg != remainingDeclPrograme->end(); itdeclProg++)
        {
            auto declProg = *itdeclProg;
            if(declaration.compare(declProg) == 0)
            {
                removegDeclPrograme.push_back(declProg);
                remainingDeclPrograme->erase(itdeclProg);
            }
        }
    }
    for ( auto instruction: this->instructions)
    {
        instruction->resolvedUnUsedFonctAndDecl(remainingFunctions, remainingDeclPrograme, remainingParam, &remainingDeclBloc);
        for ( auto decl : remainingDeclBloc)
        {
            cout << "here " << decl  << endl;
        }
    }
    // then discarded are put back value since we leave the bloc
    for ( auto removedParam : removeDeclParam)
    {
        remainingParam->push_back(removedParam);
    }
    cout << " so we're here right ?" << endl;
    for ( auto removedDecl : removegDeclPrograme)
    {
        remainingDeclPrograme->push_back(removedDecl);
    }
    cout << " what's wrong ?" << endl;
    // then print unused local variables
    for ( auto decl : remainingDeclBloc)
    {
        cout << "here " << decl  << endl;
    }
    for ( auto decl : remainingDeclBloc)
    {
        cout << "here " << decl << " ?" << endl;
        WarningHandling::ThrowWarning(111,decl);
        cout << "after " << decl << " ?" << endl;
    }
    cout << "or here ?" << endl;
    // param also done there
    for ( auto param : *remainingParam)
    {
        WarningHandling::ThrowWarning(112,param);
    }
    cout << " now ?" << endl;
}

void Bloc::resolvedUnUsedFonctAndDecl(std::vector<std::string>* remainingFunctions, std::vector<std::string>* remainingDeclPrograme, std::vector<std::string>* remainingParam, std::vector<std::string>* remainingDeclBloc)
{
    for ( auto instruction: this->instructions)
    {
        instruction->resolvedUnUsedFonctAndDecl(remainingFunctions, remainingDeclPrograme, remainingParam, remainingDeclBloc);
    }
}

Bloc &Bloc::operator=(const Bloc &unBloc)
{
    //
}

std::vector<Instruction*> Bloc::getInstructions()
{
    return this->instructions;
}

std::vector<Declaration*> Bloc::getDeclarations()
{
    return this->declarations;
}

Bloc::Bloc(const Bloc &unBloc)
{
    #ifdef MAP
        cout << "Appel au constructeur de copie de <Bloc>" << endl;
    #endif
}

Bloc::Bloc()
{
    #ifdef MAP
        cout << "Appel au constructeur de <Bloc>" << endl;
    #endif
}

Bloc::~Bloc()
{
    #ifdef MAP
        cout << "Appel au destructeur de <Bloc>" << endl;
    #endif
}
