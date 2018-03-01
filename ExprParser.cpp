
// Generated from Expr.g4 by ANTLR 4.7.1


#include "ExprVisitor.h"

#include "ExprParser.h"


using namespace antlrcpp;
using namespace antlr4;

ExprParser::ExprParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

ExprParser::~ExprParser() {
  delete _interpreter;
}

std::string ExprParser::getGrammarFileName() const {
  return "Expr.g4";
}

const std::vector<std::string>& ExprParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& ExprParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgContext ------------------------------------------------------------------

ExprParser::ProgContext::ProgContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExprParser::ExprContext* ExprParser::ProgContext::expr() {
  return getRuleContext<ExprParser::ExprContext>(0);
}


size_t ExprParser::ProgContext::getRuleIndex() const {
  return ExprParser::RuleProg;
}

antlrcpp::Any ExprParser::ProgContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitProg(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::ProgContext* ExprParser::prog() {
  ProgContext *_localctx = _tracker.createInstance<ProgContext>(_ctx, getState());
  enterRule(_localctx, 0, ExprParser::RuleProg);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(4);
    expr(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

ExprParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t ExprParser::ExprContext::getRuleIndex() const {
  return ExprParser::RuleExpr;
}

void ExprParser::ExprContext::copyFrom(ExprContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ParContext ------------------------------------------------------------------

ExprParser::ExprContext* ExprParser::ParContext::expr() {
  return getRuleContext<ExprParser::ExprContext>(0);
}

ExprParser::ParContext::ParContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any ExprParser::ParContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitPar(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DivContext ------------------------------------------------------------------

std::vector<ExprParser::ExprContext *> ExprParser::DivContext::expr() {
  return getRuleContexts<ExprParser::ExprContext>();
}

ExprParser::ExprContext* ExprParser::DivContext::expr(size_t i) {
  return getRuleContext<ExprParser::ExprContext>(i);
}

ExprParser::DivContext::DivContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any ExprParser::DivContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitDiv(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AddContext ------------------------------------------------------------------

std::vector<ExprParser::ExprContext *> ExprParser::AddContext::expr() {
  return getRuleContexts<ExprParser::ExprContext>();
}

ExprParser::ExprContext* ExprParser::AddContext::expr(size_t i) {
  return getRuleContext<ExprParser::ExprContext>(i);
}

ExprParser::AddContext::AddContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any ExprParser::AddContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitAdd(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MultContext ------------------------------------------------------------------

std::vector<ExprParser::ExprContext *> ExprParser::MultContext::expr() {
  return getRuleContexts<ExprParser::ExprContext>();
}

ExprParser::ExprContext* ExprParser::MultContext::expr(size_t i) {
  return getRuleContext<ExprParser::ExprContext>(i);
}

ExprParser::MultContext::MultContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any ExprParser::MultContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitMult(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ConstContext ------------------------------------------------------------------

tree::TerminalNode* ExprParser::ConstContext::INT() {
  return getToken(ExprParser::INT, 0);
}

ExprParser::ConstContext::ConstContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any ExprParser::ConstContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitConst(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MoinsContext ------------------------------------------------------------------

std::vector<ExprParser::ExprContext *> ExprParser::MoinsContext::expr() {
  return getRuleContexts<ExprParser::ExprContext>();
}

ExprParser::ExprContext* ExprParser::MoinsContext::expr(size_t i) {
  return getRuleContext<ExprParser::ExprContext>(i);
}

ExprParser::MoinsContext::MoinsContext(ExprContext *ctx) { copyFrom(ctx); }

antlrcpp::Any ExprParser::MoinsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitMoins(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::ExprContext* ExprParser::expr() {
   return expr(0);
}

ExprParser::ExprContext* ExprParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  ExprParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  ExprParser::ExprContext *previousContext = _localctx;
  size_t startState = 2;
  enterRecursionRule(_localctx, 2, ExprParser::RuleExpr, precedence);

    

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(12);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ExprParser::INT: {
        _localctx = _tracker.createInstance<ConstContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(7);
        match(ExprParser::INT);
        break;
      }

      case ExprParser::T__4: {
        _localctx = _tracker.createInstance<ParContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(8);
        match(ExprParser::T__4);
        setState(9);
        expr(0);
        setState(10);
        match(ExprParser::T__5);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(28);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(26);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<MultContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(14);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(15);
          match(ExprParser::T__0);
          setState(16);
          expr(7);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<DivContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(17);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(18);
          match(ExprParser::T__1);
          setState(19);
          expr(6);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<AddContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(20);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(21);
          match(ExprParser::T__2);
          setState(22);
          expr(5);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<MoinsContext>(_tracker.createInstance<ExprContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpr);
          setState(23);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(24);
          match(ExprParser::T__3);
          setState(25);
          expr(4);
          break;
        }

        } 
      }
      setState(30);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

bool ExprParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 1: return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool ExprParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 6);
    case 1: return precpred(_ctx, 5);
    case 2: return precpred(_ctx, 4);
    case 3: return precpred(_ctx, 3);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> ExprParser::_decisionToDFA;
atn::PredictionContextCache ExprParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN ExprParser::_atn;
std::vector<uint16_t> ExprParser::_serializedATN;

std::vector<std::string> ExprParser::_ruleNames = {
  "prog", "expr"
};

std::vector<std::string> ExprParser::_literalNames = {
  "", "'*'", "'/'", "'+'", "'-'", "'('", "')'"
};

std::vector<std::string> ExprParser::_symbolicNames = {
  "", "", "", "", "", "", "", "INT"
};

dfa::Vocabulary ExprParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> ExprParser::_tokenNames;

ExprParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x9, 0x22, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 
    0x3, 0xf, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x7, 0x3, 0x1d, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x20, 0xb, 0x3, 0x3, 0x3, 
    0x2, 0x3, 0x4, 0x4, 0x2, 0x4, 0x2, 0x2, 0x2, 0x24, 0x2, 0x6, 0x3, 0x2, 
    0x2, 0x2, 0x4, 0xe, 0x3, 0x2, 0x2, 0x2, 0x6, 0x7, 0x5, 0x4, 0x3, 0x2, 
    0x7, 0x3, 0x3, 0x2, 0x2, 0x2, 0x8, 0x9, 0x8, 0x3, 0x1, 0x2, 0x9, 0xf, 
    0x7, 0x9, 0x2, 0x2, 0xa, 0xb, 0x7, 0x7, 0x2, 0x2, 0xb, 0xc, 0x5, 0x4, 
    0x3, 0x2, 0xc, 0xd, 0x7, 0x8, 0x2, 0x2, 0xd, 0xf, 0x3, 0x2, 0x2, 0x2, 
    0xe, 0x8, 0x3, 0x2, 0x2, 0x2, 0xe, 0xa, 0x3, 0x2, 0x2, 0x2, 0xf, 0x1e, 
    0x3, 0x2, 0x2, 0x2, 0x10, 0x11, 0xc, 0x8, 0x2, 0x2, 0x11, 0x12, 0x7, 
    0x3, 0x2, 0x2, 0x12, 0x1d, 0x5, 0x4, 0x3, 0x9, 0x13, 0x14, 0xc, 0x7, 
    0x2, 0x2, 0x14, 0x15, 0x7, 0x4, 0x2, 0x2, 0x15, 0x1d, 0x5, 0x4, 0x3, 
    0x8, 0x16, 0x17, 0xc, 0x6, 0x2, 0x2, 0x17, 0x18, 0x7, 0x5, 0x2, 0x2, 
    0x18, 0x1d, 0x5, 0x4, 0x3, 0x7, 0x19, 0x1a, 0xc, 0x5, 0x2, 0x2, 0x1a, 
    0x1b, 0x7, 0x6, 0x2, 0x2, 0x1b, 0x1d, 0x5, 0x4, 0x3, 0x6, 0x1c, 0x10, 
    0x3, 0x2, 0x2, 0x2, 0x1c, 0x13, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x16, 0x3, 
    0x2, 0x2, 0x2, 0x1c, 0x19, 0x3, 0x2, 0x2, 0x2, 0x1d, 0x20, 0x3, 0x2, 
    0x2, 0x2, 0x1e, 0x1c, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x1f, 0x3, 0x2, 0x2, 
    0x2, 0x1f, 0x5, 0x3, 0x2, 0x2, 0x2, 0x20, 0x1e, 0x3, 0x2, 0x2, 0x2, 
    0x5, 0xe, 0x1c, 0x1e, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

ExprParser::Initializer ExprParser::_init;
