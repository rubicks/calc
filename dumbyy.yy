/* calc/dumbyy.yy */

%code top {
/* dumbyy.yy code top BEGIN */
#include <cmath>
#include <iostream>
#include "dumbctx.hh"
    void
    _assign( dumbctx_t&ctx,
             dumbctx_t&res,
             dumbctx_t&arg )
    {
        ctx.value_ = res.value_ = arg.value_ ;
    }
/* dumbyy.yy code top END */
 }

%require "3.0.2"
%define api.pure full
%defines "dumbyy.hh"
%output  "dumbyy.cc"
%define parse.error verbose
%lex-param { void*scanner }
%parse-param { dumbctx_t*context } /* YYSTYPE == dumbctx_t */

%define api.value.type { dumbctx_t }
%token NUM
%left '-' '+'
%left '*' '/'
%precedence NEG
%right '^'

%code {
/* dumbyy.yy code BEGIN */
    int yylex( YYSTYPE*lvalp, void*scanner );
    void yyerror( YYSTYPE*lvalp, char const*msg ){
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
/* dumbyy.yy code END */
 }

%%

/* input: %empty */
/*      | input line */
/*      ; */

/* line: '\n' */
/*     | exp '\n' { std::cout << $1 << std::endl ; } */
/*     ; */

input: %empty
     | exp              { _assign( *context, $$, $1 ); }
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
