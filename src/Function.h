#pragma once

#include <string>
#include "Bloc.h"
#include "Declaration.h"

class Function {


public:

    friend std::ostream& operator<< (std::ostream& stream, const Function& function);

    void setDeclarations(std::list<Declaration*> declarations)
    {
        this->declarations = declarations;
    }

    Function &operator=(const Function &unFunction);

    std::string getName();

    Bloc* getBloc();

    Function(const Function &unFunction);

    Function(std::string name, Bloc *Bloc, Type typeRetour);

    virtual ~Function();

private:
    std::string name;
    Bloc* bloc;
    std::list<Declaration*> declarations;
    Type typeRetour;
};