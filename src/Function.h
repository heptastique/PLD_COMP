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

	friend ostream & operator<<(ostream & stream, const Function & function);

    ControlFlowGraph generateIR();

    int calculateAddressRangeSize();

    void resolveScopeVariables(std::list<Declaration*> declProgramme);

	void setParameters(list <Declaration*> parameters);

	string getName();

	std::list<Declaration*> getParameters();

	Bloc * getBloc();

	Function & operator=(const Function & function);

	Function(const Function & function);
  
    Function(string name, Bloc * bloc, Type typeRetour);

	virtual ~Function();


private:
    std::string name;
    Bloc* bloc;
    std::list<Declaration*> parameters;
    Type typeRetour;
};
