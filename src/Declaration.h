#pragma once

#include "Instruction.h"
#include "Type.h"
//# include "ControlFlowGraph.h"

#include <string>

//class ControlFlowGraph;

class Declaration : public Instruction {

public:

	//void generateIR(ControlFlowGraph * controlFlowGraph);

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
