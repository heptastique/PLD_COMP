# pragma once

# include "BasicBlock.h"
# include "Programme.h"
# include <list>
#include <iostream>

class BasicBlock;
class Programme;

class ControlFlowGraph
{
	protected :

	public :

		void generateASM(std::ostream &os) const;

		ControlFlowGraph(const ControlFlowGraph &controlFlowGraph);

    		ControlFlowGraph();

    		ControlFlowGraph(Programme * prog);

		virtual ~ControlFlowGraph();

	private :

		std::list <BasicBlock *> blocs;
		Programme * prog;
};
