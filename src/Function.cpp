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

	// Add Function Definition to Prolog BasicBlock
	prologBasicBlock.addFunctionDefinition(this->name, 32);

	// Add Prolog BasicBlock to Function ControlFlowGraph
	controlFlowGraph.addBasicBlock(prologBasicBlock);

	return controlFlowGraph;
}

ostream & operator<<(ostream & stream, const Function & function)
{
	stream << " Fonction: Name=" << function.name << " TypeRetour=" << function.typeRetour << endl;

	if (!function.declarations.empty())
	{
		stream << " Param:" << endl;

		for (auto declaration : function.declarations)
		{
			stream << " " << *declaration;
	}
	}

	stream << *function.bloc;

	return stream;
}

Function & Function::operator=(const Function & function)
{

}

void Function::setDeclarations(list <Declaration*> declarations)
{
	this->declarations = declarations;
}

string Function::getName()
{
	return this->name;
}

Bloc * Function::getBloc()
{
	return this->bloc;
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
