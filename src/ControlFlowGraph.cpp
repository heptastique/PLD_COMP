using namespace std;

# include "ControlFlowGraph.h"

void ControlFlowGraph::addBasicBlock(BasicBlock basicBlock)
{
	basicBlocks.push_back(basicBlock);
}

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

	// TODO : Link to first BasicBlock

	BasicBlock basicBlock = basicBlocks.front();
	IRInstr iRInstr = basicBlock.getIRInstrs().front();

	string functionName = "toto";
	int addressRangeSize = 32;

	generateProlog(os, iRInstr.getParam(0), stoi(iRInstr.getParam(1)));

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

ControlFlowGraph::ControlFlowGraph(Programme * programme)
{
	#ifdef MAP
		cout << "Appel au constructeur de <ControlFlowGraph>" << endl;
	#endif

	this->programme = programme;
}

ControlFlowGraph::~ControlFlowGraph()
{
	#ifdef MAP
		cout << "Appel au destructeur de <ControlFlowGraph>" << endl;
	#endif
}
