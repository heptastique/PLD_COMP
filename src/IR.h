# pragma once

# include "ControlFlowGraph.h"

# include <iostream>
# include <list>

using namespace std;

class ControlFlowGraph;

class IR
{
	public :

		void generateASM(ostream & os) const;

		void addControlFlowGraph(ControlFlowGraph * controlFlowGraph);

		list <ControlFlowGraph *> getControlFlowGraphs() const;

    	IR();
		IR(const IR & iR);
		IR(list <ControlFlowGraph *> controlFlowGraphs);

		virtual ~IR();

	private :

		list <ControlFlowGraph *> controlFlowGraphs;
};
