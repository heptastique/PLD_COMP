#pragma once

#include "Instruction.h"
#include "Type.h"
#include <string>

class Declaration : public Instruction {

public:

    void print(std::ostream& stream) const;

    friend std::ostream& operator<< (std::ostream& stream, const Declaration& declaration);

    Declaration &operator=(const Declaration &unDeclaration);

    Type getType();

    std::string getName();

    Declaration(const Declaration &unDeclaration);

    Declaration(std::string name, Type type);

    virtual ~Declaration();

private:
    Type type;
    std::string name;
};
