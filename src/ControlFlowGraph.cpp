using namespace std;

# include "ControlFlowGraph.h"

void ControlFlowGraph::addIRInstr(IRInstr iRInstr)
{
	currentBasicBlock->addIRInstr(iRInstr);
}

list <BasicBlock *> ControlFlowGraph::getBasicBlocks() const
{
	return basicBlocks;
}

void ControlFlowGraph::newBasicBlock()
{
	BasicBlock * newBasicBlock = new BasicBlock;
	
	basicBlocks.push_back(newBasicBlock);
	
	currentBasicBlock = newBasicBlock;
}

// Generate Prolog of Function
void ControlFlowGraph::generateProlog(ostream & os, string functionName, int addressRangeSize) const
{
	#ifdef MAP
		cout << "Appel a la methode ControlFlowGraph::generateProlog" << endl;
	#endif

	os << functionName << ":\n";
	os << "\n";
	os << "\tpushq\t%rbp\n";
	os << "\tmovq\t%rsp, %rbp\n";
	os << "\tsubq\t$" << addressRangeSize << ", %rsp\n";
	os << "\n";
}
void ControlFlowGraph::generateEpilog(ostream & os, int addressRangeSize) const
{
	#ifdef MAP
		cout << "Appel a la methode ControlFlowGraph::generateProlog" << endl;
	#endif

	os << "\taddq\t$" << addressRangeSize << ", %rsp\n";
	os << "\tpopq\t%rbp\n";
	os << "\tretq\n";
}

// Generate ASM
void ControlFlowGraph::generateASM(ostream & os) const
{
	#ifdef MAP
		cout << "Appel a la methode ControlFlowGraph::generateASM" << endl;
	#endif

	// For each BasicBlock of ControlFLowGraph
	for (auto basicBlock : basicBlocks)
	{
		// For each IRInstr of BasicBlock
		for (auto iRInstr : basicBlock->getIRInstrs())
		{
			// If IRInstr if a Function Declaration
			if (iRInstr.getMnemonique() == FUNCTION_DECLARATION)
			{
				// Generate Prolog of Function
				generateProlog(os, iRInstr.getParam(0), stoi(iRInstr.getParam(1)));

				// Generate Body
				// 

				// Generate Epilog
				generateEpilog(os,stoi(iRInstr.getParam(1)));
			}
			// If IRInstr if a Function Return
			//else if (iRInstr.getMnemonique() == FUNCTION_RETURN)
			//{
				// Generate Epilog
				//generateEpilog(os,stoi(iRInstr.getParam(1)));
			//}
		}
	}
}

ControlFlowGraph::ControlFlowGraph(const ControlFlowGraph &controlFlowGraph)
{
	#ifdef MAP
		cout << "Appel au constructeur de copie de <ControlFlowGraph>" << endl;
	#endif

	programme = controlFlowGraph.programme;

	for (auto basicBlock : controlFlowGraph.basicBlocks)
	{
		basicBlocks.push_back(basicBlock);
	}

	currentBasicBlock = basicBlocks.back();
}


ControlFlowGraph::ControlFlowGraph()
{
	#ifdef MAP
		cout << "Appel au constructeur de <ControlFlowGraph>" << endl;
	#endif

	currentBasicBlock = new BasicBlock;
}

ControlFlowGraph::ControlFlowGraph(Programme * programme)
{
	#ifdef MAP
		cout << "Appel au constructeur de <ControlFlowGraph>" << endl;
	#endif

	currentBasicBlock = new BasicBlock;

	this->programme = programme;
}

ControlFlowGraph::~ControlFlowGraph()
{
	#ifdef MAP
		cout << "Appel au destructeur de <ControlFlowGraph>" << endl;
	#endif
}
