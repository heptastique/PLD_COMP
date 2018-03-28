using namespace std;

# include "Function.h"
# include "BasicBlock.h"

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

	// Create Body BasicBlock
	BasicBlock bodyBasicBlock;

	bloc->generateIR(&controlFlowGraph);

	// Add Body BasicBlock to Function ControlFlowGraph
	controlFlowGraph.addBasicBlock(bodyBasicBlock);

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
            stream << "     " << *it;
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

void Function::setParameters(list<Declaration*> parameters)
{
    this->parameters = parameters;
}

std::list<Declaration*> Function::getParameters()
{
    return this->parameters;
}

void Function::resolveScopeVariables(std::list<Declaration*> declProgramme)
{
    this->bloc->resolveScopeVariables(declProgramme, this->getParameters());
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
