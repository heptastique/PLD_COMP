using namespace std;

# include "IR.h"
# include <iostream>

void IR::generateASM(ostream & os) const
{
	for (auto controlFlowGraph : controlFlowGraphs)
	{
		controlFlowGraph.generateASM(os);
	}
}

void IR::addControlFlowGraph(ControlFlowGraph controlFlowGraph)
{
	controlFlowGraphs.push_back(controlFlowGraph);
}

vector <ControlFlowGraph> IR::getControlFlowGraphs() const
{
	return controlFlowGraphs;
}

IR::IR()
{
	#ifdef MAP
		cout << "Appel au constructeur de <IR>" << endl;
	#endif
}

IR::IR(const IR & iR)
{
	#ifdef MAP
		cout << "Appel au constructeur de copie de <IR>" << endl;
	#endif

	controlFlowGraphs = iR.controlFlowGraphs;
}

IR::IR(vector <ControlFlowGraph> controlFlowGraphs)
{
	#ifdef MAP
		cout << "Appel au constructeur de <IR>" << endl;
	#endif

	this->controlFlowGraphs = controlFlowGraphs;
}

IR::~IR()
{
	#ifdef MAP
		cout << "Appel au destructeur de <IR>" << endl;
	#endif
}
