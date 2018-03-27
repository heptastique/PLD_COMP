#pragma once

#include <string>
#include "Bloc.h"
#include "Declaration.h"


class Function {


public:

    friend std::ostream& operator<< (std::ostream& stream, const Function& function);

    void setParameters(std::list<Declaration*> parameters)
    {
        this->parameters = parameters;
    }

    Function &operator=(const Function &unFunction);

    std::string getName();

    Bloc* getBloc();

    std::list<Declaration*> getParameters();

    void resolveScopeVariables(std::list<Declaration*> declProgramme);

    Function(const Function &unFunction);

    Function(std::string name, Bloc *Bloc, Type typeRetour);

    virtual ~Function();

private:
    std::string name;
    Bloc* bloc;
    std::list<Declaration*> parameters;
    Type typeRetour;
};