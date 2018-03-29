# pragma once

# include "BasicBlock.h"
# include <list>
# include <iostream>

using namespace std;

class BasicBlock;
class Programme;

class ControlFlowGraph
{
	protected :

	public :

		list <BasicBlock> getBasicBlocks() const;

		void addBasicBlock(BasicBlock basicBlock);

		void generateProlog(ostream &os, string functionName, int addressRangeSize) const;
		
		void generateEpilog(ostream & os, int addressRangeSize) const;

		void generateASM(ostream &os) const;

		ControlFlowGraph(const ControlFlowGraph &controlFlowGraph);

    		ControlFlowGraph();

    		ControlFlowGraph(Programme * prog);

		virtual ~ControlFlowGraph();

	private :

		Programme * programme;
		list <BasicBlock> basicBlocks;
};
