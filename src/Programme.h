#pragma once

#include "Function.h"
#include "Declaration.h"
#include <list>

class Programme {

public:

    friend std::ostream& operator<< (std::ostream& stream, const Programme& programme);

    void addFunction (Function * function);

    void addDeclaration (Declaration * declaration);

    std::list<Function*> getFunctions();

    std::list<Declaration*> getDeclarations();

    Programme &operator=(const Programme &unProgramme);

    Programme(const Programme &unProgramme);

    Programme();

    virtual ~Programme();

    std::list<Function*> functions;
    std::list<Declaration*> declarions;
};

