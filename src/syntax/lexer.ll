%{ /* -*- C++ -*- */
  
using token = yy::Parser::token;
#define YYSTYPE int
%}

%option noyywrap nounput nodefault warn yylineno

%{
    #define YY_USER_ACTION driver->loc->columns(yyleng);
    #define YY_DO_BEFORE_ACTION \
	(yytext_ptr) = yy_bp; \
	yyleng = (int) (yy_cp - yy_bp); \
	(yy_hold_char) = *yy_cp; \
	*yy_cp = '\0'; \
	(yy_c_buf_p) = yy_cp;
	#define yywrap() (/*CONSTCOND*/1)
	#define YY_NEW_FILE yyrestart( yyin  )
%}

%%

%{
    driver->loc->step();
%}

<<EOF>>                 { return token::END; }
%%
