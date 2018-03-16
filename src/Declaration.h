#pragma once

#include "Instruction.h"
#include "Type.h"
#include <string>

class Declaration : public Instruction {

public:

    Declaration &operator=(const Declaration &unDeclaration);

    Declaration(const Declaration &unDeclaration);

    Declaration(std::string &name, Type type);

    virtual ~Declaration();

private:
    Type type;
    std::string name;
};
