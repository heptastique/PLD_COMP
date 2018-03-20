# pragma once

# include "CFG.h"

class IRInstr
{
	protected :

	public :

		IRInstr(const IRInstr &iRInstr);

    		IRInstr();

		virtual ~IRInstr();

	private :

		CFG * cFG;
};
