#pragma once

#include "ControlFlowGraph.h"

#include <iostream>
#include <vector>

using namespace std;

class ControlFlowGraph;

class IR
{
    public:
        void generateASM(ostream & os) const;

        void addControlFlowGraph(ControlFlowGraph * controlFlowGraph);

        vector <ControlFlowGraph*> getControlFlowGraphs() const;

        IR();
        IR(const IR & iR);
        IR(vector <ControlFlowGraph*> controlFlowGraphs);

        virtual ~IR();

    private:
        vector <ControlFlowGraph*> controlFlowGraphs;
};
