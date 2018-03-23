using namespace std;

# include "ControlFlowGraph.h"

# include <iostream>
# include <fstream>

void ControlFlowGraph::generateASM()
{
	#ifdef MAP
		cout << "Appel a la methode generateASM <ControlFlowGraph>" << endl;
	#endif

	ofstream aSMFile;

	aSMFile.open("./target/prog.s");

	aSMFile << ".text\n";
	aSMFile << ".global main\n\n";

	aSMFile << "main:\n\n";

	aSMFile << "\tret\n\n";

	aSMFile.close();
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
