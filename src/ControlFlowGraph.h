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

        //string createNewVariable(string name);

        string createNewTemp();

        //IRVariable getVariable(string name);

        void addIRInstr(IRInstr iRInstr);

        void newBasicBlock();

        void generateProlog(ostream &os, string functionName, int addressRangeSize) const;

        void generateEpilog(ostream & os, int addressRangeSize) const;

        void generateASM(ostream &os) const;

        string getOffset(std::string string);

        ControlFlowGraph(const ControlFlowGraph &controlFlowGraph);

        ControlFlowGraph();

        ControlFlowGraph(Programme * prog);

        virtual ~ControlFlowGraph();

    private:
        Programme * programme;

        BasicBlock * currentBasicBlock;

        vector <BasicBlock*> basicBlocks;

        map <string, IRVariable> variableMap;

        int nbTemp;

        int lastOffset = -8;
};
