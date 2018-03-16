#pragma once

#include "Function.h"
#include <list>

class Programme {

public:

    void addFunction (Function * function);

    Programme &operator=(const Programme &unProgramme);

    Programme(const Programme &unProgramme);

    Programme();

    virtual ~Programme();

    std::list<Function*> functions;
};

