using namespace std;

# include "ControlFlowGraph.h"
# include <iostream>

void ControlFlowGraph::visit()
{
	#ifdef MAP
		cout << "Appel a la methode visit <ControlFlowGraph>" << endl;
	#endif
	
	for (auto i : this->prog->getDeclarations())
	{
		cout << *i << endl;
	}
}

ControlFlowGraph::ControlFlowGraph(const ControlFlowGraph &controlFlowGraph)
{
	#ifdef MAP
		cout << "Appel au constructeur de copie de <ControlFlowGraph>" << endl;
	#endif
}

ControlFlowGraph::ControlFlowGraph()
{
	#ifdef MAP
		cout << "Appel au constructeur de <ControlFlowGraph>" << endl;
	#endif
}

ControlFlowGraph::ControlFlowGraph(Programme * prog)
{
	#ifdef MAP
		cout << "Appel au constructeur de <ControlFlowGraph>" << endl;
	#endif
	
	this->prog = prog;
}

ControlFlowGraph::~ControlFlowGraph()
{
	#ifdef MAP
		cout << "Appel au destructeur de <ControlFlowGraph>" << endl;
	#endif
}
