# pragma once

# include "BasicBlock.h"
# include "Programme.h"
# include <list>

class BasicBlock;
class Programme;

class ControlFlowGraph
{
	protected :

	public :

		void generateASM();

		ControlFlowGraph(const ControlFlowGraph &controlFlowGraph);

    		ControlFlowGraph();

    		ControlFlowGraph(Programme * prog);

		virtual ~ControlFlowGraph();

	private :

		std::list <BasicBlock *> blocs;
		Programme * prog;
};
