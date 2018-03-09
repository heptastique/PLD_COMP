#include <iostream>
#include "grammar/ExprLexer.h"
#include "grammar/ExprParser.h"
#include "grammar/ExprBaseVisitor.h"
#include "src/Calc.h"
#include "antlr4-runtime.h"

using namespace antlr4;
using namespace std;

int main(int argc, char* argv[]) {
    ifstream inputFile;
    
    inputFile.open (argv[1]);
    
    string contenu;
    string ligne;
    
    if (inputFile)
    {       
        while ( getline (inputFile, ligne) )
        {
            contenu = contenu + ligne; 
        }
    }
                
    inputFile.close();

    ANTLRInputStream input(contenu);
    ExprLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    ExprParser parser(&tokens);
    tree::ParseTree *tree = parser.prog();
    Calc visitor;
    int resultat = (int) visitor.visit(tree);
    cout << resultat << endl;
    return 0;
}