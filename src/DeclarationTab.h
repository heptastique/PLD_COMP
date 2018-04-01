#pragma once

#include "Declaration.h"

class DeclarationTab : public Declaration {
public:
    void generateIR(ControlFlowGraph * controlFlowGraph);

    void print(std::ostream& stream) const;

    friend std::ostream& operator<< (std::ostream& stream, const DeclarationTab& declarationTab);

    void setSize(std::string size){
        this->size=size;
    }

    DeclarationTab &operator=(const DeclarationTab &unDeclarationTab);

    DeclarationTab(std::string name, Type type, std::string size);

    virtual ~DeclarationTab();

protected:
    std::string size;
};
