#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "../lib/catch.hpp"
#include "../../src/Bloc.h"
#include "../../src/Type.h"
#include "../../src/Declaration.h"

Instruction* AddInstruction(Instruction* inst){
    Bloc* b = new Bloc();

    b->addInstruction(inst);

    std::list<Instruction*> list = b->getInstructions();

    return list.front();
}

TEST_CASE("Instruction is added","[bloc]" ) {
    Instruction * inst = new Declaration("name",CHAR);
    REQUIRE ( AddInstruction(inst) == inst);
}