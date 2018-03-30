# pragma once

# include "IRInstr.h"
# include <string>
# include <vector>

using namespace std;

class IRInstr;

class BasicBlock
{
	protected :

	public :

		vector <IRInstr> getIRInstrs() const;

		void addFunctionDefinition(string functionName, int adressRangeSize);

		void generateASM();

		BasicBlock(const BasicBlock & basicBlock);

    		BasicBlock();

		virtual ~BasicBlock();

	private :

		vector <IRInstr> iRInstrs;
		BasicBlock * successor;
		BasicBlock * condSuccessor;
};
