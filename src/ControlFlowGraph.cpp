using namespace std;

#include "ControlFlowGraph.h"


string ControlFlowGraph::createNewVariable(string name)
{
    nbTemp = nbTemp + 1;

    string variableName = "VAR." + to_string(nbTemp*8);

    IRVariable iRVariable(variableName, lastOffset - 8);

    lastOffset = lastOffset - 8;

    variableMap.insert(pair <string, IRVariable> (variableName, iRVariable));

    return variableName;
}


string ControlFlowGraph::getOffset(std::string string)
{
    auto pos = variableMap.find(string);
    if(pos != variableMap.end())
    {
        IRVariable var = pos->second;
        return to_string(var.getOffset());
    }
    return "0";
}

int ControlFlowGraph::createNewOffset(Type type)
{
    int size = 0;

    if (type == INT32_T || type == CHAR)
    {
        size = 8;
    }
    else if (type == INT64_T)
    {
        size = 16;
    }

    int offset = lastOffset;

    lastOffset = lastOffset - size;

    return offset;
}

string ControlFlowGraph::createNewTemp()
{
    nbTemp = nbTemp + 1;

    string tempName = "TMP." + to_string(nbTemp*8);

    IRVariable iRVariable(tempName, createNewOffset(INT32_T));

    variableMap.insert(pair <string, IRVariable> (tempName, iRVariable));

    return tempName;
}

/*
IRVariable ControlFlowGraph::getVariable(string name)
{
    map <string, IRVariable> :: iterator variable;

    variable = variableMap.find(name);

    return variable->second;
}
*/

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
                case DECL :
                {
                    // Generate Prolog of Function
                    generateProlog(os, iRInstr.getParam(0), stoi(iRInstr.getParam(1)));

                    break;
                }
                // Function Return
                case RET :
                {
                    // Generate Epilog
                    generateEpilog(os, stoi(iRInstr.getParam(0)));

                    break;
                }
                case PUTCHAR_VALUE :
                {
                    os << "\tmovl\t$" << iRInstr.getParam(0) <<", %edi\n";
                    os << "\tcall\tputchar\n";

                    break;
                }
                case PUTCHAR_RBP_REL :
                {
                    os << "\tmovl\t" << iRInstr.getParam(0) <<"(%rbp), %edi\n";
                    os << "\tcall\tputchar\n";

                    break;
                }
                case STORE_RBP_REL :
                {
                    os << "\tmovl\t$" << iRInstr.getParam(0) << ", " << iRInstr.getParam(1) << "(%rbp)\n";

                    break;
                }
                case PUSH_RBP_REL :
                {
                    os << "\tpushl\t" << iRInstr.getParam(0) << "(%rbp)\n";

                    break;
                }
                case PUSH_VALUE :
                {
                    os << "\tpushl\t$" << iRInstr.getParam(0) << "\n";

                    break;
                }
                case CALL :
                {
                    os << "\tcall\t" << iRInstr.getParam(0) << "\n";

                    break;
                }
                case ADD_RSP :
                {
                    os << "\taddq\t$" << iRInstr.getParam(0) << ", %rsp\n";

                    break;
                }
                case ADD :
                {
                    os << "\tmovl\t-" << iRInstr.getParam(1).substr(4)  << "(%rbp), %eax\n";
                    os << "\tadd\t\t-"  << iRInstr.getParam(2).substr(4)  << "(%rbp), %eax\n";
                    os << "\tmovl\t"  << "%eax, -" << iRInstr.getParam(0).substr(4)  << "(%rbp)\n";

                    break;
                }
                case AFFECTATION :
                {
                    os << "\tmovl\t-"  <<  iRInstr.getParam(0).substr(4) << "(%rbp), %eax\n";
                    os << "\tmovl\t" << "%eax, -" << iRInstr.getParam(1).substr(4) << "(%rbp)\n";
                    break;
                }
                case REG_STORE :
                {
                    os << "\tmovl\t$" << iRInstr.getParam(0) << ", -" <<  iRInstr.getParam(1).substr(4) << "(%rbp)\n";
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

    nbTemp = controlFlowGraph.nbTemp;

    lastOffset = controlFlowGraph.lastOffset;
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
