using namespace std;

# include "ControlFlowGraph.h"

void ControlFlowGraph::generateProlog(ostream &os, int addressRangeSize) const
{
	#ifdef MAP
		cout << "Appel a la methode ControlFlowGraph::generateProlog" << endl;
	#endif

	os << "pusq\t%rbp\n";
	os << "movq\t%rsp, %rbp\n";
	os << "subq\t$" << addressRangeSize << ", %rsp\n";
}

void ControlFlowGraph::generateASM(ostream &os) const
{
	#ifdef MAP
		cout << "Appel a la methode ControlFlowGraph::generateASM" << endl;
	#endif

	int addressRangeSize = 32;

	generateProlog(os, addressRangeSize);
	/*
	os << ".text\n";
	os << ".global main\n\n";

	os << "main:\n\n";

	os << "\tret\n\n";
	*/
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
