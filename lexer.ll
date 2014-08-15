/* calc/lexer.ll */

%{
#include "yyctx.hpp"
#include "parser.hh"
%}

%option reentrant
%option bison-bridge
%option noyywrap
%option header-file="lexer.hh"
%option outfile="lexer.cc"

%%

[0-9]+     { yylval->u.dval = atof( yytext ); return NUM ; }

[-+()*\n=] { yylval->u.sval = yytext ; return STR ; }

[ \t]      ;

.          { yyerror( yylval, "Unknown character"); }

%%
