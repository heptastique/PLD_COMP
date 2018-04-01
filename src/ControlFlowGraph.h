#pragma once

#include "BasicBlock.h"
#include "IRInstr.h"
#include "Programme.h"
#include <vector>
#include <iostream>

using namespace std;

class BasicBlock;
class IRInstr;
class Programme;

class ControlFlowGraph
{
    public:
        void addIRInstr(IRInstr iRInstr);

        vector <BasicBlock*> getBasicBlocks() const;

        void newBasicBlock();

        void generateProlog(ostream &os, string functionName, int addressRangeSize) const;

        void generateEpilog(ostream & os, int addressRangeSize) const;

        void generateASM(ostream &os) const;

        ControlFlowGraph(const ControlFlowGraph &controlFlowGraph);

        ControlFlowGraph();

        ControlFlowGraph(Programme * prog);

        virtual ~ControlFlowGraph();

    private:
        Programme * programme;
        BasicBlock * currentBasicBlock;
        vector <BasicBlock*> basicBlocks;
};
