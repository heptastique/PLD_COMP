# pragma once

# include "BasicBlock.h"
# include "Programme.h"
# include <list>

class BasicBlock;

class ControlFlowGraph
{
	protected :

	public :
	
		void visit();

		ControlFlowGraph(const ControlFlowGraph &controlFlowGraph);

    	ControlFlowGraph();
    	
    	ControlFlowGraph(Programme * prog);

		virtual ~ControlFlowGraph();

	private :

		std::list <BasicBlock *> blocs;
		Programme * prog;
};
