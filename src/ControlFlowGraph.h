# pragma once

# include "BasicBlock.h"
# include "IRInstr.h"
# include "Programme.h"
# include "IRVariable.h"
# include <vector>
# include <iostream>
# include <map>

using namespace std;

class BasicBlock;
class IRInstr;
class Programme;
class IRVariable;

class ControlFlowGraph
{
	protected :

	public :

		string createNewVariable(string name);

		string createNewTemp();

		IRVariable getVariable(string name);

		void addIRInstr(IRInstr iRInstr);

		vector <BasicBlock*> getBasicBlocks() const;

		void newBasicBlock();

		void generateASM(ostream &os) const;

		ControlFlowGraph(const ControlFlowGraph &controlFlowGraph);

    		ControlFlowGraph();

    		ControlFlowGraph(Programme * prog);

		virtual ~ControlFlowGraph();

	private :

		Programme * programme;

		BasicBlock * currentBasicBlock;

		vector <BasicBlock*> basicBlocks;

		map <string, IRVariable> variableMap;

		int nbTemp;
};
