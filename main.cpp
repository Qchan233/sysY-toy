#include <iostream>
#include <any>
#include <map>

// #include "antlr4-runtime.h"
#include "SysYLexer.h"
#include "SysYParser.h"
#include "SysYParserBaseVisitor.h"

using namespace antlr4;


int main() {
    std::ifstream stream;
    stream.open("test.sysy");
    
    ANTLRInputStream input(stream);
    SysYLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    SysYParser parser(&tokens);    

    auto tree = parser.compUnit();
    SysYParserBaseVisitor visitor;

    return 0;
}
