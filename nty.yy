/* calc/nty.yy */

%code top {
/* nty.yy code top BEGIN */
#include <cmath>
#include <iostream>
#include "ntctx.hpp"
/* nty.yy code top END */
 }

%define api.pure full
%defines "nty.hh"
%output  "nty.cc"
%define parse.error verbose
%lex-param { void*scanner }
%parse-param { ntctx*context } /* YYSTYPE == ntctx */

%define api.value.type { ntctx }
%token <u.dval> REAL    //"double"
%token <u.ival> INTEGER //"long"
%token <u.cval> CHAR    //"long"
%token <u.sval> STR     //"string"

%token <u.cval> PLUS     '+'
%token <u.cval> MINUS    '-'
%token <u.cval> MULTIPLY '*'
%token <u.cval> DIVIDE   '/'
%token <u.cval> EXPONENT '^'

%type <u.dval> exp

%left '-' '+'
%left '*' '/'
%precedence NEG
%right '^'

%code {
/* nty.yy code BEGIN */
    int yylex( YYSTYPE*lvalp, void*scanner );
    int yyerror( YYSTYPE*lvalp, char const*msg ){
        std::cerr
            << std::endl
            << __PRETTY_FUNCTION__
            << std::endl
            << "YYSTYPE*lvalp == "
            << std::hex << std::showbase
            << reinterpret_cast< unsigned long >( lvalp )
            << std::endl
            << "msg == \"" << msg << "\""
            << std::endl
            ;
    }
#define scanner (context->scanner_)
/* nty.yy code END */
 }

%%

input: %empty
     | input line
     ;

line: '\n'
    | exp '\n' { printf( "\t%.10g\n", $1 ); }
    ;

exp : REAL              { $$ = $1            ; }
    | exp '+' exp       { $$ = $1 + $3       ; }
    | exp '-' exp       { $$ = $1 - $3       ; }
    | exp '*' exp       { $$ = $1 * $3       ; }
    | exp '/' exp       { $$ = $1 / $3       ; }
    | '-' exp %prec NEG { $$ = -$2           ; }
    | exp '^' exp       { $$ = pow( $1, $3 ) ; }
    | '(' exp ')'       { $$ = $2            ; }
    ;
