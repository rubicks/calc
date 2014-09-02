/* calc/dumbll.ll */

%{
/* dumbll.ll code block begin */
#include <cmath>
#include <iostream>
#include <boost/lexical_cast.hpp>
#include "dumbctx.hh"
#include "dumbyy.hh"
#include "where.hpp"
/* dumbll.ll code block end */
%}


/* flex options section */
%option reentrant
%option bison-bridge
%option noyywrap
%option header-file="dumbll.hh"
%option outfile="dumbll.cc"


/* definitions section */
DIGIT  [0-9]
WS     [ \t\n]
OP     [-+*/^]


%%

{DIGIT}+ {
    std::cout
        << std::endl
        << WHERE_STRING()
        << std::endl
        << "integer: atof( \"" << yytext << "\" ) == "
        << atof( yytext )
        << std::endl
        ;
    yylval->value_ = atof( yytext );
    return NUM ;
}


{DIGIT}+"."{DIGIT}* {
    std::cout
        << std::endl
        << WHERE_STRING()
        << std::endl
        << "real: atof( \"" << yytext << "\" ) == "
        << atof( yytext )
        << std::endl
        ;
    yylval->value_ = atof( yytext );
    return NUM ;
}


{WS}+ {
    /* eat whitespace */
}


{OP} {
    std::cout
        << std::endl
        << WHERE_STRING()
        << std::endl
        << "operator: int( \'" << yytext[0] << "\' ) == "
        << std::hex << std::showbase
        << unsigned( yytext[0] )
        << std::endl
        ;
    return int( yytext[0] );
}


. {
    std::cerr
        << std::endl
        << "unrecognized character: "
        << yytext
        << std::endl
        ;
    return -1 ;
}

%%

