# pragma once

# include "IRInstr.h"
# include <string>
# include <list>

using namespace std;

class IRInstr;

class BasicBlock
{
	protected :

	public :

		list <IRInstr> getIRInstrs() const;

		void addFunctionDefinition(string functionName, int adressRangeSize);

		void generateASM();

		BasicBlock(const BasicBlock &basicBlock);

    	BasicBlock();

		virtual ~BasicBlock();

	private :

		list <IRInstr> iRInstrs;
		BasicBlock * successor;
		BasicBlock * condSuccessor;
};
