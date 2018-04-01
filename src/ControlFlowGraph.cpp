using namespace std;

#include "ControlFlowGraph.h"

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

    os << "\n";
    os << "\taddq\t$" << addressRangeSize << ", %rsp\n";
    os << "\tpopq\t%rbp\n";
    os << "\tretq\n";
    os << "\n";
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
                    generateProlog(os, iRInstr.getParam(0), stoi(iRInstr.getParam(1)));

                    break;
                }
                // Function Return
                case FUNCTION_RETURN :
                {
                    // Generate Epilog
                    generateEpilog(os, stoi(iRInstr.getParam(0)));

                    break;
                }
                case PUTCHAR :
                {
                    os << "\tmovl\t$" << iRInstr.getParam(0) <<", %edi\n";
                    os << "\tcall putchar\n";
                    break;
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
