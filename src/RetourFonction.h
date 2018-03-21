#pragma once

#include <ostream>
#include "Instruction.h"
#include "Variable.h"

class RetourFonction : public Instruction{
public:
    friend std::ostream& operator<< (std::ostream& stream, const RetourFonction& retourFonction);

    void print(std::ostream& stream) const;

    RetourFonction &operator=(const RetourFonction &unRetourFonction);

    RetourFonction(const RetourFonction &unRetourFonction);

    RetourFonction(Variable* variable);

    virtual ~RetourFonction();

private:
    Variable * variable;
};
