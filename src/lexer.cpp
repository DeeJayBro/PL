#include "lexer.h"

#include <string>
#include <cctype>

namespace PL {

TOKEN Lexer::token_for(int ordinary) {
  if(ordinary == 0) return TOKEN::EOI;
  switch((char)ordinary) {
    case '+': return TOKEN::INC;        break;
    case '-': return TOKEN::DEC;        break;
    case '>': return TOKEN::MOVERIGHT;  break;
    case '<': return TOKEN::MOVELEFT;   break;
    case '[': return TOKEN::LBRACKET;   break;
    case ']': return TOKEN::RBRACKET;   break;
    case '.': return TOKEN::DOT;        break;
    case ',': return TOKEN::COMMA;      break;
    default:
      return (TOKEN)-1;
  }
}

TOKEN Lexer::lookahead() {
  if(this->input) {
    return token_for(this->input->peek());
  } else {
    return (TOKEN)-1;
  }
}

TOKEN Lexer::next_token() {
  if(this->input) {
    pos++;
    return token_for(this->input->get());
  } else {
    return (TOKEN)-1;
  }
}

}
