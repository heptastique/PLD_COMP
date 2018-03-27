# pragma once

# include <string>

# include "Bloc.h"
# include "Declaration.h"
# include "ControlFlowGraph.h"

using namespace std;

class ControlFlowGraph;

class Function
{
	public:
  
    void setParameters(std::list<Declaration*> parameters)
    {
        this->parameters = parameters;
    }

		ControlFlowGraph generateIR();

		friend ostream & operator<<(ostream & stream, const Function & function);

		void setDeclarations(list <Declaration*> declarations);

		Function & operator=(const Function & function);

    std::list<Declaration*> getParameters();

    void resolveScopeVariables(std::list<Declaration*> declProgramme);

		string getName();

		Bloc * getBloc();

		Function(const Function & function);
  
    Function(string name, Bloc * bloc, Type typeRetour);

		virtual ~Function();


private:
    std::string name;
    Bloc* bloc;
    std::list<Declaration*> parameters;
    Type typeRetour;
};
