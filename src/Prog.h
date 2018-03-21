#pragma once

#include <iostream>
#include <cfenv>

#include "antlr4-runtime.h"
#include "../grammar/ProgBaseVisitor.h"
#include "Function.h"
#include "Type.h"
#include "Declaration.h"
#include "Programme.h"
#include "AppelFunction.h"
#include "RetourFonction.h"

using namespace std;

class Prog : public ProgBaseVisitor 
{
	public:


	antlrcpp::Any visitLprog(ProgParser::LprogContext *ctx) override
	{
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
            b->addInstruction(visit(i));
        }
        return b;
    }

    antlrcpp::Any visitLfun(ProgParser::LfunContext *ctx) override
    {
        Type type = visit(ctx->typeretour());
        Function* f = new Function(ctx->Name()->toString(), visit(ctx->bloc()),type);
        f->setDeclarations(visit(ctx->params()));
        return f;
    }

    antlrcpp::Any visitLparams(ProgParser::LparamsContext *ctx) override {
        std::list<Declaration*> params;
        for(auto it : ctx->param()){
            params.emplace_back(visit(it));
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

    antlrcpp::Any visitLtyperetourVoid(ProgParser::LtyperetourVoidContext *ctx) override {
        return VOID;
    }

    antlrcpp::Any visitLtype(ProgParser::LtypeContext *ctx) override {
        return getTypeFromString(ctx->type()->getText());
    }

    antlrcpp::Any visitLinstrDecl(ProgParser::LinstrDeclContext *ctx) override {
        Declaration* declaration = visit(ctx->decl());
        return dynamic_cast<Instruction*> (declaration);
    }

    antlrcpp::Any visitLdecl(ProgParser::LdeclContext *ctx) override {
        Type type = getTypeFromString(ctx->type()->getText());
        Declaration* declaration = new Declaration(ctx->Name()->toString(), type);
        return declaration;
    }

    antlrcpp::Any visitLinstAppelfonct(ProgParser::LinstAppelfonctContext *ctx) override {
        return (Instruction*) (visit(ctx->appelfonct()));
    }

    antlrcpp::Any visitLappelfonct(ProgParser::LappelfonctContext *ctx) override {
        std::list<Variable*> vars = visit(ctx->valeurs());
        AppelFunction* appelFunction = new AppelFunction(ctx->Name()->getText(), vars);
        return dynamic_cast<Instruction*>(appelFunction);
    }

    antlrcpp::Any visitLinstRetourfonct(ProgParser::LinstRetourfonctContext *ctx) override {
        return (Instruction*) (visit(ctx->retourfonct()));
    }

    antlrcpp::Any visitLretourfonct(ProgParser::LretourfonctContext *ctx) override {
        Variable * var = visit(ctx->variable());
        RetourFonction* retourFonction = new RetourFonction(var);
        return dynamic_cast<Instruction*>(retourFonction);
    }



    antlrcpp::Any visitLvaleurs(ProgParser::LvaleursContext *ctx) override {
        std::list<Variable*> vars;
        for(auto it : ctx->variable()){
            vars.emplace_back(visit(it));
        }
        return vars;
    }

    antlrcpp::Any visitLvaleursEpsilon(ProgParser::LvaleursEpsilonContext *ctx) override {
        std::list<Variable*> vars;
        return vars;
    }

    antlrcpp::Any visitLvariableName(ProgParser::LvariableNameContext *ctx) override {
        Variable* variable = new Variable (NAME, ctx->Name()->getText());
        return variable;
    }

    antlrcpp::Any visitLvariableEntier(ProgParser::LvariableEntierContext *ctx) override {
        Variable* variable = new Variable (ENTIER, ctx->Entier()->getText());
        return variable;
    }

    antlrcpp::Any visitLvariableCaractere(ProgParser::LvariableCaractereContext *ctx) override {
        Variable* variable = new Variable (CARACTERE, ctx->Caractere()->getText());
        return variable;
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
