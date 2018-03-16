#pragma once

#include "Instruction.h"
#include "Type.h"
#include <string>

class Declaration : public Instruction {

public:

    friend std::ostream& operator<< (std::ostream& stream, const Declaration& declaration);

    Declaration &operator=(const Declaration &unDeclaration);

    Declaration(const Declaration &unDeclaration);

    Declaration(std::string name, Type type);

    virtual ~Declaration();

private:
    Type type;
    std::string name;
};
