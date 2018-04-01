# pragma once

# include "IRInstr.h"
# include <string>
# include <vector>

using namespace std;

class IRInstr;

class BasicBlock
{
    public:
        vector <IRInstr> getIRInstrs() const;

        void addIRInstr(IRInstr iRInstr);

        void generateASM();

        BasicBlock(const BasicBlock & basicBlock);

        BasicBlock();

        virtual ~BasicBlock();

    private:
        vector <IRInstr> iRInstrs;
        BasicBlock * successor;
        BasicBlock * condSuccessor;
};
