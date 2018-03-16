#include <sys/stat.h>
#include <iostream>

#include "antlr4-runtime.h"

#include "grammar/ProgLexer.h"
#include "grammar/ProgParser.h"
#include "grammar/ProgBaseVisitor.h"
#include "src/Prog.h"

using namespace antlr4;
using namespace std;

int main(int argc, const char *argv[])
{
	char * fileContent;
	long fileSize;

	FILE * file;

	//check if input is given
	if(argc<2)
	{
		cout<<"No input file given"<<endl;
		return -1;
	}

	file= fopen(argv[1], "rb");

	fseek(file, 0, SEEK_END);
	fileSize = ftell(file);
	rewind(file);

	fileContent = (char *) malloc((fileSize + 1) * (sizeof(char)));
	fread(fileContent, sizeof(char), fileSize, file);

	fileContent[fileSize] = '\0';

	fclose(file);

	ANTLRInputStream input(fileContent);
	ProgLexer lexer(&input);
	CommonTokenStream tokens(&lexer);
	ProgParser parser(&tokens);
	tree::ParseTree * tree = parser.prog();

	Prog visitor;

	visitor.visit(tree);
	cout << "Ok" << endl;

	return 0;
}
