#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "../lib/catch.hpp"
#include "../../src/Bloc.h"
#include "../../src/Type.h"
#include "../../src/Declaration.h"

Instruction* AddInstruction(std::vector<Instruction*> insts){
    Bloc* b = new Bloc();

    b->addInstructions(insts);

    std::vector<Instruction*> list = b->getInstructions();

    return list.front();
}

TEST_CASE("Instruction is added","[bloc]" ) {
    Instruction * inst = new Declaration("name",CHAR);
    std::vector<Instruction*> insts;
    insts.emplace_back(inst);
    REQUIRE ( AddInstruction(insts) == inst);
}