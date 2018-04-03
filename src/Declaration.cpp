using namespace std;

#include "Declaration.h"
#include "ControlFlowGraph.h"

#include <iostream>

string Declaration::generateIR(ControlFlowGraph * controlFlowGraph)
{
    // controlFlowGraph->createNewVariable(name);

    offset = controlFlowGraph->createNewOffset(type);

    return "";
}

void Declaration::print(std::ostream &stream) const
{
    stream << " Declaration: Name=" << name << " Type=" << type << endl;
}

std::ostream& operator<<(std::ostream& stream, const Declaration& declaration)
{
    stream << " Declaration: Name=" << declaration.name << " Type=" << declaration.type << endl;

    return stream;
}

Declaration & Declaration::operator=(const Declaration & declaration)
{
    type = declaration.type;
    name = declaration.name;
    //iRVariable = declaration.iRVariable;
    offset = declaration.offset;
}

void Declaration::resolveScopeVariables(std::vector<Declaration*> declProgramme, std::vector<Declaration*> paramFunction, std::vector<Declaration*> declBloc, std::vector<Function*> functionProgram)
{
    //iRVariable = IRVariable(name, declBloc.size() * 8);
}

void Declaration::resolveTypeExpr()
{
    //
}

void Declaration::setType(Type type)
{
    this->type = type;
}
/*
void Declaration::setIRVariable(IRVariable iRVariable)
{
    this->iRVariable = iRVariable;
}

IRVariable Declaration::getIRVariable()
{
    return iRVariable;
}
*/
Type Declaration::getType()
{
    return this->type;
}

void Declaration::setOffset(int offset)
{
    this->offset = offset;
}

int Declaration::getOffset()
{
    return offset;
}

std::string Declaration::getName()
{
    return this->name;
}

Declaration::Declaration()
{
    #ifdef MAP
        cout << "Appel au constructeur par default de <Declaration>" << endl;
    #endif
}

Declaration::Declaration(const Declaration &unDeclaration)
{
    #ifdef MAP
        cout << "Appel au constructeur de copie de <Declaration>" << endl;
    #endif
}

Declaration::Declaration(string name, Type type): Instruction()
{
    #ifdef MAP
        cout << "Appel au constructeur de <Declaration>" << endl;
    #endif

    this->name = name;
    this->type = type;
}

Declaration::~Declaration()
{
    #ifdef MAP
        cout << "Appel au destructeur de <Declaration>" << endl;
    #endif
}
