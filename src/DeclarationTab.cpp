using namespace std;

#include "DeclarationTab.h"
#include "ControlFlowGraph.h"
#include <iostream>

string DeclarationTab::generateIR(ControlFlowGraph * controlFlowGraph)
{
    // Same as declaration for the moment
    string var = controlFlowGraph->createNewVariable(name, type);
    this->name = var;

    return var;
}

void DeclarationTab::print(std::ostream &stream) const
{
    stream << " DeclarationTab: Name=" << name << " Type=" << type << " Size=" << size << endl;
}

std::ostream& operator<<(std::ostream& stream, const DeclarationTab& declarationtTab)
{
    stream << " DeclarationTab: Name=" << declarationtTab.name << " Type=" << declarationtTab.type;
    stream << " Size=" << declarationtTab.size << endl;
    
    return stream;
}

DeclarationTab &DeclarationTab::operator=(const DeclarationTab &unDeclarationTab)
{
    //
}

DeclarationTab::DeclarationTab(std::string name, Type type, std::string size):Declaration(name, type)
{
    #ifdef MAP
        cout << "Appel au constructeur de <DeclarationTab>" << endl;
    #endif

    this->size = size;
}

DeclarationTab::~DeclarationTab()
{
    #ifdef MAP
        cout << "Appel au destructeur de <DeclarationTab>" << endl;
    #endif
}
