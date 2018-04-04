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
    STORE_RBP_REL_RSP = 4,
    STORE_VALUE_RBP_REL = 5,
    STORE_RBP_REL_REG = 6,
    STORE_REG_RSP = 7,

    PUSH_VALUE = 8,
    PUSH_RBP_REL = 9,

    ADD_RSP = 10,
    SUB_RSP = 11,

    AFFECTATION = 40,
    BINARYOPERATION= 41,
    UNARYOPERATION= 42,

    PUTCHAR_VALUE = 100,
    PUTCHAR_RBP_REL = 101
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
