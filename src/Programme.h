# pragma once

# include "Function.h"
# include "Declaration.h"
# include "ControlFlowGraph.h"
# include "IR.h"

# include <vector>

using namespace std;

class IR;
class Function;
class ControlFlowGraph;
class Declaration;

class Programme
{
    public:
        IR generateIR();

        friend ostream & operator<<(ostream & stream, const Programme & programme);

        void addFunction(Function * function);

        void addDeclarations(std::vector<Declaration*> declarations);

        vector <Function*> getFunctions();

        vector <Declaration*> getDeclarations();

        Programme & operator=(const Programme & programme);

        void resolveScopeVariables();

        void resolveTypeExpr();

        Programme(const Programme & programme);

        Programme();

        virtual ~Programme();

    private:
        vector <Function*> functions;
        vector <Declaration*> declarations;
};
