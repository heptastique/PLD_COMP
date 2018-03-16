#pragma once

#include "ostream"
class Instruction {

public:

    friend std::ostream& operator<< (std::ostream& stream, const Instruction& instruction);

    Instruction &operator=(const Instruction &unInstruction);

    Instruction(const Instruction &unInstruction);

    Instruction();

    virtual ~Instruction();

};
