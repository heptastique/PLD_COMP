# pragma once

# include "Function.h"
# include "Declaration.h"
# include "ControlFlowGraph.h"
# include "IR.h"

# include <list>

using namespace std;

class IR;
class Function;
class ControlFlowGraph;

class Programme
{
	public:

		IR generateIR();

		friend ostream & operator<<(ostream & stream, const Programme & programme);

		void addFunction(Function * function);

		void addDeclaration(Declaration * declaration);

		list <Function*> getFunctions();

		list <Declaration*> getDeclarations();

		Programme & operator=(const Programme & programme);

    void resolveScopeVariables();

		Programme(const Programme & programme);

		Programme();

		virtual ~Programme();

	private :

		list <Function*> functions;
		list <Declaration*> declarations;
};

