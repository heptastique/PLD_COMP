using namespace std;

# include "Programme.h"
#include "ErrorHandling.h"

# include <iostream>

// Generate IR
IR Programme::generateIR()
{
    // Create IR
    IR iR;

    ControlFlowGraph * controlFlowGraph;

    // For each Function of Program
    for (auto function : functions)
    {
        controlFlowGraph = new ControlFlowGraph;

        // Generate Function Control Flow Graph
        function->generateIR(controlFlowGraph);

        // Add Function Control Flow Graph to IR
        iR.addControlFlowGraph(controlFlowGraph);
    }

    return iR;
}

ostream & operator<<(ostream & stream, const Programme & programme)
{
    stream << "Programme:" << endl;

    for (auto declaration :  programme.declarations)
    {
        stream << *declaration;
    }

    for (auto function :  programme.functions)
    {
        stream << *function;
    }

    stream << endl;

    return stream;
}

void Programme::addFunction(Function *function)
{
    this->functions.emplace_back(function);
}

void Programme::addDeclarations(vector<Declaration*> declarations)
{
    for(auto decl : declarations){
        this->declarations.emplace_back(decl);
    }
}

vector <Function*> Programme::getFunctions()
{
    return this->functions;
}

vector <Declaration*> Programme::getDeclarations()
{
    return this->declarations;
}

void Programme::resolveScopeVariables()
{
    vector<Declaration*>::iterator it;
    for(it = this->declarations.begin(); it != this->declarations.end(); ++it){
        vector<Declaration*>::iterator it2 = it;
        ++it2;
        while(it2 != this->declarations.end()){
            Declaration * declaration = *it;
            Declaration * declaration2 = *it2;
            if ( declaration->getName().compare(declaration2->getName()) == 0)
            {
                ErrorHandling::ThrowError(103,0, declaration2->getName());
            }
            ++it2;
        }
    }
    // test if 2 functions share the same name
    vector<Function*>::iterator itfunction;
    for(itfunction = this->functions.begin(); itfunction!=this->functions.end(); ++itfunction){
        auto itfunction2 = itfunction;
        ++itfunction2;
        while(itfunction2!= this->functions.end()){
            Function * function = *itfunction;
            Function * function2 = *itfunction2;
            if ( function->getName().compare(function2->getName()) == 0)
            {
                ErrorHandling::ThrowError(105,0, function2->getName());
            }
            ++itfunction2;
        }
    }

    for (auto function :  this->functions){
        function->resolveScopeVariables(this->getDeclarations(), this->functions);
    }
}

void Programme::resolveTypeExpr(){
    for (auto function :  this->functions){
        function->resolveTypeExpr();
    }
}

Programme & Programme::operator=(const Programme & programme)
{
}

Programme::Programme(const Programme & programme)
{
    #ifdef MAP
        cout << "Appel au constructeur de copie de <Programme>" << endl;
    #endif
}

Programme::Programme()
{
    #ifdef MAP
        cout << "Appel au constructeur de <Programme>" << endl;
    #endif
}

Programme::~Programme()
{
    #ifdef MAP
        cout << "Appel au destructeur de <Programme>" << endl;
    #endif
}
