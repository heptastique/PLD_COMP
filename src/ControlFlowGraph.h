# pragma once

# include "BasicBlock.h"
# include <list>

class BasicBlock;

class ControlFlowGraph
{
	protected :

	public :

		ControlFlowGraph(const ControlFlowGraph &controlFlowGraph);

    		ControlFlowGraph();

		virtual ~ControlFlowGraph();

	private :

		std::list <BasicBlock *> blocs;
};
