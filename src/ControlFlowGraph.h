# pragma once

# include "BasicBlock.h"
# include "IRInstr.h"
# include <list>
# include <iostream>

using namespace std;

class BasicBlock;
class IRInstr;
class Programme;

class ControlFlowGraph
{
	protected :

	public :

		void addIRInstr(IRInstr iRInstr);

		list <BasicBlock *> getBasicBlocks() const;

		void newBasicBlock();

		void generateProlog(ostream &os, string functionName, int addressRangeSize) const;
		
		void generateEpilog(ostream & os, int addressRangeSize) const;

		void generateASM(ostream &os) const;

		ControlFlowGraph(const ControlFlowGraph &controlFlowGraph);

    		ControlFlowGraph();

    		ControlFlowGraph(Programme * prog);

		virtual ~ControlFlowGraph();

	private :

		Programme * programme;
		list <BasicBlock *> basicBlocks;
		BasicBlock * currentBasicBlock;
};
