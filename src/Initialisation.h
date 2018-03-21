#pragma once

#include "Instruction.h"

class Initialisation : public Instruction {

public:

    Initialisation &operator=(const Initialisation &unInitialisation);

    Initialisation(const Initialisation &unInitialisation);

    Initialisation();

    virtual ~Initialisation();

};
