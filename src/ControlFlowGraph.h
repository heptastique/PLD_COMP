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

		void generateProlog(ostream &os, int addressRangeSize) const;

		void generateASM(ostream &os) const;

		ControlFlowGraph(const ControlFlowGraph &controlFlowGraph);

    		ControlFlowGraph();

    		ControlFlowGraph(Programme * prog);

		virtual ~ControlFlowGraph();

	private :

		list <BasicBlock *> blocs;
		Programme * prog;
};
