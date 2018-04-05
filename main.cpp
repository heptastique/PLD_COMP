#include <sys/stat.h>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <cstdio>
#include <array>

#include <gflags/gflags.h>

#include "antlr4-runtime.h"

#include "grammar/ProgLexer.h"
#include "grammar/ProgParser.h"
#include "grammar/ProgBaseVisitor.h"
#include "src/Prog.h"
#include "src/ControlFlowGraph.h"
#include "src/IR.h"

using namespace antlr4;
using namespace std;

DEFINE_bool(o, false, "generate binary executable");
DEFINE_string(Sout, "./target/prog.s", "generated asm path");
DEFINE_string(oout, "./target/prog.out", "generate binary executable to specified path");

std::string exec(const char *);

int main (int argc, char * argv[])
{
    /*
        Input C Programm
    */

    google::ParseCommandLineFlags(&argc, &argv, true);

    cout << "Reading C Program" << endl;

    char * fileContent;
    long fileSize;

    FILE * file;

    // check if input is given
    if (argc < 2)
    {
        cout << "No input file given" << endl;
        return -1;
    }

    struct stat fileStat;
    const char * fileName = argv[1];

    if (stat(fileName, &fileStat) < 0)
    {
        switch (errno)
        {
            case EACCES :
                cout << "Search permission is denied for a component of the path prefix." << endl;
                return EACCES;
            case EIO :
                cout << "An error occurred while reading from the file system" << endl;
                return EIO;
            case ELOOP :
                cout << "Too many symbolic links were encountered in resolving path." << endl;
                return ELOOP;
            case ENAMETOOLONG :
                cout << "The length of the path argument exceeds {PATH_MAX} or"
                    " a pathname component is longer than {NAME_MAX}." << endl;
                return ENAMETOOLONG;
            case ENOENT :
                cout << "A component of path does not name an existing file." << endl;
                return ENOENT;
            case ENOTDIR :
                cout << "A component of the path prefix is not a directory." << endl;
                return ENOTDIR;
            case EOVERFLOW :
                cout << "The file size in bytes or the number of blocks allocated to the file or the file"
                    " serial number cannot be represented correctly in the structure pointed to by buf." << endl;
                return EOVERFLOW;
            default :
                // noerror
                break;
        }
    }

    file = fopen(argv[1], "rb");

    fseek(file, 0, SEEK_END);
    fileSize = ftell(file);
    rewind(file);

    fileContent = (char *) malloc((fileSize + 1) * (sizeof(char)));
    fread(fileContent, sizeof(char), fileSize, file);

    fileContent[fileSize] = '\0';

    fclose(file);

    cout << "C Program read" << endl;

    /*
        C Program -> C++ Memory Representation
    */

    cout << "Generating Abstract Syntaxic Tree" << endl;

    ANTLRInputStream input(fileContent);
    ProgLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    ProgParser parser(&tokens);
    tree::ParseTree * tree = parser.prog();

    Prog visitor;

    Programme * programme = visitor.visit(tree);

    cout << "Fin" << endl;
    cout << "Abstract Syntaxic Tree generated" << endl;

    /*

     * Variables scope resolution

    */

    programme->resolveScopeVariables();

    programme->resolveTypeExpr();

    /*
        C++ Memory Representation -> Intermediate Representation
    */

    cout << "Generating Intermediate Representation" << endl;

    // Generate IR from Abstract Syntaxic Tree

    IR iR = programme->generateIR();

    cout << "Intermediate Representation generated" << endl;

    /*
        Intermediate Representation -> Assembly
    */

    cout << "Generating Assembly" << endl;

    ofstream aSMFile;

    aSMFile.open(FLAGS_Sout);

    if (aSMFile.bad() || aSMFile.fail() || !aSMFile.good())
    {
        cout << "Failed to open prog.s" << endl;
    }

    // Generate ASM from IR

    iR.generateASM(aSMFile);

    aSMFile.close();

    cout << "Assembly generated in "<< FLAGS_Sout << endl;

    if(FLAGS_o || FLAGS_oout != "./target/prog.out")
    {
        const std::string assemble("as -o ./prog.o " + FLAGS_Sout);
        const std::string compile("gcc -o " + FLAGS_oout + " ./prog.o");
        cout << exec(assemble.c_str()) << endl;
        cout << exec(compile.c_str()) << endl;
        exec("rm ./prog.o"); 
        cout << "Executable generated in " << FLAGS_oout << endl;
    }

    return 0;
}

std::string exec(const char* cmd) 
{
    std::array<char, 128> buffer;
    std::string result;
    std::shared_ptr<FILE> pipe(popen(cmd, "r"), pclose);
    if (!pipe) throw std::runtime_error("popen() failed!");
    while (!feof(pipe.get())) {
        if (fgets(buffer.data(), 128, pipe.get()) != nullptr)
            result += buffer.data();
    }
    return result;
}
