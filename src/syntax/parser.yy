%skeleton "lalr1.cc"
%require "3.0.4"
%defines
%define api.pure
%define api.location.type {}
%define parser_class_name {Parser}
%code requires
{
};

};

}
%param {}
%locations
%define parse.error verbose
%code
{

YY_DECL;
int yyparse();
void yyerror(const char * msg);
}

%union {

}

%pure-parser

%token END 0 "end of file"

%printer { yyoutput << $$; } <*>;

%start root
%%
root:

%%
