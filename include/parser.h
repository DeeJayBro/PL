#ifndef PL_PARSER
#define PL_PARSER

#include <iostream>

namespace PL {

enum class TOKEN;

class Lexer;

class Parser {
  public:
    Parser(std::istream*);
    ~Parser();

    int parse();
  private:
    Lexer* lexer;
};

}

#endif
