using namespace std;

# include "Programme.h"

# include <iostream>

// Generate IR
IR Programme::generateIR()
{
	// Create IR
	IR iR;

	// Create Control Flow Graph
	ControlFlowGraph controlFlowGraph;

	// For each Function of Program
	for (auto function : functions)
	{
		// Generate Function Control Flow Graph
		controlFlowGraph = function->generateIR();

		// Add Function Control Flow Graph to IR
		iR.addControlFlowGraph(controlFlowGraph);
	}

	return iR;
}

ostream & operator<<(ostream & stream, const Programme & programme)
{
	stream << "Programme:" << endl;

	for (auto declaration :  programme.declarations)
	{
		stream << *declaration;
	}

	for (auto function :  programme.functions)
	{
		stream << *function;
	}

	stream << endl;

	return stream;
}

void Programme::addFunction(Function *function)
{
	this->functions.emplace_back(function);
}

void Programme::addDeclarations(list<Declaration*> declarations)
{
	for(auto decl : declarations){
		this->declarations.emplace_back(decl);
	}

}

list <Function*> Programme::getFunctions()
{
	return this->functions;
}

list <Declaration*> Programme::getDeclarations()
{
	return this->declarations;
}

void Programme::resolveScopeVariables()
{
    for (auto it :  this->functions){
        it->resolveScopeVariables(this->getDeclarations());
    }
}

Programme & Programme::operator=(const Programme & programme)
{

}

Programme::Programme(const Programme & programme)
{
	#ifdef MAP
		cout << "Appel au constructeur de copie de <Programme>" << endl;
	#endif
}

Programme::Programme()
{
	#ifdef MAP
		cout << "Appel au constructeur de <Programme>" << endl;
	#endif
}

Programme::~Programme()
{
	#ifdef MAP
		cout << "Appel au destructeur de <Programme>" << endl;
	#endif
}
