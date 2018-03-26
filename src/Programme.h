# pragma once

# include "Function.h"
# include "Declaration.h"
# include "ControlFlowGraph.h"

# include <list>

using namespace std;

class Function;
class ControlFlowGraph;

class Programme
{
	public:

		ControlFlowGraph generateIR();

		friend ostream & operator<<(ostream & stream, const Programme & programme);

		void addFunction(Function * function);

		void addDeclaration(Declaration * declaration);

		list <Function*> getFunctions();

		list <Declaration*> getDeclarations();

		Programme & operator=(const Programme & programme);

		Programme(const Programme & programme);

		Programme();

		virtual ~Programme();

	private :

		list <Function*> functions;
		list <Declaration*> declarations;
};

