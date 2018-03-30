# pragma once

# include "ControlFlowGraph.h"

# include <string>
# include <vector>

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
		vector <string> getParams() const;

		IRInstr(const IRInstr & iRInstr);

    		IRInstr();
		IRInstr(Mnemonique mnemonique, vector <string> params);

		virtual ~IRInstr();

	private :

		ControlFlowGraph * controlFlowGraph;

		Mnemonique mnemonique;
		vector <string> params;
};
