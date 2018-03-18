#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "../lib/catch.hpp"
#include "../../src/Bloc.h"
#include <string>
#include <iostream>
#include "../../src/Type.h"
#include "../../src/Declaration.h"

std::string AddInstruction(){
    Bloc* b = new Bloc();
    Instruction * inst = new Declaration("name",CHAR);
    b->addInstruction(inst);
    std::ostringstream stream;
    stream << *b;
    return stream.str();
}

TEST_CASE("Instruction is added","[bloc]" ) {
    REQUIRE ( AddInstruction() == "     Bloc:\n     Instruction: Declaration: Name=name Type=3\n\n");
}