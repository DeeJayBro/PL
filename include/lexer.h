#ifndef PL_LEXER
#define PL_LEXER
#include <iostream>

namespace PL {

enum class TOKEN {
  INC,
  DEC,
  MOVERIGHT,
  MOVELEFT,
  LBRACKET,
  RBRACKET,
  DOT,
  COMMA,
  EOI
};

class Lexer {
  public:
    Lexer(std::istream* input): input(input), pos(0) {};
    ~Lexer() {};

    TOKEN lookahead();
    TOKEN next_token();
  private:
    TOKEN token_for(int character);
    std::istream* input;
    unsigned int pos;
};

}

#endif
