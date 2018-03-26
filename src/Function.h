# pragma once

# include "Bloc.h"
# include "Declaration.h"
# include "ControlFlowGraph.h"

# include <string>

using namespace std;

class ControlFlowGraph;

class Function
{
	public:

		ControlFlowGraph generateIR();

		friend ostream & operator<<(ostream & stream, const Function & function);

		void setDeclarations(list <Declaration*> declarations);

		Function & operator=(const Function & function);

		string getName();

		Bloc * getBloc();

		Function(const Function & function);

		Function(string name, Bloc * bloc, Type typeRetour);

		virtual ~Function();

	private:

		string name;
		Bloc * bloc;
		list <Declaration*> declarations;
		Type typeRetour;
};
