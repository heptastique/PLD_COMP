# pragma once

# include "IRInstr.h"
# include <list>

class IRInstr;

class BasicBlock
{
	protected :

	public :

		void generateASM();

		BasicBlock(const BasicBlock &basicBlock);

    		BasicBlock();

		virtual ~BasicBlock();

	private :

		std::list <IRInstr *> iRInstrs;
		BasicBlock * successor;
		BasicBlock * condSuccessor;
};
