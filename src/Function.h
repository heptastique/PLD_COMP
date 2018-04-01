#pragma once

#include <string>
#include "ControlFlowGraph.h"
#include "Bloc.h"
#include "Type.h"

using namespace std;

class ControlFlowGraph;
class Bloc;
class Declaration;

class Function
{
    public:
        void generateIR(ControlFlowGraph * controlFlowGraph);

        friend ostream & operator<<(ostream & stream, const Function & function);

        Function & operator=(const Function & function);

        int calculateAddressRangeSize();

        void setParameters(vector <Declaration*> parameters);

        std::vector<Declaration*> getParameters();

        void resolveScopeVariables(std::vector<Declaration*> declProgramme, std::vector<Function*> functionProgram);

        void resolveTypeExpr();

        string getName();

        Bloc * getBloc();

        Type getTypeRetour ();

        Function(const Function & function);

        Function(string name, Bloc * bloc, Type typeRetour);

        virtual ~Function();

    private:
        std::string name;
        Bloc* bloc;
        std::vector<Declaration*> parameters;
        Type typeRetour;
};
