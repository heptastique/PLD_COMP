using namespace std;

# include "ControlFlowGraph.h"


void ControlFlowGraph::generateASM(std::ostream &os) const
{
	#ifdef MAP
		cout << "Appel a la methode generateASM <ControlFlowGraph>" << endl;
	#endif

	
	os << ".text\n";
	os << ".global main\n\n";

	os << "main:\n\n";

	os << "\tret\n\n";

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
