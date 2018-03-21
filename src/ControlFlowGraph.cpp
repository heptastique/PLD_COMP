using namespace std;

# include "ControlFlowGraph.h"
# include <iostream>

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

ControlFlowGraph::~ControlFlowGraph()
{
	#ifdef MAP
		cout << "Appel au destructeur de <ControlFlowGraph>" << endl;
	#endif
}
