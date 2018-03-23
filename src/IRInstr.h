# pragma once

# include "ControlFlowGraph.h"

class ControlFlowGraph;

class IRInstr
{
	protected :

	public :

		IRInstr(const IRInstr &iRInstr);

    	IRInstr();

		virtual ~IRInstr();

	private :

		ControlFlowGraph * controlFlowGraph;
};
