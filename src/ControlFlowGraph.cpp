using namespace std;

#include "ControlFlowGraph.h"


string ControlFlowGraph::createNewVariable(string name, Type type)
{
    IRVariable iRVariable("VAR", createNewOffset(type));
    string variableName = "VAR." + to_string(iRVariable.getOffset());
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

string ControlFlowGraph::createNewTemp(Type type)
{
    nbTemp = nbTemp + 1;

    IRVariable iRVariable("TMP", createNewOffset(type));

    string tempName = "TMP." + to_string(iRVariable.getOffset());

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

int ControlFlowGraph::getLastLabel() const
{
    return this->lastLabel;
}

void ControlFlowGraph::setLastLabel(int label)
{
    this->lastLabel = label;
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
        cout << "Appel a la methode ControlFlowGraph::generateEpilog" << endl;
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

                case COMPJUMP :
                {
                    os << "\tcmpl\t$1, " << iRInstr.getParam(1) << "(%rbp)\n";
                    os << "\tjne .L" << iRInstr.getParam(0) << "\n";

                    break;
                }

                case LABEL :
                {
                    os << ".L" << iRInstr.getParam(0) << ":\n";

                    break;
                }

                case RETIF :
                {
                    os << "\tjmp .L" << iRInstr.getParam(0) << "\n";

                    break;
                }

                case PUTCHAR_VALUE :
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
                    os << "\tpush\t" << iRInstr.getParam(0) << "(%rbp)\n";

                    break;
                }
                case PUSH_VALUE :
                {
                    os << "\tpush\t$" << iRInstr.getParam(0) << "\n";

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
                case BINARYOPERATION :
                {
                    os << "\tmovl\t" << iRInstr.getParam(2)  << "(%rbp), %eax\n";

                    if ( iRInstr.getParam(0) == to_string(PLUS))
                    {
                        os << "\tadd\t\t" << iRInstr.getParam(3) << "(%rbp), %eax\n";
                    }
                    if ( iRInstr.getParam(0) == to_string(MINUS))
                    {
                        os << "\tsub\t\t" << iRInstr.getParam(3) << "(%rbp), %eax\n";
                    }
                    if ( iRInstr.getParam(0) == to_string(MULT))
                    {
                        os << "\timul\t" << iRInstr.getParam(3) << "(%rbp), %eax\n";
                    }
                    if ( iRInstr.getParam(0) == to_string(DIV))
                    {
                        os << "\tmovl\t"  << "$0, %edx\n";
                        os << "\tmovl\t"  << iRInstr.getParam(3) <<"(%rbp), %ebx\n";
                        os << "\tidiv\t%ebx\n";
                    }
                    if ( iRInstr.getParam(0) == to_string(MOD))
                    {
                        os << "\tmovl\t"  << "$0, %edx\n";
                        os << "\tmovl\t"  << iRInstr.getParam(3) <<"(%rbp), %ebx\n";
                        os << "\tidiv\t%ebx\n";
                        os << "\tmovl\t"  << "%edx, %eax";
                    }
                    if ( iRInstr.getParam(0) == to_string(ANDBB))
                    {
                        os << "\tand\t" << iRInstr.getParam(3) << "(%rbp), %eax\n";
                    }
                    if ( iRInstr.getParam(0) == to_string(ORBB))
                    {
                        os << "\tor\t" << iRInstr.getParam(3) << "(%rbp), %eax\n";
                    }
                    if ( iRInstr.getParam(0) == to_string(XORBITWISEB))
                    {
                        os << "\txor\t" << iRInstr.getParam(3) << "(%rbp), %eax\n";
                    }
                    if ( iRInstr.getParam(0) == to_string(LEFTSHIFTBITWISEB))
                    {
                        os << "\tshl\t" << iRInstr.getParam(3) << "(%rbp), %eax\n";
                    }
                    if ( iRInstr.getParam(0) == to_string(RIGHTSHIFTBITWISEB))
                    {
                        os << "\tshr\t" << iRInstr.getParam(3) << "(%rbp), %eax\n";
                    }
                    if ( iRInstr.getParam(0) == to_string(EQUALEQUAL))
                    {
                        os << "\tcmp\t" << iRInstr.getParam(3) << "(%rbp), %eax\n";
                        os << "\tmovl\t$0, %eax\n";
                        os << "\tsete\t%al\n";
                    }
                    if ( iRInstr.getParam(0) == to_string(NOTEQUAL))
                    {
                        os << "\tcmp\t" << iRInstr.getParam(3) << "(%rbp), %eax\n";
                        os << "\tmovl\t$0, %eax\n";
                        os << "\tsetne\t%al\n";
                    }
                    if ( iRInstr.getParam(0) == to_string(LT))
                    {
                        os << "\tcmp\t" << iRInstr.getParam(3) << "(%rbp), %eax\n";
                        os << "\tmovl\t$0, %eax\n";
                        os << "\tsetl\t%al\n";
                    }
                    if ( iRInstr.getParam(0) == to_string(GT))
                    {
                        os << "\tcmp\t" << iRInstr.getParam(3) << "(%rbp), %eax\n";
                        os << "\tmovl\t$0, %eax\n";
                        os << "\tsetg\t%al\n";
                    }
                    if ( iRInstr.getParam(0) == to_string(LTE))
                    {
                        os << "\tcmp\t" << iRInstr.getParam(3) << "(%rbp), %eax\n";
                        os << "\tmovl\t$0, %eax\n";
                        os << "\tsetle\t%al\n";
                    }
                    if ( iRInstr.getParam(0) == to_string(GTE))
                    {
                        os << "\tcmp\t" << iRInstr.getParam(3) << "(%rbp), %eax\n";
                        os << "\tmovl\t$0, %eax\n";
                        os << "\tsetge\t%al\n";
                    }
                    if ( iRInstr.getParam(0) == to_string(AND))
                    {
                        os << "\tmovl\t"<< iRInstr.getParam(3) << "(%rbp), %ebx\n";
                        os << "\tcmp\t$0, %eax\n";
                        os << "\tmovl\t$0, %eax\n";
                        os << "\tsetne\t%al\n";
                        os << "\tcmp\t$0, %ebx\n";
                        os << "\tmovl\t$0, %ebx\n";
                        os << "\tsetne\t%bl\n";
                        os << "\tand\t%bl, %al\n";
                    }
                    if ( iRInstr.getParam(0) == to_string(OR))
                    {
                        os << "\tmovl\t"<< iRInstr.getParam(3) << "(%rbp), %ebx\n";
                        os << "\tcmp\t$0, %eax\n";
                        os << "\tmovl\t$0, %eax\n";
                        os << "\tsetne\t%al\n";
                        os << "\tcmp\t$0, %ebx\n";
                        os << "\tmovl\t$0, %ebx\n";
                        os << "\tsetne\t%bl\n";
                        os << "\tor\t%bl, %al\n";
                    }
                    os << "\tmovl\t"  << "%eax, " << iRInstr.getParam(1) << "(%rbp)\n";

                    break;
                }
                case AFFECTATION :
                {
                    os << "\tmovl\t"  <<  iRInstr.getParam(0) << "(%rbp), %eax\n";
                    os << "\tmovl\t" << "%eax, " << iRInstr.getParam(1) << "(%rbp)\n";
                    break;
                }
                case REG_STORE :
                {
                    os << "\tmovl\t$" << iRInstr.getParam(0) << ", " <<  iRInstr.getParam(1) << "(%rbp)\n";
                    break;
                }
                case UNARYOPERATION :
                {
                    os << "\tmovl\t"  << iRInstr.getParam(2) << "(%rbp), %eax\n";
                    if ( iRInstr.getParam(0).compare(to_string(MINUSU)) == 0 )
                    {
                        os << "\tneg\t%eax\n";
                    }
                    if ( iRInstr.getParam(0).compare(to_string(NOT)) == 0 )
                    {
                        os << "\tnot\t%eax\n";
                    }
                    os << "\tmovl\t"  << "%eax, " << iRInstr.getParam(1)  << "(%rbp)\n";
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
