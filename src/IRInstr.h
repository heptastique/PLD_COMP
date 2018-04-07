#pragma once

#include "ControlFlowGraph.h"

#include <string>
#include <vector>

using namespace std;

class ControlFlowGraph;

enum Mnemonique
{
    // Function
    PROLOG = 0,
    EPILOG = 1,
    CALL = 2,

    // MOV
    MOV_VALUE_RBP_REL = 10,
    MOV_REG_RBP_REL = 11,
    MOV_RBP_REL_REG = 12,
    MOV_RBP_REL_RBP_REl = 13,

    // Stack
    PUSH_VALUE = 20,
    PUSH_RBP_REL = 21,
    ADD_RSP = 22,
    SUB_RSP = 23,

    // Conditions
    COMPJUMP = 30,
    COMPJUMPEQUALS = 31,
    LABEL = 32,
    RETIF = 33,

    // Operations
    BINARYOPERATION= 41,
    UNARYOPERATION= 42,
    PREINCIR = 43,
    PREDECIR = 44,
    POSINCIR = 45,
    POSDECIR = 46,
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
