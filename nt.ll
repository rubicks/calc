/* calc/nt.ll */

%{
/* nt.ll code block begin */
#include<cmath>
#include<iostream>
#include<boost/lexical_cast.hpp>
#include"ntctx.hpp"
#include"nt.yy.hh"
/* nt.ll code block end */
%}


/* flex options section */
%option reentrant
%option bison-bridge
%option noyywrap
%option header-file="nt.ll.hh"
%option outfile="nt.ll.cc"


/* definitions section */
DIGIT  [0-9]
WS     [ \t\n]
OP     [-+*/^]


%%

{DIGIT}+ {
    std::cout
        << "INTEGER (code " << INTEGER << ")"
        << " .. yytext == \"" << yytext << "\""
        << " .. atol( yytext ) == " << atol( yytext )
        << std::endl
        ;
    yylval->u.ival = atol( yytext );
    return INTEGER ;
}

{DIGIT}+"."{DIGIT}* {
    std::cout
        << "REAL (code " << REAL << ")"
        << " .. yytext == \"" << yytext << "\""
        << " .. atof( yytext ) == " << atof( yytext )
        << std::endl
        ;
    yylval->u.dval = atof( yytext );
    return REAL ;
}

{WS}+ {
    /* eat whitespace */
}

{OP} {
    std::cout
        << "OP"
        << " .. *yytext == \'" << *yytext << "\'"
        << " .. unsigned( *yytext ) == "
        << std::dec
        << unsigned( *yytext )
        << " == "
        << std::hex << std::showbase
        << unsigned( *yytext )
        << std::endl
        ;
    yylval->u.cval = *yytext ;
    return *yytext ;
}

. {
    fprintf( stderr, "unrecognized character: %s\n", yytext );
}

%%

