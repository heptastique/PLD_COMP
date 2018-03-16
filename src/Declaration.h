#pragma once

#include "Instruction.h"

class Declaration : public Instruction {

public:

    Declaration &operator=(const Declaration &unDeclaration);

    Declaration(const Declaration &unDeclaration);

    Declaration();

    virtual ~Declaration();

};
