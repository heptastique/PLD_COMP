using namespace std;

# include "ControlFlowGraph.h"

string ControlFlowGraph::createNewVariable()
{
	nbVariables = nbVariables + 1;

	string name = "tmp" + to_string(nbVariables);

	IRVariable iRVariable(name);

	variableMap.insert(pair <string, IRVariable> (name, iRVariable));

	return name;
}

IRVariable ControlFlowGraph::getVariable(string name)
{
	map <string, IRVariable> :: iterator variable;

	//variable = 
}

void ControlFlowGraph::addIRInstr(IRInstr iRInstr)
{
	currentBasicBlock->addIRInstr(iRInstr);
}

vector <BasicBlock*> ControlFlowGraph::getBasicBlocks() const
{
	return basicBlocks;
}

void ControlFlowGraph::newBasicBlock()
{
	BasicBlock * newBasicBlock = new BasicBlock;

	basicBlocks.push_back(newBasicBlock);

	currentBasicBlock = newBasicBlock;
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
			// For each Kind of IRInstr
			switch (iRInstr.getMnemonique())
			{
				// Function Declaration
				case FUNCTION_DECLARATION :
				{
					// Generate Prolog of Function
					os << iRInstr.getParam(0) << ":\n";
					os << "\n";
					os << "\tpushq\t%rbp\n";
					os << "\tmovq\t%rsp, %rbp\n";
					os << "\tsubq\t$" << iRInstr.getParam(1) << ", %rsp\n";
					os << "\n";

					break;
				}
				// Function Return
				case FUNCTION_RETURN :
				{
					// Generate Epilog
					os << "\n";
					os << "\taddq\t$" << iRInstr.getParam(0) << ", %rsp\n";
					os << "\tpopq\t%rbp\n";
					os << "\tretq\n";
					os << "\n";

					break;
				}
				case PUTCHAR :
				{
					os << "\tmovl\t$" << iRInstr.getParam(0) <<", %edi\n";
					os << "\tcall putchar\n";
				}
			}
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
