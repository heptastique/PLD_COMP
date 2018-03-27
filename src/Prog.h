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
#include "Affectation.h"
#include "OperationBinaire.h"
#include "OperationUnaire.h"
#include "While.h"
#include "If.h"
#include "Else.h"
#include "Initialisation.h"
#include "DeclarationTab.h"

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

    antlrcpp::Any visitLinstrInit(ProgParser::LinstrInitContext *ctx) override {
        Initialisation* initialisation = visit(ctx->init());
        return dynamic_cast<Instruction*> (initialisation);
    }

    antlrcpp::Any visitLinit(ProgParser::LinitContext *ctx) override {
        Type type = getTypeFromString(ctx->type()->getText());
        Expression* expression = visit(ctx->expr());
        Initialisation* initialisation = new Initialisation(type, expression, ctx->Name()->toString());
        return initialisation;
    }

    antlrcpp::Any visitLinstrDecl(ProgParser::LinstrDeclContext *ctx) override {
        Declaration* declaration = visit(ctx->decl());
        return dynamic_cast<Instruction*> (declaration);
    }

    antlrcpp::Any visitLdeclTable(ProgParser::LdeclTableContext *ctx) override {
        Type type = getTypeFromString(ctx->type()->getText());
        DeclarationTab* declarationTab = new DeclarationTab(ctx->Name()->toString(), type, ctx->Entier()->getText());
        return dynamic_cast<Declaration*> (declarationTab);
    }

    antlrcpp::Any visitLdecl(ProgParser::LdeclContext *ctx) override {
        Type type = getTypeFromString(ctx->type()->getText());
        Declaration* declaration = new Declaration(ctx->Name()->toString(), type);
        return declaration;
    }

    antlrcpp::Any visitLinstAppelfonct(ProgParser::LinstAppelfonctContext *ctx) override {
        AppelFunction* appelFunction = visit(ctx->appelfonct());
        return dynamic_cast<Instruction*> (appelFunction);
    }

    antlrcpp::Any visitLappelfonct(ProgParser::LappelfonctContext *ctx) override {
        std::list<Variable*> vars = visit(ctx->valeurs());
        AppelFunction* appelFunction = new AppelFunction(ctx->Name()->getText(), vars);
        return appelFunction;
    }

    antlrcpp::Any visitLinstRetourfonct(ProgParser::LinstRetourfonctContext *ctx) override {
        return (Instruction*) (visit(ctx->retourfonct()));
    }

    antlrcpp::Any visitLretourfonct(ProgParser::LretourfonctContext *ctx) override {
        Expression * expression = visit(ctx->expr());
        RetourFonction* retourFonction = new RetourFonction(expression);
        return dynamic_cast<Instruction*>(retourFonction);
    }

    antlrcpp::Any visitLinstAffectation(ProgParser::LinstAffectationContext *ctx) override {
        return (Instruction*) (visit(ctx->affectation()));
    }

    antlrcpp::Any visitLaffectation(ProgParser::LaffectationContext *ctx) override {
        Variable* var = (Variable*) visit(ctx->varleftpart());
        Operateur operateur = (Operateur) visit(ctx->operation());
        Expression* expression = (Expression*) visit(ctx->expr());
        Affectation* affection = new Affectation(var, operateur, expression);
        return dynamic_cast<Instruction*>(affection);
    }

    antlrcpp::Any visitLinsWhile(ProgParser::LinsWhileContext *ctx) override {
        return (Instruction*)(visit(ctx->inswhile()));
    }

    antlrcpp::Any visitLwhile(ProgParser::LwhileContext *ctx) override {
        Expression* condition = (Expression*) visit(ctx->expr());
        While* aWhile = new While(visit(ctx->bloc()), condition);
        return dynamic_cast<Instruction*>(aWhile);
    }

    antlrcpp::Any visitLinstIf(ProgParser::LinstIfContext *ctx) override {
        return (Instruction*)(visit(ctx->insif()));
    }

    antlrcpp::Any visitLif(ProgParser::LifContext *ctx) override {
        Expression* condition = (Expression*) visit(ctx->expr());
        If* anIf = new If(condition, visit(ctx->bloc()));
        if(ctx->inselse() != nullptr){
            anIf->setElse(visit(ctx->inselse()));
        }
        return dynamic_cast<Instruction*>(anIf);
    }

    antlrcpp::Any visitLelse(ProgParser::LelseContext *ctx) override {
        Else* anElse = new Else ((Bloc*)visit(ctx->bloc()));
        return anElse;
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

    antlrcpp::Any visitLvariablevarleftpart(ProgParser::LvariablevarleftpartContext *ctx) override {
        return (Variable*) visit(ctx->varleftpart());
    }

    antlrcpp::Any visitLvarleftpart(ProgParser::LvarleftpartContext *ctx) override {
        Variable* var = new Variable(NAME, ctx->Name()->getText());
        return var;
    }

    antlrcpp::Any visitLvariableEntier(ProgParser::LvariableEntierContext *ctx) override {
        Variable* variable = new Variable (ENTIER, ctx->Entier()->getText());
        return variable;
    }

    antlrcpp::Any visitLvariableCaractere(ProgParser::LvariableCaractereContext *ctx) override {
        Variable* variable = new Variable (CARACTERE, ctx->Caractere()->getText());
        return variable;
    }

    antlrcpp::Any visitLexprVariable(ProgParser::LexprVariableContext *ctx) override {
        Variable* var = visit(ctx->variable());
        return dynamic_cast<Expression*> (var);
    }

    antlrcpp::Any visitLexprAppelfonction(ProgParser::LexprAppelfonctionContext *ctx) override {
        AppelFunction* appelFunction = visit(ctx->appelfonct());
        return dynamic_cast<Expression*> (appelFunction);
    }

    antlrcpp::Any visitLexprOperationbinaire(ProgParser::LexprOperationbinaireContext *ctx) override {
        Expression* expressionL = visit(ctx->expr(0));
        Expression* expressionR = visit(ctx->expr(1));
        Operateur operateur = visit(ctx->operationbinaire());
        OperationBinaire* operationBinaire = new OperationBinaire(expressionL, expressionR, operateur);
        return static_cast<Expression*> (operationBinaire);
    }

    antlrcpp::Any visitLexprOperationunaire(ProgParser::LexprOperationunaireContext *ctx) override {
        Expression* expression = visit(ctx->expr());
        Operateur operateur = visit(ctx->operationunaire());
        OperationUnaire* operationUnaire = new OperationUnaire (operateur, expression);
        return static_cast<Expression*> (operationUnaire);
    }

    antlrcpp::Any visitLexprParentheses(ProgParser::LexprParenthesesContext *ctx) override {
        Expression* expression = visit(ctx->expr());
        return expression;
    }

    antlrcpp::Any visitLoperationEqual(ProgParser::LoperationEqualContext *ctx) override {
        return EQUAL;
    }

    antlrcpp::Any visitLoperationPlusequal(ProgParser::LoperationPlusequalContext *ctx) override {
        return PLUSEQUAL;
    }

    antlrcpp::Any visitLoperationMoinsequal(ProgParser::LoperationMoinsequalContext *ctx) override {
        return MINUSEQUAL;
    }

    antlrcpp::Any visitLoperationMultequal(ProgParser::LoperationMultequalContext *ctx) override {
        return MULTEQUAL;
    }

    antlrcpp::Any visitLoperationDivequal(ProgParser::LoperationDivequalContext *ctx) override {
        return DIVEQUAL;
    }

    antlrcpp::Any visitLoperationModequal(ProgParser::LoperationModequalContext *ctx) override {
        return MODEQUAL;
    }

    antlrcpp::Any visitLoperationXorbitwise(ProgParser::LoperationXorbitwiseContext *ctx) override {
        return XORBITWISE;
    }

    antlrcpp::Any visitLoperationAndbitwise(ProgParser::LoperationAndbitwiseContext *ctx) override {
        return ANDBITWISE;
    }

    antlrcpp::Any visitLoperationOrbitwise(ProgParser::LoperationOrbitwiseContext *ctx) override {
        return ORBITWISE;
    }

    antlrcpp::Any visitLoperationLeftshiftbitwise(ProgParser::LoperationLeftshiftbitwiseContext *ctx) override {
        return LESTSHIFTBITWISE;
    }

    antlrcpp::Any visitLoperationRightshiftbitwise(ProgParser::LoperationRightshiftbitwiseContext *ctx) override {
        return RIGHTSHIFTBITWISE;
    }

    antlrcpp::Any visitLoperationunaireMoins(ProgParser::LoperationunaireMoinsContext *ctx) override {
        return MINUSU;
    }

    antlrcpp::Any visitLoperationunaireNot(ProgParser::LoperationunaireNotContext *ctx) override {
        return NOT;
    }

    antlrcpp::Any visitLoperationbinairePlus(ProgParser::LoperationbinairePlusContext *ctx) override {
        return PLUS;
    }

    antlrcpp::Any visitLoperationbinaireMoins(ProgParser::LoperationbinaireMoinsContext *ctx) override {
        return MINUS;
    }

    antlrcpp::Any visitLoperationbinaireMult(ProgParser::LoperationbinaireMultContext *ctx) override {
        return MULT;
    }

    antlrcpp::Any visitLoperationbinaireDiv(ProgParser::LoperationbinaireDivContext *ctx) override {
        return DIV;
    }

    antlrcpp::Any visitLoperationbinaireMod(ProgParser::LoperationbinaireModContext *ctx) override {
        return MOD;
    }

    antlrcpp::Any visitLoperationbinaireEqual(ProgParser::LoperationbinaireEqualContext *ctx) override {
        return EQUALEQUAL;
    }

    antlrcpp::Any visitLoperationbinaireNotequal(ProgParser::LoperationbinaireNotequalContext *ctx) override {
        return NOTEQUAL;
    }

    antlrcpp::Any visitLoperationbinaireLt(ProgParser::LoperationbinaireLtContext *ctx) override {
        return LT;
    }

    antlrcpp::Any visitLoperationbinaireGt(ProgParser::LoperationbinaireGtContext *ctx) override {
        return GT;
    }

    antlrcpp::Any visitLoperationbinaireLte(ProgParser::LoperationbinaireLteContext *ctx) override {
        return LTE;
    }

    antlrcpp::Any visitLoperationbinaireGte(ProgParser::LoperationbinaireGteContext *ctx) override {
        return GTE;
    }

    antlrcpp::Any visitLoperationbinaireAnd(ProgParser::LoperationbinaireAndContext *ctx) override {
        return AND;
    }

    antlrcpp::Any visitLoperationbinaireOr(ProgParser::LoperationbinaireOrContext *ctx) override {
        return OR;
    }

    antlrcpp::Any visitLoperationbinaireAndbitwise(ProgParser::LoperationbinaireAndbitwiseContext *ctx) override {
        return ANDBB;
    }

    antlrcpp::Any visitLoperationbinaireOrbitwise(ProgParser::LoperationbinaireOrbitwiseContext *ctx) override {
        return ORBB;
    }

    antlrcpp::Any visitLoperationbinaireLeftshiftbiwise(ProgParser::LoperationbinaireLeftshiftbiwiseContext *ctx) override {
        return LEFTSHIFTBITWISEB;
    }

    antlrcpp::Any visitLoperationbinaireRightshiftbitwise(ProgParser::LoperationbinaireRightshiftbitwiseContext *ctx) override {
        return RIGHTSHIFTBITWISEB;
    }

    antlrcpp::Any visitLoperationbinaireXorbitwise(ProgParser::LoperationbinaireXorbitwiseContext *ctx) override {
        return XORBITWISEB;
    }

    antlrcpp::Any visitLint32_t(ProgParser::Lint32_tContext *ctx) override {
        return visit(ctx);
    }

    antlrcpp::Any visitLint64_t(ProgParser::Lint64_tContext *ctx) override {
        return visit(ctx);
    }

    Type getTypeFromString(const std::string &str) {
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
