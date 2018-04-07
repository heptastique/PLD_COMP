#pragma once

#include "BasicBlock.h"
#include "IRInstr.h"
#include "Programme.h"
#include "Type.h"
//#include "IRVariable.h"
#include <vector>
#include <iostream>
#include <map>

using namespace std;

class BasicBlock;
class IRInstr;
class Programme;
class IRVariable;

class ControlFlowGraph
{
    public:
        int createNewOffset(Type type);

        vector <BasicBlock*> getBasicBlocks() const;

        int getLastLabel() const;

        string createNewVariable(string name, Type type);

        string createNewTemp(Type type);

        //IRVariable getVariable(string name);

        void addIRInstr(IRInstr iRInstr);

        void newBasicBlock();

        void generateProlog(ostream &os, string functionName, int addressRangeSize) const;

        void generateEpilog(ostream & os, int addressRangeSize) const;

        bool getEpilogGenerated() const;

        void setEpilogGenerated();

        void generateASM(ostream &os) const;

        void setLastLabel(int label);

        void setAddressRangeSize(int addressRangeSize);

        int getLastOffset();

        string getOffset(std::string string);

        int getAddressRangeSize();

        ControlFlowGraph(const ControlFlowGraph &controlFlowGraph);

        ControlFlowGraph();

        ControlFlowGraph(Programme * prog);

        virtual ~ControlFlowGraph();

    private:
        Programme * programme;

        BasicBlock * currentBasicBlock;

        vector <BasicBlock*> basicBlocks;

        map <string, IRVariable> variableMap;

        int nbTemp = 0;

        int lastOffset = -8;

        int addressRangeSize = 0;

        bool epilogGenerated = false;
};
