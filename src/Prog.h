#pragma once

#include <iostream>
#include <cfenv>

#include "antlr4-runtime.h"
#include "../grammar/ProgBaseVisitor.h"
#include "Function.h"
#include "Type.h"
#include "Declaration.h"
#include "Programme.h"

using namespace std;

class Prog : public ProgBaseVisitor 
{
	public:


	antlrcpp::Any visitLprog(ProgParser::LprogContext *ctx) override
	{
        std::string some;
        Programme* programme = new Programme();
        for(auto i : ctx->decl()){
            programme->addDeclaration(visit(i));
        }
        for(auto i : ctx->fun()){
            programme->addFunction(visit(i));
        }
        cout << *programme;
		return programme;
	}

    antlrcpp::Any visitLbloc(ProgParser::LblocContext *ctx) override
    {
        Bloc* b = new Bloc();
        auto instructions = ctx->instr();
        for(auto i : instructions ){
            b->addInstruction((Declaration*)visit(i));
        }
        return b;
    }

    antlrcpp::Any visitLfun(ProgParser::LfunContext *ctx) override
    {
        Function* f = new Function(ctx->Name()->toString(), visit(ctx->bloc()));
        f->setDeclarations(visit(ctx->params()));
        return f;
    }

    antlrcpp::Any visitLparams(ProgParser::LparamsContext *ctx) override {
        std::list<Declaration*> params;
        for(auto it : ctx->param()){
            params.emplace_back((Declaration*)(visit(it)));
        }
        return params;
    }

    antlrcpp::Any visitLparam(ProgParser::LparamContext *ctx) override {
        Type type = getTypeFromString(ctx->type()->getText());
        Declaration * declaration = new Declaration(ctx->Name()->toString(), type);
        return declaration;
    }

    antlrcpp::Any visitLparamsVoid(ProgParser::LparamsVoidContext *ctx) override {
        std::list<Declaration*> params;
        return params;
    }

    antlrcpp::Any visitLparamsEpsilon(ProgParser::LparamsEpsilonContext *ctx) override {
        std::list<Declaration*> params;
        return params;
    }

    antlrcpp::Any visitLinstrDecl(ProgParser::LinstrDeclContext *ctx) override
    {
        return (Declaration*) visit(ctx->decl());
    }

    antlrcpp::Any visitLdecl(ProgParser::LdeclContext *ctx) override
    {
        Type type = getTypeFromString(ctx->type()->getText());
        Declaration* declaration = new Declaration(ctx->Name()->toString(), type);
        return declaration;
    }

    antlrcpp::Any visitLint32_t(ProgParser::Lint32_tContext *ctx) override {
        return visit(ctx);
    }

    antlrcpp::Any visitLint64_t(ProgParser::Lint64_tContext *ctx) override {
        return visit(ctx);
    }

    Type getTypeFromString(const std::string &str)
    {
        if(str == "void")
            return VOID;
        if(str == "char")
            return CHAR;
        if(str == "int32_t")
            return INT32_T;
        if(str == "int64_t")
            return INT64_T;
        return ERROR;
    }
};
