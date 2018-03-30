using namespace std;

# include "Function.h"
# include "BasicBlock.h"
#include "DeclarationTab.h"

# include <iostream>

// Generate IR
ControlFlowGraph Function::generateIR()
{
	// Create Function ControlFlowGraph
	ControlFlowGraph controlFlowGraph;

	// Create Prolog BasicBlock
	BasicBlock prologBasicBlock;

	// Calculate Address Range Size
	int addressRangeSize = calculateAddressRangeSize();

	// Add Function Definition to Prolog BasicBlock
	prologBasicBlock.addFunctionDefinition(name, addressRangeSize);

	// Add Prolog BasicBlock to Function ControlFlowGraph
	controlFlowGraph.addBasicBlock(prologBasicBlock);

	// Generate IR for Body
	bloc->generateIR(&controlFlowGraph);

	// Create Epilog BasicBlock
	//BasicBlock epilogBasicBlock;

	// Add Function Return to Function ControlFlowGraph
	//epilogBasicBlock.addFunctionReturn();

	// Add Epilog BasicBlock to Function ControlFlowGraph
	//controlFlowGraph.addBasicBlock(epilogBasicBlock);


	return controlFlowGraph;
}

int Function::calculateAddressRangeSize()
{

	int taille = 0;

	for(auto declaration : bloc->getDeclarations())
	{
		if(declaration->getType() == INT32_T || declaration->getType() == CHAR)
		{
			taille += 8;
		}
		else if(declaration->getType() == INT64_T)
		{
			taille += 16;
		}
	}

	return taille;
}

ostream & operator<<(ostream & stream, const Function & function)
{
    stream << " Fonction: Name=" << function.name << " TypeRetour=" << function.typeRetour << endl;
    if(!function.parameters.empty()){
        stream << "     Param:" << endl;
        for (auto it : function.parameters){
			if(DeclarationTab *decla = dynamic_cast<DeclarationTab*>(it))
			{
				stream << "     " << *decla;
			} else
			{
				stream << "     " << *it;
			}
        }
    }

	stream << *function.bloc;

	return stream;
}

Function & Function::operator=(const Function & function)
{

}

string Function::getName()
{
	return this->name;
}

Bloc * Function::getBloc()
{
	return this->bloc;
}

Type Function::getTypeRetour (){
    return this->typeRetour;
}

void Function::setParameters(std::list<Declaration*> parameters)
{
    this->parameters = parameters;
}

std::list<Declaration*> Function::getParameters()
{
    return this->parameters;
}

void Function::resolveScopeVariables(std::list<Declaration*> declProgramme, std::list<Function*> functionProgram)
{
	list<Declaration*>::iterator it;
	for(it = this->parameters.begin(); it!=this->parameters.end(); ++it){
        auto it2 = it;
        ++it2;
        while(it2!= this->parameters.end()) {
            Declaration *parameters = *it;
            Declaration *parameters2 = *it2;
            if (parameters->getName().compare(parameters2->getName()) == 0) {
                cout << "variable " << parameters2->getName() << " already exist in functions parameters" << endl;
            }
            ++it2;
        }
	}
	this->bloc->resolveScopeVariables(declProgramme, this->getParameters(), functionProgram);
}

void Function::resolveTypeExpr(){
    this->bloc->resolveTypeExpr();
}

Function::Function(const Function & function)
{
	#ifdef MAP
		cout << "Appel au constructeur de copie de <Function>" << endl;
	#endif
}

Function::Function(string name, Bloc * bloc, Type typeRetour)
{
	#ifdef MAP
		cout << "Appel au constructeur de <Function>" << endl;
	#endif

	this->name = name;
	this->bloc = bloc;
	this->typeRetour = typeRetour;
}


Function::~Function()
{
	#ifdef MAP
		cout << "Appel au destructeur de <Function>" << endl;
	#endif
}
