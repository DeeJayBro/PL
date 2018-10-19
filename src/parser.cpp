#include "parser.h"
#include "lexer.h"


namespace PL {

Parser::Parser(std::istream* input) {
  this->lexer = new Lexer(input);
}

Parser::~Parser() {
  delete this->lexer;
}

int Parser::parse() {
  return -1;
}

}
