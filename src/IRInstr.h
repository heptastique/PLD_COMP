# pragma once

# include "ControlFlowGraph.h"

# include <string>
# include <list>

using namespace std;

class ControlFlowGraph;

enum Mnemo
{
	FUNCTION_DECLARATION = 0
};

class IRInstr
{
	protected :

	public :

		string getParam(int index);
		list <string> getParams() const;

		IRInstr(const IRInstr &iRInstr);

    		IRInstr();
		IRInstr(Mnemo mnemo, list <string> params);

		virtual ~IRInstr();

	private :

		ControlFlowGraph * controlFlowGraph;

		Mnemo mnemo;
		list <string> params;
};
