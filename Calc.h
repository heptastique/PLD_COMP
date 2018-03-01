#pragma once

#include "antlr4-runtime.h"
#include "ExprBaseVisitor.h"

using namespace std;

class Calc : public ExprBaseVisitor {
public:
    antlrcpp::Any visitProg(ExprParser::ProgContext *ctx) override {
        return (int) visit(ctx->expr());
    }

    antlrcpp::Any visitAdd (ExprParser::AddContext *ctx) override {
        return (int) visit(ctx->expr(0)) + (int) visit(ctx->expr(1));
    }

    antlrcpp::Any visitMoins (ExprParser::MoinsContext *ctx) override {
        return (int) visit(ctx->expr(0)) - (int) visit(ctx->expr(1));
    }

    antlrcpp::Any visitMult (ExprParser::MultContext *ctx) override {
        return (int) visit(ctx->expr(0)) * (int) visit(ctx->expr(1));
    }

    antlrcpp::Any visitPar (ExprParser::ParContext *ctx) override {
        return (int) visit(ctx->expr());
    }

    antlrcpp::Any visitDiv(ExprParser::DivContext *ctx) override {
        return (int) visit(ctx->expr(0)) / (int) visit(ctx->expr(1));
    }

    /*
    les autres
    opérations sont
    identiques */

    virtual antlrcpp::Any visitConst(ExprParser::ConstContext *ctx) override {
        return (int) stoi(ctx->INT()->getText());
    }
};