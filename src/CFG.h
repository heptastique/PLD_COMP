# pragma once

# include "BasicBlock.h"
# include <list>

class CFG
{
	protected :

	public :

		CFG(const CFG &cFG);

    		CFG();

		virtual ~CFG();

	private :

		std::list <BasicBlock*> blocs;
};
