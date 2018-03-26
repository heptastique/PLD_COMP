# pragma once

# include "ControlFlowGraph.h"

# include <string>
# include <list>

using namespace std;

class ControlFlowGraph;

enum Mnemonique
{
	FUNCTION_DECLARATION = 0
};

class IRInstr
{
	public :

		Mnemonique getMnemonique() const;

		string getParam(int index) const;
		list <string> getParams() const;

		IRInstr(const IRInstr & iRInstr);

    		IRInstr();
		IRInstr(Mnemonique mnemonique, list <string> params);

		virtual ~IRInstr();

	private :

		ControlFlowGraph * controlFlowGraph;

		Mnemonique mnemonique;
		list <string> params;
};
