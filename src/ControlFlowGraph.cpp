using namespace std;

# include "ControlFlowGraph.h"

list <BasicBlock> ControlFlowGraph::getBasicBlocks() const
{
	list <BasicBlock> basicBlocksCopy;

	list <BasicBlock> :: const_iterator it = basicBlocks.begin();

	while (it != basicBlocks.end())
	{
		basicBlocksCopy.push_back(*it);

		it ++;
	}

	return basicBlocksCopy;
}

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

	list <BasicBlock> :: const_iterator basicBlock = basicBlocks.begin();

	while (basicBlock != basicBlocks.end())
	{
		list <IRInstr> iRInstrs = basicBlock->getIRInstrs();

		list <IRInstr> :: iterator iRInstr = iRInstrs.begin();

		while (iRInstr != iRInstrs.end())
		{
			if (iRInstr->getMnemonique() == FUNCTION_DECLARATION)
			{
				generateProlog(os, iRInstr->getParam(0), stoi(iRInstr->getParam(1)));
			}

			iRInstr ++;
		}

		basicBlock ++;
	}
}

ControlFlowGraph::ControlFlowGraph(const ControlFlowGraph &controlFlowGraph)
{
	#ifdef MAP
		cout << "Appel au constructeur de copie de <ControlFlowGraph>" << endl;
	#endif

	programme = controlFlowGraph.programme;

	basicBlocks = controlFlowGraph.getBasicBlocks();
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
