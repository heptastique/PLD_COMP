# pragma once

# include "BasicBlock.h"
# include "Programme.h"
# include <list>
# include <iostream>

using namespace std;

class BasicBlock;
class Programme;

class ControlFlowGraph
{
	protected :

	public :

		void addBasicBlock(BasicBlock basicBlock);

		void generateProlog(ostream &os, string functionName, int addressRangeSize) const;

		void generateASM(ostream &os) const;

		ControlFlowGraph(const ControlFlowGraph &controlFlowGraph);

    		ControlFlowGraph();

    		ControlFlowGraph(Programme * prog);

		virtual ~ControlFlowGraph();

	private :

		list <BasicBlock> basicBlocks;
		Programme * programme;
};
