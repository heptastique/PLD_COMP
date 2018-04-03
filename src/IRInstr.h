#pragma once

#include "ControlFlowGraph.h"

#include <string>
#include <vector>

using namespace std;

class ControlFlowGraph;

enum Mnemonique
{
    DECL = 0,
    RET = 1,
    CALL = 2,

    REG_STORE = 3,
    STACK_STORE = 4,
    PUSH = 5,
    PUSH_REL = 6,

    ADD_SP = 10,

    AFFECTATION = 40,
    BINARYOPERATION= 41,
    UNARYOPERATION= 42,

    PUTCHAR = 100
};

class IRInstr
{
    public:
        Mnemonique getMnemonique() const;

        string getParam(int index) const;
        vector <string> getParams() const;

        IRInstr(const IRInstr & iRInstr);

        IRInstr();

        IRInstr(Mnemonique mnemonique, vector <string> params);

        virtual ~IRInstr();

    private:
        ControlFlowGraph * controlFlowGraph;
        Mnemonique mnemonique;
        vector <string> params;
};
