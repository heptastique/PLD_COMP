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
    STORE_RBP_REL = 4,
    PUSH_VALUE = 5,
    PUSH_RBP_REL = 6,

    ADD_RSP = 10,
    SUB_RSP = 11,

    MOV_REG_RBP_REL = 20,
    MOV_RBP_REL_REG = 21,

    COMPJUMP = 30,
    LABEL = 31,
    RETIF = 32,
    COMPJUMPEQUALS = 33,

    AFFECTATION = 40,
    BINARYOPERATION= 41,
    UNARYOPERATION= 42,
    ADD = 13,
    PREINCIR = 50,
    PREDECIR = 51,
    POSINCIR = 52,
    POSDECIR = 53,
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
