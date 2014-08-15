/* calc/parser.y */

%code top {
#include <math.h>
#include <stdio.h>
#include "yyctx.hpp"
}

%define api.pure full
%defines "parser.hh"
%define parse.error verbose
%lex-param { void*scanner }
%parse-param { yyctx*context } /* YYSTYPE == yyctx */

%define api.value.type { yyctx }
%token <u.dval> NUM "double"
%token <u.sval> STR "string"

%type <u.dval> exp

%left '-' '+'
%left '*' '/'
%precedence NEG
%right '^'

%code {
    int yylex( YYSTYPE*lvalp, void*scanner );

    void yyerror( YYSTYPE*lvalp, char const*msg )
    {
        fprintf( stderr, "%s\n", msg );
    }

#define scanner (context->scanner_)
 }

%%

input: %empty
     | input line
     ;

line: '\n'
    | exp '\n' { printf( "\t%.10g\n", $1 ); }
    ;

exp : NUM               { $$ = $1            ; }
    | exp '+' exp       { $$ = $1 + $3       ; }
    | exp '-' exp       { $$ = $1 - $3       ; }
    | exp '*' exp       { $$ = $1 * $3       ; }
    | exp '/' exp       { $$ = $1 / $3       ; }
    | '-' exp %prec NEG { $$ = -$2           ; }
    | exp '^' exp       { $$ = pow( $1, $3 ) ; }
    | '(' exp ')'       { $$ = $2            ; }
    ;
