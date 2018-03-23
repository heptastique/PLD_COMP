using namespace std;

# include "ControlFlowGraph.h"

void ControlFlowGraph::generateProlog(ostream &os, string functionName, int addressRangeSize) const
{
	#ifdef MAP
		cout << "Appel a la methode ControlFlowGraph::generateProlog" << endl;
	#endif

	os << functionName << ":\n";
	os << "\n";
	os << "\tpusq\t%rbp\n";
	os << "\tmovq\t%rsp, %rbp\n";
	os << "\tsubq\t$" << addressRangeSize << ", %rsp\n";
	os << "\n";
}

void ControlFlowGraph::generateASM(ostream &os) const
{
	#ifdef MAP
		cout << "Appel a la methode ControlFlowGraph::generateASM" << endl;
	#endif

	string functionName = "toto";
	int addressRangeSize = 32;

	generateProlog(os, functionName, addressRangeSize);
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
