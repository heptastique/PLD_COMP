#include <iostream>
#include "ExprLexer.h"
#include "ExprParser.h"
#include "ExprBaseVisitor.h"
#include "Calc.h"
#include "antlr4-runtime.h"

using namespace antlr4;
using namespace std;

int main(int, const char **) {
    ANTLRInputStream input("3*7");
    ExprLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    ExprParser parser(&tokens);
    tree::ParseTree *tree = parser.prog();
    Calc visitor;
    int resultat = (int) visitor.visit(tree);
    cout << "Résultat " << resultat << endl;
    return 0;
}