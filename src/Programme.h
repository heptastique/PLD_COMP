#pragma once

#include "Function.h"
#include "Declaration.h"
#include <list>

class Programme {

public:

    void addFunction (Function * function);

    void addDeclaration (Declaration * declaration);

    Programme &operator=(const Programme &unProgramme);

    Programme(const Programme &unProgramme);

    Programme();

    virtual ~Programme();

    std::list<Function*> functions;
    std::list<Declaration*> declarions;
};

