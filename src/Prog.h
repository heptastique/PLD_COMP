#pragma once

# include <iostream>

#include "antlr4-runtime.h"
#include "../grammar/ProgBaseVisitor.h"

using namespace std;

class Prog : public ProgBaseVisitor 
{
	public:

		antlrcpp::Any visitProg(ProgParser::ProgContext *ctx) override 
		{
			cout << "VisitProg" << endl;
			return visitChildren(ctx);
		}

};
